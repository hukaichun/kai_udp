#include "kai_udp.h"


#include <iostream>
using namespace std;

int main()
{
    KAI_UDP::UDP udp("0.0.0.0", 8700);
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