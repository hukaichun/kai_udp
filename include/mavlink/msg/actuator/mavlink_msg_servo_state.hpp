// MESSAGE SERVO_STATE support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief SERVO_STATE message
 *
 * Servo State
 */
struct SERVO_STATE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 2;
    static constexpr size_t LENGTH = 33;
    static constexpr size_t MIN_LENGTH = 33;
    static constexpr uint8_t CRC_EXTRA = 81;
    static constexpr auto NAME = "SERVO_STATE";


    uint8_t ID; /*<  ID */
    uint64_t timestamp; /*<  timestamp */
    float GoalPosition; /*<  GoalPosition */
    float MovingSpeed; /*<  MovingSpeed */
    float PresentPosition; /*<  PresentPosition */
    float PresentSpeed; /*<  PresentSpeed */
    float PresentLoad; /*<  PresentLoad */
    uint32_t PresentTemperature; /*<  PresentTemperature */


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
        ss << "  PresentPosition: " << PresentPosition << std::endl;
        ss << "  PresentSpeed: " << PresentSpeed << std::endl;
        ss << "  PresentLoad: " << PresentLoad << std::endl;
        ss << "  PresentTemperature: " << PresentTemperature << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << GoalPosition;                  // offset: 8
        map << MovingSpeed;                   // offset: 12
        map << PresentPosition;               // offset: 16
        map << PresentSpeed;                  // offset: 20
        map << PresentLoad;                   // offset: 24
        map << PresentTemperature;            // offset: 28
        map << ID;                            // offset: 32
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> GoalPosition;                  // offset: 8
        map >> MovingSpeed;                   // offset: 12
        map >> PresentPosition;               // offset: 16
        map >> PresentSpeed;                  // offset: 20
        map >> PresentLoad;                   // offset: 24
        map >> PresentTemperature;            // offset: 28
        map >> ID;                            // offset: 32
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
