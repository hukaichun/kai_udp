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
constexpr std::array<mavlink_msg_entry_t, 9> MESSAGE_ENTRIES {{ {0, 81, 33, 33, 0, 0, 0}, {1, 92, 8, 8, 0, 0, 0}, {2, 151, 20, 20, 0, 0, 0}, {3, 251, 5, 5, 0, 0, 0}, {4, 137, 2, 2, 0, 0, 0}, {5, 168, 17, 17, 0, 0, 0}, {6, 44, 2, 2, 0, 0, 0}, {7, 176, 0, 0, 0, 0, 0}, {8, 227, 1, 1, 0, 0, 0} }};

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
    SETTING_ACK=4, /* setting the servo ack | */
    COMMAND=5, /* command for servo | */
    COMMAND_ACK=6, /* command for servo ack | */
    ACTION=7, /* action | */
    ACTION_ACK=8, /* action ack | */
};

//! MESSAGE_TYPE ENUM_END
constexpr auto MESSAGE_TYPE_ENUM_END = 9;

/** @brief ACK STATUS TYPE */
enum class ACK_STATUS_TYPE
{
    OK=0, /* OK | */
    ID_NOT_EXIST=1, /* id not exist | */
    OUT_OF_RANGE=2, /* out of range | */
};

//! ACK_STATUS_TYPE ENUM_END
constexpr auto ACK_STATUS_TYPE_ENUM_END = 3;


} // namespace actuator
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_servo_state.hpp"
#include "./mavlink_msg_heartbeat.hpp"
#include "./mavlink_msg_register_partner.hpp"
#include "./mavlink_msg_setting.hpp"
#include "./mavlink_msg_setting_ack.hpp"
#include "./mavlink_msg_command.hpp"
#include "./mavlink_msg_command_ack.hpp"
#include "./mavlink_msg_action.hpp"
#include "./mavlink_msg_action_ack.hpp"

// base include

