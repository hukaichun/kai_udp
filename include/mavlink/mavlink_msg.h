#pragma once
#include "msg/actuator/actuator.hpp"

#include <iostream>
#include <map>
#include <utility>


namespace mavlink
{

    const mavlink_msg_entry_t *mavlink_get_msg_entry(uint32_t msgid);

} // namespace mavlink