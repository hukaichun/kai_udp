#include "kai_udp/kai_udp.h"

namespace KAI
{

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

    const bool &UDP::check_valid()
    {
        return _is_valid;
    }

    ssize_t UDP::send(const void *msg, int msg_len)
    {
        int num = 0, bytes = 0;
        for (const auto &x : _address_book)
        {
            const UDP_PARTNER &partner = x.second; // alias of udp_partner
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

    ssize_t UDP::send_to(const void *msg, int msg_len, const std::string &partner_id)
    {
        if (_address_book.count(partner_id))
        {
            const UDP_PARTNER &partner = _address_book[partner_id];
            return sendto(
                _fd,
                msg, msg_len,
                0,
                (sockaddr *)&(partner.sock), sizeof(partner));
        }else
        {
            printf("Warn!! unknow partner_id \n");
            return 0;
        }
    }

    ssize_t UDP::send_to(const void *msg, int msg_len, const char *ip, uint32_t port)
    {
        char buf[64];
        sprintf(buf, "%s:%d", ip, port);
        std::string partner_id = buf;
        return send_to(msg, msg_len, partner_id);
    }

    int UDP::recv(void *buf, int buf_len, UDP_PARTNER *from)
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
            memcpy(from, &_partner_from, sizeof(_partner_from));
        }

        return nbytes;
    }

} // namespace KAI