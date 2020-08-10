#pragma once

#include "kai_udp/kai_udp.h"
#include "schedule/schedule_base.h"
#include "mavlink/mavlink_msg.h"

#include <ctime>

namespace KAI
{
    
    constexpr const uint16_t PACK_SIZE = 1500;

    class UDP_NODE : public UDP, public Schedule::ScheduleBase
    {

        /**
         *  UDP methods:
         *      bool register_partner(const char* IP, int port)
         *      bool register_partner(const UDP_PARTNER& partner)
         * 
         *  ScheduleBase methods:
         *      int Push(Letter_ptr letter_ptr)
         */
    public:
        UDP_NODE() = delete;
        UDP_NODE(
            int port,
            std::unique_ptr<mavlink::MsgHandlerBase> handler = nullptr);
        ~UDP_NODE();

    private:
        uint8_t send_buf[PACK_SIZE];
        virtual void execute_task(Schedule::Letter_ptr) final;
        void recv_loop();
        std::thread recv_thr_;
        bool should_stop_ = false;
        std::unique_ptr<mavlink::MsgHandlerBase> msg_handler_;
    };
}