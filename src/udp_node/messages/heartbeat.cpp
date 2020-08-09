#include "udp_node/messages/heartbeat.h"

namespace KAI
{
    namespace MSG
    {
        uint16_t Heartbeat::SetMessage_Impl(
            uint8_t *buf)
        {
            static mavlink::mavlink_message_t mavlink_msg;
            static mavlink::MsgMap msg_map(mavlink_msg);
            static mavlink::actuator::msg::HEARTBEAT heartbeat;

            heartbeat.timestamp = clock_t();

            heartbeat.serialize(msg_map);
            mavlink::mavlink_finalize_message(&mavlink_msg, 1, 1,
                                              heartbeat.MIN_LENGTH,
                                              heartbeat.LENGTH,
                                              heartbeat.CRC_EXTRA);

            return mavlink::mavlink_msg_to_send_buffer(buf, &mavlink_msg);
        }
    } // namespace MSG
} // namespace KAI