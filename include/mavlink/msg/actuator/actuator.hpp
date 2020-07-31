/** @file
 *	@brief MAVLink comm protocol generated from actuator.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace actuator {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (trought @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 4> MESSAGE_ENTRIES {{ {0, 92, 8, 8, 0, 0, 0}, {1, 251, 5, 5, 0, 0, 0}, {2, 81, 33, 33, 0, 0, 0}, {3, 168, 17, 17, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 0;


// ENUM DEFINITIONS


/** @brief message type */
enum class MESSAGE_TYPE
{
    HEARTBEAT=0, /* heartbeat | */
    SETTING=1, /* setting the servo | */
    SERVO_STATE=2, /* servo state | */
    COMMAND=3, /* command for servo | */
};

//! MESSAGE_TYPE ENUM_END
constexpr auto MESSAGE_TYPE_ENUM_END = 4;


} // namespace actuator
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_heartbeat.hpp"
#include "./mavlink_msg_setting.hpp"
#include "./mavlink_msg_servo_state.hpp"
#include "./mavlink_msg_command.hpp"

// base include

