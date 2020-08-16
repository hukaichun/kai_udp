#pragma once

#include "../socket_helper.h"
#include <map>
#include <cstdint>
#include <mutex>

namespace KAI
{
    class AddressBook : public std::map<std::string, UDP_PARTNER>
    {
    public:

        bool add(const char *IP, int port);
        bool add(const UDP_PARTNER &);
        bool update(const UDP_PARTNER &);

    private:
        bool check_add_partner(const UDP_PARTNER &);
        std::mutex lock;
    };

} // namespace KAI
