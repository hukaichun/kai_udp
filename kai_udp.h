#pragma once

// memset
#include <cstring>
#include <set>

// close()
#include <unistd.h>

// socket header
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace KAI_UDP
{

    struct sockaddr_compare
    {
        bool operator()(const sockaddr_in &, const sockaddr_in &);
    };

    sockaddr_in get_sockaddr(const char *IP, int port);

    class UDP
    {
    public:
        UDP() = delete;
        UDP(const char *IP, int port);
        virtual ~UDP();
        bool check_valid();

        int register_partner(const char *IP, int port);

        ssize_t send(const void *msg, int msg_len);
        int recv(void *buf, int buf_len);

    protected:
        std::set<sockaddr_in, sockaddr_compare> _partners;
        sockaddr_in _partner_from;
        socklen_t _partnerlen;

    private:
        int _fd;
        sockaddr_in _info;
        bool _is_valid;
    };

} // namespace KAI_UDP