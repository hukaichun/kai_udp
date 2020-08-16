/** @file
 *  @brief MAVLink comm protocol generated from actuator.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_ACTUATOR_H
#define MAVLINK_ACTUATOR_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_ACTUATOR.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 81, 33, 33, 0, 0, 0}, {1, 92, 8, 8, 0, 0, 0}, {2, 151, 20, 20, 0, 0, 0}, {3, 251, 5, 5, 0, 0, 0}, {4, 137, 2, 2, 0, 0, 0}, {5, 168, 17, 17, 0, 0, 0}, {6, 44, 2, 2, 0, 0, 0}, {7, 176, 0, 0, 0, 0, 0}, {8, 227, 1, 1, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_ACTUATOR

// ENUM DEFINITIONS


/** @brief message type */
#ifndef HAVE_ENUM_MESSAGE_TYPE
#define HAVE_ENUM_MESSAGE_TYPE
typedef enum MESSAGE_TYPE
{
   MESSAGE_TYPE_SERVO_STATE=0, /* servo state | */
   MESSAGE_TYPE_HEARTBEAT=1, /* heartbeat | */
   MESSAGE_TYPE_REGISTER_PARTNER=2, /* heartbeat | */
   MESSAGE_TYPE_SETTING=3, /* setting the servo | */
   MESSAGE_TYPE_SETTING_ACK=4, /* setting the servo ack | */
   MESSAGE_TYPE_COMMAND=5, /* command for servo | */
   MESSAGE_TYPE_COMMAND_ACK=6, /* command for servo ack | */
   MESSAGE_TYPE_ACTION=7, /* action | */
   MESSAGE_TYPE_ACTION_ACK=8, /* action ack | */
   MESSAGE_TYPE_ENUM_END=9, /*  | */
} MESSAGE_TYPE;
#endif

/** @brief ACK STATUS TYPE */
#ifndef HAVE_ENUM_ACK_STATUS_TYPE
#define HAVE_ENUM_ACK_STATUS_TYPE
typedef enum ACK_STATUS_TYPE
{
   ACK_STATUS_TYPE_OK=0, /* OK | */
   ACK_STATUS_TYPE_ID_NOT_EXIST=1, /* id not exist | */
   ACK_STATUS_TYPE_OUT_OF_RANGE=2, /* out of range | */
   ACK_STATUS_TYPE_ENUM_END=3, /*  | */
} ACK_STATUS_TYPE;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 0
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_servo_state.h"
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_register_partner.h"
#include "./mavlink_msg_setting.h"
#include "./mavlink_msg_setting_ack.h"
#include "./mavlink_msg_command.h"
#include "./mavlink_msg_command_ack.h"
#include "./mavlink_msg_action.h"
#include "./mavlink_msg_action_ack.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_SERVO_STATE, MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_REGISTER_PARTNER, MAVLINK_MESSAGE_INFO_SETTING, MAVLINK_MESSAGE_INFO_SETTING_ACK, MAVLINK_MESSAGE_INFO_COMMAND, MAVLINK_MESSAGE_INFO_COMMAND_ACK, MAVLINK_MESSAGE_INFO_ACTION, MAVLINK_MESSAGE_INFO_ACTION_ACK}
# define MAVLINK_MESSAGE_NAMES {{ "ACTION", 7 }, { "ACTION_ACK", 8 }, { "COMMAND", 5 }, { "COMMAND_ACK", 6 }, { "HEARTBEAT", 1 }, { "REGISTER_PARTNER", 2 }, { "SERVO_STATE", 0 }, { "SETTING", 3 }, { "SETTING_ACK", 4 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_ACTUATOR_H
