#include "udp_node/udp_node.h"

#include <iostream>
using namespace std;

namespace KAI
{
    UDP_NODE::UDP_NODE(int port) : UDP("0.0.0.0", port),
                                   Schedule::ScheduleBase()
    {
        recv_thr_ = std::thread(&UDP_NODE::recv_loop, this);
    }

    UDP_NODE::~UDP_NODE()
    {
        cout << "exit UDP node" << endl;
        should_stop_ = true;
        if (recv_thr_.joinable())
            recv_thr_.join();
        cout << "exit UDP node ... done" << endl;
    }

    void UDP_NODE::execute_task(Schedule::Letter_ptr letter_ptr)
    {
        auto bytes = letter_ptr->SetMessage(send_buf);
        send(send_buf, bytes);
    }

    void UDP_NODE::recv_loop()
    {
        uint8_t recv_buf[PACK_SIZE];
        mavlink::mavlink_message_t mavlink_msg;
        mavlink::mavlink_status_t status;

        bool done = false;

        while (!should_stop_)
        {
            uint16_t recv_bytes = this->recv(recv_buf, PACK_SIZE);
            done = false;
            for (uint16_t i = 0; i < recv_bytes; ++i)
            {
                done = mavlink::mavlink_parse_char(
                    mavlink::MAVLINK_COMM_0, recv_buf[i], &mavlink_msg, &status);
            }
            if (done)
            {
                cout << "recv data, msgid: " << mavlink_msg.msgid << endl;

                mavlink::actuator::MESSAGE_TYPE msg_type = static_cast<mavlink::actuator::MESSAGE_TYPE>(mavlink_msg.msgid);



                switch (msg_type)
                {
                case mavlink::actuator::MESSAGE_TYPE::HEARTBEAT:
                    if (register_partner(this->_partner_from))
                    {
                        cout << "add partner : " << str(_partner_from.sock) << endl;
                    }else
                    {
                        cout << "partner exist" << endl;
                    }
                    break;

                default:
                    break;
                }
            }
        }
    }
} // namespace KAI