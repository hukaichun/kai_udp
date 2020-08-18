// MESSAGE ACK support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief ACK message
 *
 * Action ack
 */
struct ACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 8;
    static constexpr size_t LENGTH = 5;
    static constexpr size_t MIN_LENGTH = 5;
    static constexpr uint8_t CRC_EXTRA = 108;
    static constexpr auto NAME = "ACK";


    uint32_t MSG_TYPE; /*<  message type */
    uint8_t STATUS; /*<  Setting status */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  MSG_TYPE: " << MSG_TYPE << std::endl;
        ss << "  STATUS: " << +STATUS << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << MSG_TYPE;                      // offset: 0
        map << STATUS;                        // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> MSG_TYPE;                      // offset: 0
        map >> STATUS;                        // offset: 4
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
