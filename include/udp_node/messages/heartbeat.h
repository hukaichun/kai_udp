#pragma once

#include "mavlink/mavlink_msg.h"
#include "../schedule/schedule_base.h"

#include <ctime>

namespace KAI
{
    namespace MSG
    {
        class Heartbeat : public Schedule::Letter_CRTP<Heartbeat>
        {
        public:
            Heartbeat() = default;
            uint16_t SetMessage_Impl(uint8_t *buf);
        };
    } // namespace MSG
} // namespace KAI