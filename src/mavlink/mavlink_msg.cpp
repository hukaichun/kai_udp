#include "mavlink/mavlink_msg.h"

namespace mavlink
{

    static inline std::map<uint32_t, const mavlink_msg_entry_t *> initialize_msg_entry_map()
    {
        std::map<uint32_t, const mavlink_msg_entry_t *> tmp;
        for (const mavlink_msg_entry_t &x : actuator::MESSAGE_ENTRIES)
        {
            tmp[x.msgid] = &x;
        }
        return tmp;
    }


    const mavlink_msg_entry_t *mavlink_get_msg_entry(uint32_t msgid)
    {
        static std::map<uint32_t, const mavlink_msg_entry_t *> msg_entry_map = initialize_msg_entry_map();
        if (!msg_entry_map.count(msgid))
        {
            std::cout << "msgid " << msgid <<  " not found" << std::endl;
            return nullptr;
        }
        return msg_entry_map[msgid];
    }



} // namespace mavlink