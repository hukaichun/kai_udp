#include "kai_udp.h"

#include <cstdio>

int main()
{
    KAI_UDP::UDP udp("0.0.0.0", 8701);
    
    int partner_num = 0;
    partner_num = udp.register_partner("127.0.0.1", 8700);
    printf("partner num %d\n", partner_num);
 


    char message[] = "Hi";
    int nbytes = udp.send(message, sizeof(message));


    char message_exit[] = "q";
    nbytes = udp.send(message_exit, sizeof(message_exit));

    sleep(3);

    return 0;
}