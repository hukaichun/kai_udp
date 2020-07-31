// MESSAGE COMMAND support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief COMMAND message
 *
 * Servo State
 */
struct COMMAND : mavlink::Message {
    static constexpr msgid_t MSG_ID = 3;
    static constexpr size_t LENGTH = 17;
    static constexpr size_t MIN_LENGTH = 17;
    static constexpr uint8_t CRC_EXTRA = 168;
    static constexpr auto NAME = "COMMAND";


    uint8_t ID; /*<  ID */
    uint64_t timestamp; /*<  timestamp */
    float GoalPosition; /*<  GoalPosition */
    float MovingSpeed; /*<  MovingSpeed */


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
        ss << "  timestamp: " << timestamp << std::endl;
        ss << "  GoalPosition: " << GoalPosition << std::endl;
        ss << "  MovingSpeed: " << MovingSpeed << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << GoalPosition;                  // offset: 8
        map << MovingSpeed;                   // offset: 12
        map << ID;                            // offset: 16
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> GoalPosition;                  // offset: 8
        map >> MovingSpeed;                   // offset: 12
        map >> ID;                            // offset: 16
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
