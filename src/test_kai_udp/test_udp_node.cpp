#include "udp_node/udp_node.h"

#include <thread>

#include <iostream>
using namespace std;

int main()
{
    KAI::UDP_NODE node(9487);

    KAI::UDP udp_client("0,0,0,0", 9488);

    if (udp_client.register_partner("127.0.0.1", 9487))
    {
        cout << "register the udp_node 9487" << endl;
    }
    else
    {
        cout << "register error" << endl;
        return -1;
    }

    this_thread::sleep_for(chrono::seconds(1));

    mavlink::actuator::msg::HEARTBEAT heartbeat;
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap msg_map(msg);

    uint8_t buf[1500];
    heartbeat.serialize(msg_map);
    mavlink::mavlink_finalize_message(
        &msg, 1, 1,
        heartbeat.MIN_LENGTH,
        heartbeat.LENGTH,
        heartbeat.CRC_EXTRA);
    int msg_len = mavlink::mavlink_msg_to_send_buffer(buf, &msg);
    udp_client.send(buf, msg_len);

    this_thread::sleep_for(chrono::seconds(1));

    udp_client.send(buf, msg_len);

    this_thread::sleep_for(chrono::seconds(1));

    udp_client.send(buf, msg_len);

    node.~UDP_NODE();

    this_thread::sleep_for(chrono::seconds(2));


    return 0;
}