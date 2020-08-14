#include "udp_node/udp_node.h"

#include <utility>

#include <iostream>
using namespace std;

namespace KAI
{
    UDP_NODE::UDP_NODE(int port) :
        UDP("0.0.0.0", port),
        Schedule::ScheduleBase() {}


    void UDP_NODE::execute_task(Schedule::Letter_ptr letter_ptr)
    {
        std::string* addr;
        auto bytes = letter_ptr->SetMessage(send_buf, addr);
        send(send_buf, bytes);
    }

} // namespace KAI