#pragma once
// MESSAGE COMMAND PACKING

#define MAVLINK_MSG_ID_COMMAND 5


typedef struct __mavlink_command_t {
 uint64_t timestamp; /*<  timestamp*/
 float GoalPosition; /*<  GoalPosition*/
 float MovingSpeed; /*<  MovingSpeed*/
 uint8_t ID; /*<  ID*/
} mavlink_command_t;

#define MAVLINK_MSG_ID_COMMAND_LEN 17
#define MAVLINK_MSG_ID_COMMAND_MIN_LEN 17
#define MAVLINK_MSG_ID_5_LEN 17
#define MAVLINK_MSG_ID_5_MIN_LEN 17

#define MAVLINK_MSG_ID_COMMAND_CRC 168
#define MAVLINK_MSG_ID_5_CRC 168



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_COMMAND { \
    5, \
    "COMMAND", \
    4, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_command_t, ID) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_command_t, timestamp) }, \
         { "GoalPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_t, GoalPosition) }, \
         { "MovingSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_t, MovingSpeed) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_COMMAND { \
    "COMMAND", \
    4, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_command_t, ID) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_command_t, timestamp) }, \
         { "GoalPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_command_t, GoalPosition) }, \
         { "MovingSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_command_t, MovingSpeed) }, \
         } \
}
#endif

/**
 * @brief Pack a command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_uint8_t(buf, 16, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LEN);
#else
    mavlink_command_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
}

/**
 * @brief Pack a command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,uint64_t timestamp,float GoalPosition,float MovingSpeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_uint8_t(buf, 16, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_COMMAND_LEN);
#else
    mavlink_command_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_COMMAND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_COMMAND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
}

/**
 * @brief Encode a command struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_command_t* command)
{
    return mavlink_msg_command_pack(system_id, component_id, msg, command->ID, command->timestamp, command->GoalPosition, command->MovingSpeed);
}

/**
 * @brief Encode a command struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param command C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_command_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_command_t* command)
{
    return mavlink_msg_command_pack_chan(system_id, component_id, chan, msg, command->ID, command->timestamp, command->GoalPosition, command->MovingSpeed);
}

/**
 * @brief Send a command message
 * @param chan MAVLink channel to send the message
 *
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_command_send(mavlink_channel_t chan, uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_COMMAND_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_uint8_t(buf, 16, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND, buf, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
#else
    mavlink_command_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND, (const char *)&packet, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
#endif
}

/**
 * @brief Send a command message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_command_send_struct(mavlink_channel_t chan, const mavlink_command_t* command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_command_send(chan, command->ID, command->timestamp, command->GoalPosition, command->MovingSpeed);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND, (const char *)command, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
#endif
}

#if MAVLINK_MSG_ID_COMMAND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_command_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_uint8_t(buf, 16, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND, buf, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
#else
    mavlink_command_t *packet = (mavlink_command_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->GoalPosition = GoalPosition;
    packet->MovingSpeed = MovingSpeed;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_COMMAND, (const char *)packet, MAVLINK_MSG_ID_COMMAND_MIN_LEN, MAVLINK_MSG_ID_COMMAND_LEN, MAVLINK_MSG_ID_COMMAND_CRC);
#endif
}
#endif

#endif

// MESSAGE COMMAND UNPACKING


/**
 * @brief Get field ID from command message
 *
 * @return  ID
 */
static inline uint8_t mavlink_msg_command_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field timestamp from command message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_command_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field GoalPosition from command message
 *
 * @return  GoalPosition
 */
static inline float mavlink_msg_command_get_GoalPosition(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MovingSpeed from command message
 *
 * @return  MovingSpeed
 */
static inline float mavlink_msg_command_get_MovingSpeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a command message into a struct
 *
 * @param msg The message to decode
 * @param command C-struct to decode the message contents into
 */
static inline void mavlink_msg_command_decode(const mavlink_message_t* msg, mavlink_command_t* command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    command->timestamp = mavlink_msg_command_get_timestamp(msg);
    command->GoalPosition = mavlink_msg_command_get_GoalPosition(msg);
    command->MovingSpeed = mavlink_msg_command_get_MovingSpeed(msg);
    command->ID = mavlink_msg_command_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_COMMAND_LEN? msg->len : MAVLINK_MSG_ID_COMMAND_LEN;
        memset(command, 0, MAVLINK_MSG_ID_COMMAND_LEN);
    memcpy(command, _MAV_PAYLOAD(msg), len);
#endif
}
