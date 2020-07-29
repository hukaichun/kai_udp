#include "kai_udp.h"


namespace KAI
{

    bool sockaddr_compare::operator()(
        const sockaddr_in &A, const sockaddr_in &B)
    {
        if (A.sin_addr.s_addr < B.sin_addr.s_addr)
        {
            return true;
        }
        else if (A.sin_addr.s_addr > B.sin_addr.s_addr)
        {
            return false;
        }else
        {
            if(A.sin_port < B.sin_port)
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
        _partners.insert(get_sockaddr(IP, port));
        return _partners.size();
    }

    ssize_t UDP::send(const void *msg, int msg_len)
    {
        int num = 0, bytes = 0;
        for (const auto &partner : _partners)
        {
            bytes = sendto(
                        _fd,
                        msg, msg_len,
                        0,
                        (sockaddr *)&partner, sizeof(partner)
                        );

            if (bytes > 0)
                num += 1;
        }

        return num;
    }

    int UDP::recv(void *buf, int buf_len)
    {
        static socklen_t partnerlen = sizeof(_partner_from);

        return recvfrom(
            _fd,
            buf, buf_len,
            0,
            (sockaddr *)&_partner_from, &partnerlen);
    }

} // namespace KAI