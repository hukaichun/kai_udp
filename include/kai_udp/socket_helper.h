#pragma once

#include <string>
#include <cstring>

// socket header
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SOCKET_HELPER static inline

namespace KAI
{
    SOCKET_HELPER sockaddr_in get_sockaddr(const char *IP, int port)
    {
        sockaddr_in info;
        info.sin_family = AF_INET;
        info.sin_port = htons(port);
        inet_pton(info.sin_family, IP, &info.sin_addr);
        memset(&info.sin_zero, 0, sizeof(info.sin_zero));
        return info;
    }

    SOCKET_HELPER std::string str(const char *IP, int port)
    {
        char buf[128];
        memset(buf, 0, 128);
        sprintf(buf, "%s:%d", IP, port);
        return std::string(buf);
    }

    SOCKET_HELPER std::string str(const sockaddr_in &sock)
    {
        char ip[INET_ADDRSTRLEN];
        uint16_t port = 0;

        memset(ip, 0, INET_ADDRSTRLEN);

        inet_ntop(AF_INET, &(sock.sin_addr), ip, INET_ADDRSTRLEN);
        port = ntohs(sock.sin_port);

        return str(ip, port);
    }

    /**
     * member: clock_t timestemp
     * member: sockaddr_in sock
     */
    struct UDP_PARTNER
    {
        clock_t timestemp;
        sockaddr_in sock;
    };

    SOCKET_HELPER UDP_PARTNER get_partner()
    {
        UDP_PARTNER tmp;
        tmp.timestemp = clock();
        return tmp;
    }

} // namespace KAI

#undef SOCKET_HELPER