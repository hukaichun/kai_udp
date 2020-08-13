// MESSAGE ACTION support class

#pragma once

namespace mavlink {
namespace actuator {
namespace msg {

/**
 * @brief ACTION message
 *
 * Action
 */
struct ACTION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 4;
    static constexpr size_t LENGTH = 0;
    static constexpr size_t MIN_LENGTH = 0;
    static constexpr uint8_t CRC_EXTRA = 176;
    static constexpr auto NAME = "ACTION";





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


        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);


    }

    inline void deserialize(mavlink::MsgMap &map) override
    {

    }
};

} // namespace msg
} // namespace actuator
} // namespace mavlink
