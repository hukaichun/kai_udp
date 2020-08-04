#include "kai_udp/kai_udp.h"

#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[])
{

    if(argc<5)
    {
        printf("usage: ./server <IP> <port> <Remote IP> <Remote port> \n");
        return 0;
    }

    KAI::UDP udp(argv[1], atoi(argv[2]));
    
    int partner_num = 0;
    partner_num = udp.register_partner(argv[3], atoi(argv[4]));
    printf("partner num %d\n", partner_num);
 


    char message[] = "Hi";
    int nbytes = udp.send(message, sizeof(message));


    char message_exit[] = "q";
    nbytes = udp.send(message_exit, sizeof(message_exit));

    sleep(3);

    return 0;
}