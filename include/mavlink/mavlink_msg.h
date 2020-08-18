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
        MsgHandlerBase()=default;

        inline void print() const
        {
            printf(
                "SYS:%3d COMP:%3d LEN:%3d MSGID:%3d\n",
                +mavlink_msg_.sysid, +mavlink_msg_.compid, +mavlink_msg_.len, +mavlink_msg_.msgid);
        }

        inline bool parse_msg(
            uint8_t *buf, int buf_len,
            mavlink_channel_t chen = MAVLINK_COMM_1)
        {
            uint8_t done = 0;
            for (uint16_t i = 0; i < buf_len; ++i)
            {
                done = mavlink_frame_char(
                    chen, buf[i],
                    &mavlink_msg_, &status_);

                if (done)
                    break;
            }

            switch (done)
            {
            case mavlink::mavlink_framing_t::MAVLINK_FRAMING_INCOMPLETE:
                printf("MAVLINK_FRAMING_INCOMPLETE\n");
                break;

            case mavlink::mavlink_framing_t::MAVLINK_FRAMING_OK:
                return true;
                break;

            case mavlink::mavlink_framing_t::MAVLINK_FRAMING_BAD_CRC:
                printf("BAD_CRC\n");
                break;

            case mavlink::mavlink_framing_t::MAVLINK_FRAMING_BAD_SIGNATURE:
                printf("BAD SIGNATURE\n");
                break;

            default:
                printf("Unknown Msg\n");
                break;
            }

            return false;
        }

        inline uint16_t finalize_msg(
            uint8_t system_id,
            uint8_t component_id,
            uint8_t min_length,
            uint8_t length,
            uint8_t crc_extra)
        {
            return mavlink_finalize_message(&mavlink_msg_, system_id, component_id, min_length, length, crc_extra);
        }

        inline uint16_t msg_2_send_buffer(uint8_t *buf)
        {
            return mavlink::mavlink_msg_to_send_buffer(buf, &mavlink_msg_);
        }

        mavlink_message_t mavlink_msg_;
        mavlink_status_t status_;
    };

} // namespace mavlink