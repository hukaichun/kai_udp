#include "udp_node/kai_udp.h"

namespace KAI
{

    bool sockaddr_compare::operator() (
        const UDP_PARTNER &A, const UDP_PARTNER &B) const
    {
        if (A.sock.sin_addr.s_addr < B.sock.sin_addr.s_addr)
        {
            return true;
        }
        else if (A.sock.sin_addr.s_addr > B.sock.sin_addr.s_addr)
        {
            return false;
        }
        else
        {
            if (A.sock.sin_port < B.sock.sin_port)
                return true;
            else
                return false;
        }
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



    ssize_t UDP::send(const void *msg, int msg_len)
    {
        int num = 0, bytes = 0;
        for (const auto &x : _address_book)
        {
            const UDP_PARTNER& partner = x.second; // alias of udp_partner  
            bytes = sendto(
                _fd,
                msg, msg_len,
                0,
                (sockaddr *)&(partner.sock), sizeof(partner));

            if (bytes > 0)
                num += 1;
        }

        return num;
    }

    int UDP::recv(void *buf, int buf_len, sockaddr_in *from)
    {
        static socklen_t partnerlen = sizeof(_partner_from.sock);
        static int nbytes = 0;

        nbytes = recvfrom(
            _fd,
            buf, buf_len,
            0,
            (sockaddr *)&(_partner_from.sock), &partnerlen);
        _partner_from.timestemp = clock();

        if (from)
        {
            memcpy(from, &_partner_from, partnerlen);
        }

        return nbytes;
    }

} // namespace KAI