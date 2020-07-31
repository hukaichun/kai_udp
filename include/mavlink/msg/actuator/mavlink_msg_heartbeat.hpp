// MESSAGE HEARTBEAT support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief HEARTBEAT message
 *
 * Servo State
 */
struct HEARTBEAT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 0;
    static constexpr size_t LENGTH = 8;
    static constexpr size_t MIN_LENGTH = 8;
    static constexpr uint8_t CRC_EXTRA = 92;
    static constexpr auto NAME = "HEARTBEAT";


    uint64_t timestamp; /*<  timestamp */


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
        ss << "  timestamp: " << timestamp << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
