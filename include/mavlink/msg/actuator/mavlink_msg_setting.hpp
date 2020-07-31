// MESSAGE SETTING support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief SETTING message
 *
 * Setting Servo
 */
struct SETTING : mavlink::Message {
    static constexpr msgid_t MSG_ID = 1;
    static constexpr size_t LENGTH = 5;
    static constexpr size_t MIN_LENGTH = 5;
    static constexpr uint8_t CRC_EXTRA = 251;
    static constexpr auto NAME = "SETTING";


    uint8_t ID; /*<  ID */
    int16_t DIR; /*<   Rotation Direction  */
    uint16_t ZERO; /*<   Zero Position  */


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
        ss << "  DIR: " << DIR << std::endl;
        ss << "  ZERO: " << ZERO << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << DIR;                           // offset: 0
        map << ZERO;                          // offset: 2
        map << ID;                            // offset: 4
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> DIR;                           // offset: 0
        map >> ZERO;                          // offset: 2
        map >> ID;                            // offset: 4
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
