// MESSAGE COMMAND_ACK support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief COMMAND_ACK message
 *
 * Command ack
 */
struct COMMAND_ACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 6;
    static constexpr size_t LENGTH = 2;
    static constexpr size_t MIN_LENGTH = 2;
    static constexpr uint8_t CRC_EXTRA = 44;
    static constexpr auto NAME = "COMMAND_ACK";


    uint8_t ID; /*<  ID */
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
        ss << "  ID: " << +ID << std::endl;
        ss << "  STATUS: " << +STATUS << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ID;                            // offset: 0
        map << STATUS;                        // offset: 1
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ID;                            // offset: 0
        map >> STATUS;                        // offset: 1
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
