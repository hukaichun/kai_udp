#pragma once
#include "msg/actuator/actuator.hpp"

#include <cstdio>
#include <map>
#include <utility>

namespace mavlink
{

    const mavlink_msg_entry_t *mavlink_get_msg_entry(uint32_t msgid);

    MAVLINK_HELPER uint8_t mavlink_parse_msg_0(
        uint8_t *buf, int buf_len,
        mavlink_message_t *msg, mavlink_status_t *status)
    {
        uint8_t done = 0;
        for (int i = 0; i < buf_len; ++i)
        {
            done = mavlink_parse_char(
                MAVLINK_COMM_0, buf[i],
                msg, status);

            if (done)
                break;
        }
        return done;
    }

    class MsgHandlerBase
    {
    public:

        inline uint8_t parse_msg(
            uint8_t *buf, int buf_len,
            mavlink_channel_t chen =  MAVLINK_COMM_0
        )
        {
            uint8_t done = 0;
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                done = mavlink_parse_char(
                    chen, buf[i],
                    &mavlink_msg_, &status_);

                if (done)
                    break;
            }
            return done;
        }

    protected:
        mavlink_message_t mavlink_msg_;
        mavlink_status_t status_;
    };

} // namespace mavlink