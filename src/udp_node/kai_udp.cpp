#include "udp_node/kai_udp.h"


namespace KAI
{

    bool sockaddr_compare::operator()(
        const  UDP_PARTNER &A, const  UDP_PARTNER &B)
    {
        if (A.sock.sin_addr.s_addr < B.sock.sin_addr.s_addr)
        {
            return true;
        }
        else if (A.sock.sin_addr.s_addr > B.sock.sin_addr.s_addr)
        {
            return false;
        }else
        {
            if(A.sock.sin_port < B.sock.sin_port)
                return true;
            else 
                return false;
        }
    }

    sockaddr_in get_sockaddr(
        const char *IP,
        int port)
    {
        sockaddr_in info;
        info.sin_family = AF_INET;
        info.sin_port = htons(port);
        inet_pton(info.sin_family, IP, &info.sin_addr);
        memset(&info.sin_zero, 0, sizeof(info.sin_zero));
        return info;
    }

    UDP::UDP(const char *IP, int port) : _fd(socket(AF_INET, SOCK_DGRAM, 0)),
                                         _info(get_sockaddr(IP, port)),
                                         _is_valid(false)
    {
        int result = bind(_fd, (sockaddr *)&_info, sizeof(_info));
        _is_valid = (result == -1) ? false : true;
    }

    UDP::~UDP()
    {
        shutdown(_fd, 2);
        close(_fd);
    }

    bool UDP::check_valid()
    {
        return _is_valid;
    }

    int UDP::register_partner(const char *IP, int port)
    {
        UDP_PARTNER partner;
        partner.timestemp = 0;
        partner.sock = get_sockaddr(IP, port);
        

        _partners.insert(partner);
        return _partners.size();
    }

    ssize_t UDP::send(const void *msg, int msg_len)
    {
        int num = 0, bytes = 0;
        for (const UDP_PARTNER &partner : _partners)
        {
            bytes = sendto(
                        _fd,
                        msg, msg_len,
                        0,
                        (sockaddr *)&(partner.sock), sizeof(partner)
                        );

            if (bytes > 0)
                num += 1;
        }

        return num;
    }

    int UDP::recv(void *buf, int buf_len, sockaddr_in* from)
    {
        static socklen_t partnerlen = sizeof(_partner_from);
        static int nbytes = 0;


        nbytes = recvfrom(
            _fd,
            buf, buf_len,
            0,
            (sockaddr *)&_partner_from, &partnerlen);

        if(from)
        {
            memcpy(from, &_partner_from, partnerlen);
        }

        return nbytes;
    }

} // namespace KAI