#include "udp_node/udp_node.h"

#include <utility>

#include <iostream>
using namespace std;

namespace KAI
{
    UDP_NODE::UDP_NODE(int port,
        std::unique_ptr<mavlink::MsgHandlerBase> handler) :
        UDP("0.0.0.0", port),
        Schedule::ScheduleBase(),
        msg_handler_(std::move(handler))
    {
        recv_thr_ = std::thread(&UDP_NODE::recv_loop, this);
        if (!handler)
        {
            msg_handler_.reset(new mavlink::MsgHandlerBase);
        }
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

        while (!should_stop_)
        {
            ssize_t recv_bytes = this->recv(recv_buf, PACK_SIZE);
            msg_handler_->Handle_Msg(recv_buf, recv_bytes);
        }
    }
} // namespace KAI