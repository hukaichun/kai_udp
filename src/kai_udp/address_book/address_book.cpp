#include "kai_udp/address_book/address_book.h"

namespace KAI
{

    bool AddressBook::add(const char *IP, int port)
    {
        auto name = str(IP, port);
        if (this->count(name) == 0)
        {
            UDP_PARTNER partner = get_partner();
            partner.sock = get_sockaddr(IP, port);
            (*this)[name] = partner;
            return true;
        }else
        {
            return false;
        }
    }

    bool AddressBook::add(const UDP_PARTNER &partner)
    {
        auto name = str(partner.sock);
        if (this->count(name) == 0)
        {
            (*this)[name] = partner;
            return true;
        }
        else
        {
            (*this)[name].timestemp = partner.timestemp;
            return false;
        }
    }

    bool AddressBook::update(const UDP_PARTNER &partner)
    {
        auto name = str(partner.sock);
        if(this->count(name))
        {
            (*this)[name].timestemp = partner.timestemp;
            return true;
        }
        return false;
    }
} // namespace KAI
