#pragma once

#include "kai_udp.h"
#include "schedule/schedule_base.h"
#include "mavlink/mavlink_msg.h"

#include <ctime>

namespace KAI
{

    constexpr const uint16_t PACK_SIZE = 1500;

    class UDP_NODE: public UDP, public Schedule::ScheduleBase
    {
    public:
        UDP_NODE() = delete;
        UDP_NODE(int port);
        ~UDP_NODE();

    private:
        uint8_t send_buf[PACK_SIZE];
        virtual void execute_task(Schedule::Letter_ptr) override;

        void recv_loop();
        std::thread recv_thr_;
        bool should_stop_ = false;


    };
}