#pragma once

#include <string>
#include <cstdio>
#include <ctime>
#include <map>

// memset
#include <cstring>

// close()
#include <unistd.h>



#include "socket_helper.h"
#include "address_book/address_book.h"


namespace KAI
{


    class UDP
    {
    public:

        UDP() = delete;
        UDP(const char *IP, int port);
        virtual ~UDP();
        const bool& check_valid();

        inline bool register_partner(const char* IP, int port)
        {
            return _address_book.add(IP,port);
        }

        inline bool register_partner(const UDP_PARTNER& partner)
        {
            return _address_book.add(partner);
        }


        ssize_t send(const void *msg, int msg_len);
        ssize_t send_to(const void *msg, int msg_len, const std::string& partner_id);
        int recv(void *buf,
                 int buf_len,
                 UDP_PARTNER *from = nullptr);

    protected:
        AddressBook _address_book;
        UDP_PARTNER _partner_from;
        socklen_t _partnerlen;

        int _fd;
        bool _is_valid;

    private:
        sockaddr_in _info;


    };
   

} // namespace KAI