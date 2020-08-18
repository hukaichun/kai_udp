// MESSAGE REGISTER_PARTNER support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief REGISTER_PARTNER message
 *
 * REGISTER PARTNER
 */
struct REGISTER_PARTNER : mavlink::Message {
    static constexpr msgid_t MSG_ID = 2;
    static constexpr size_t LENGTH = 14;
    static constexpr size_t MIN_LENGTH = 14;
    static constexpr uint8_t CRC_EXTRA = 88;
    static constexpr auto NAME = "REGISTER_PARTNER";


    uint64_t timestamp; /*<  timestamp */
    uint8_t ip_0; /*<  ip */
    uint8_t ip_1; /*<  ip */
    uint8_t ip_2; /*<  ip */
    uint8_t ip_3; /*<  ip */
    uint16_t port; /*<  port */


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
        ss << "  ip_0: " << +ip_0 << std::endl;
        ss << "  ip_1: " << +ip_1 << std::endl;
        ss << "  ip_2: " << +ip_2 << std::endl;
        ss << "  ip_3: " << +ip_3 << std::endl;
        ss << "  port: " << port << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << port;                          // offset: 8
        map << ip_0;                          // offset: 10
        map << ip_1;                          // offset: 11
        map << ip_2;                          // offset: 12
        map << ip_3;                          // offset: 13
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> port;                          // offset: 8
        map >> ip_0;                          // offset: 10
        map >> ip_1;                          // offset: 11
        map >> ip_2;                          // offset: 12
        map >> ip_3;                          // offset: 13
    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
