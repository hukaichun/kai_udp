#include "kai_udp/kai_udp.h"
#include <cstdlib>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    if(argc<3)
    {
        printf("usage: ./client <IP> <port> \n");
        return 0;
    }else{

    }

    KAI::UDP udp(argv[1], atoi(argv[2]));
    char inputBuffer[256];
    while (true)
    {
        int nbytes = udp.recv(inputBuffer, 256);
        if (nbytes < 1)
        {
            printf("could not read datagram");
            continue;
        }
        printf("Get:%s\n", inputBuffer);
        if (inputBuffer[0] == 'q')
        {
            break;
        }
    }
}