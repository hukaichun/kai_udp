#pragma once

#include <string>
#include <cstdio>

// memset
#include <cstring>
#include <set>

// close()
#include <unistd.h>

// socket header
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace KAI
{

    struct UDP_PARTNER
    {
        clock_t timestemp;
        sockaddr_in sock;
    };

    struct sockaddr_compare
    {
        bool operator()(const UDP_PARTNER &, const UDP_PARTNER &);
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
        int recv(void *buf, int buf_len, sockaddr_in *from = nullptr);

    protected:
        std::set<UDP_PARTNER, sockaddr_compare> _partners;
        sockaddr_in _partner_from;
        socklen_t _partnerlen;

    private:
        int _fd;
        sockaddr_in _info;
        bool _is_valid;
    };

    /**
     * Get sockaddr ip port
     * 
     * @param sock 
     */
    static inline std::string str(const sockaddr_in &sock)
    {
        char buf[128];
        char ip[INET_ADDRSTRLEN];
        uint16_t port = 0;

        memset(buf, 0, 128);
        memset(ip, 0, INET_ADDRSTRLEN);

        inet_ntop(AF_INET, &(sock.sin_addr), ip, INET_ADDRSTRLEN);
        port = ntohs(sock.sin_port);

        sprintf(buf, "%s:%d", ip, port);
        return std::string(buf);
    }

} // namespace KAI