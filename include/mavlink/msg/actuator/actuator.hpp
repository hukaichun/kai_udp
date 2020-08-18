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
constexpr std::array<mavlink_msg_entry_t, 7> MESSAGE_ENTRIES {{ {0, 207, 34, 34, 0, 0, 0}, {1, 92, 8, 8, 0, 0, 0}, {2, 88, 14, 14, 0, 0, 0}, {3, 251, 5, 5, 0, 0, 0}, {5, 168, 17, 17, 0, 0, 0}, {7, 176, 0, 0, 0, 0, 0}, {8, 108, 5, 5, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 0;


// ENUM DEFINITIONS


/** @brief message type */
enum class MESSAGE_TYPE
{
    SERVO_STATE=0, /* servo state | */
    HEARTBEAT=1, /* heartbeat | */
    REGISTER_PARTNER=2, /* heartbeat | */
    SETTING=3, /* setting the servo | */
    COMMAND=5, /* command for servo | */
    ACTION=7, /* action | */
    ACK=8, /* ack | */
};

//! MESSAGE_TYPE ENUM_END
constexpr auto MESSAGE_TYPE_ENUM_END = 9;

/** @brief ACK STATUS TYPE */
enum class ACK_STATUS_TYPE
{
    FAILED=0, /* FAILED | */
    OK=1, /* OK | */
    OUT_OF_RANGE=2, /* out of range | */
    ID_NOT_EXIST=3, /* id not exist | */
};

//! ACK_STATUS_TYPE ENUM_END
constexpr auto ACK_STATUS_TYPE_ENUM_END = 4;


} // namespace actuator
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_servo_state.hpp"
#include "./mavlink_msg_heartbeat.hpp"
#include "./mavlink_msg_register_partner.hpp"
#include "./mavlink_msg_setting.hpp"
#include "./mavlink_msg_command.hpp"
#include "./mavlink_msg_action.hpp"
#include "./mavlink_msg_ack.hpp"

// base include

