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
        int recv(void *buf,
                 int buf_len,
                 sockaddr_in *from = nullptr);

    protected:
        AddressBook _address_book;
        UDP_PARTNER _partner_from;
        socklen_t _partnerlen;

    private:
        int _fd;
        sockaddr_in _info;
        bool _is_valid;
    };
   

} // namespace KAI