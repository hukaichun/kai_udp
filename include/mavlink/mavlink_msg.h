#pragma once
#include "msg/actuator/actuator.hpp"

#include <iostream>
#include <map>
#include <utility>

namespace mavlink
{

    const mavlink_msg_entry_t *mavlink_get_msg_entry(uint32_t msgid);

    MAVLINK_HELPER 
    uint8_t mavlink_parse_msg_0(
        uint8_t *buf, uint16_t buf_len,
        mavlink_message_t *msg, mavlink_status_t *status)
    {
        uint8_t done = 0;
        for (uint16_t i = 0; i < buf_len; ++i)
        {
            done = mavlink_parse_char(
                MAVLINK_COMM_0, buf[i],
                msg, status);

            if (done)
                break;
        }
        return done;
    }

} // namespace mavlink