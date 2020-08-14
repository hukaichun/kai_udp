// MESSAGE ACTION_ACK support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief ACTION_ACK message
 *
 * Action ack
 */
struct ACTION_ACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 8;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 227;
    static constexpr auto NAME = "ACTION_ACK";


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
        ss << "  STATUS: " << +STATUS << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << STATUS;                        // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> STATUS;                        // offset: 0
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
