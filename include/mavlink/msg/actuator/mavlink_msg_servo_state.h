#pragma once
// MESSAGE SERVO_STATE PACKING

#define MAVLINK_MSG_ID_SERVO_STATE 0


typedef struct __mavlink_servo_state_t {
 uint64_t timestamp; /*<  timestamp*/
 float GoalPosition; /*<  GoalPosition*/
 float MovingSpeed; /*<  MovingSpeed*/
 float PresentPosition; /*<  PresentPosition*/
 float PresentSpeed; /*<  PresentSpeed*/
 float PresentLoad; /*<  PresentLoad*/
 uint32_t PresentTemperature; /*<  PresentTemperature*/
 uint8_t ID; /*<  ID*/
} mavlink_servo_state_t;

#define MAVLINK_MSG_ID_SERVO_STATE_LEN 33
#define MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN 33
#define MAVLINK_MSG_ID_0_LEN 33
#define MAVLINK_MSG_ID_0_MIN_LEN 33

#define MAVLINK_MSG_ID_SERVO_STATE_CRC 81
#define MAVLINK_MSG_ID_0_CRC 81



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SERVO_STATE { \
    0, \
    "SERVO_STATE", \
    8, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_servo_state_t, ID) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_servo_state_t, timestamp) }, \
         { "GoalPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_servo_state_t, GoalPosition) }, \
         { "MovingSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_servo_state_t, MovingSpeed) }, \
         { "PresentPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_servo_state_t, PresentPosition) }, \
         { "PresentSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_servo_state_t, PresentSpeed) }, \
         { "PresentLoad", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_servo_state_t, PresentLoad) }, \
         { "PresentTemperature", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_servo_state_t, PresentTemperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SERVO_STATE { \
    "SERVO_STATE", \
    8, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_servo_state_t, ID) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_servo_state_t, timestamp) }, \
         { "GoalPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_servo_state_t, GoalPosition) }, \
         { "MovingSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_servo_state_t, MovingSpeed) }, \
         { "PresentPosition", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_servo_state_t, PresentPosition) }, \
         { "PresentSpeed", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_servo_state_t, PresentSpeed) }, \
         { "PresentLoad", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_servo_state_t, PresentLoad) }, \
         { "PresentTemperature", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_servo_state_t, PresentTemperature) }, \
         } \
}
#endif

/**
 * @brief Pack a servo_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 * @param PresentPosition  PresentPosition
 * @param PresentSpeed  PresentSpeed
 * @param PresentLoad  PresentLoad
 * @param PresentTemperature  PresentTemperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_servo_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed, float PresentPosition, float PresentSpeed, float PresentLoad, uint32_t PresentTemperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVO_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_float(buf, 16, PresentPosition);
    _mav_put_float(buf, 20, PresentSpeed);
    _mav_put_float(buf, 24, PresentLoad);
    _mav_put_uint32_t(buf, 28, PresentTemperature);
    _mav_put_uint8_t(buf, 32, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVO_STATE_LEN);
#else
    mavlink_servo_state_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.PresentPosition = PresentPosition;
    packet.PresentSpeed = PresentSpeed;
    packet.PresentLoad = PresentLoad;
    packet.PresentTemperature = PresentTemperature;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVO_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERVO_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
}

/**
 * @brief Pack a servo_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 * @param PresentPosition  PresentPosition
 * @param PresentSpeed  PresentSpeed
 * @param PresentLoad  PresentLoad
 * @param PresentTemperature  PresentTemperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_servo_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,uint64_t timestamp,float GoalPosition,float MovingSpeed,float PresentPosition,float PresentSpeed,float PresentLoad,uint32_t PresentTemperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVO_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_float(buf, 16, PresentPosition);
    _mav_put_float(buf, 20, PresentSpeed);
    _mav_put_float(buf, 24, PresentLoad);
    _mav_put_uint32_t(buf, 28, PresentTemperature);
    _mav_put_uint8_t(buf, 32, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SERVO_STATE_LEN);
#else
    mavlink_servo_state_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.PresentPosition = PresentPosition;
    packet.PresentSpeed = PresentSpeed;
    packet.PresentLoad = PresentLoad;
    packet.PresentTemperature = PresentTemperature;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SERVO_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SERVO_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
}

/**
 * @brief Encode a servo_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param servo_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_servo_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_servo_state_t* servo_state)
{
    return mavlink_msg_servo_state_pack(system_id, component_id, msg, servo_state->ID, servo_state->timestamp, servo_state->GoalPosition, servo_state->MovingSpeed, servo_state->PresentPosition, servo_state->PresentSpeed, servo_state->PresentLoad, servo_state->PresentTemperature);
}

/**
 * @brief Encode a servo_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param servo_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_servo_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_servo_state_t* servo_state)
{
    return mavlink_msg_servo_state_pack_chan(system_id, component_id, chan, msg, servo_state->ID, servo_state->timestamp, servo_state->GoalPosition, servo_state->MovingSpeed, servo_state->PresentPosition, servo_state->PresentSpeed, servo_state->PresentLoad, servo_state->PresentTemperature);
}

/**
 * @brief Send a servo_state message
 * @param chan MAVLink channel to send the message
 *
 * @param ID  ID
 * @param timestamp  timestamp
 * @param GoalPosition  GoalPosition
 * @param MovingSpeed  MovingSpeed
 * @param PresentPosition  PresentPosition
 * @param PresentSpeed  PresentSpeed
 * @param PresentLoad  PresentLoad
 * @param PresentTemperature  PresentTemperature
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_servo_state_send(mavlink_channel_t chan, uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed, float PresentPosition, float PresentSpeed, float PresentLoad, uint32_t PresentTemperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SERVO_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_float(buf, 16, PresentPosition);
    _mav_put_float(buf, 20, PresentSpeed);
    _mav_put_float(buf, 24, PresentLoad);
    _mav_put_uint32_t(buf, 28, PresentTemperature);
    _mav_put_uint8_t(buf, 32, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_STATE, buf, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
#else
    mavlink_servo_state_t packet;
    packet.timestamp = timestamp;
    packet.GoalPosition = GoalPosition;
    packet.MovingSpeed = MovingSpeed;
    packet.PresentPosition = PresentPosition;
    packet.PresentSpeed = PresentSpeed;
    packet.PresentLoad = PresentLoad;
    packet.PresentTemperature = PresentTemperature;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_STATE, (const char *)&packet, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
#endif
}

/**
 * @brief Send a servo_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_servo_state_send_struct(mavlink_channel_t chan, const mavlink_servo_state_t* servo_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_servo_state_send(chan, servo_state->ID, servo_state->timestamp, servo_state->GoalPosition, servo_state->MovingSpeed, servo_state->PresentPosition, servo_state->PresentSpeed, servo_state->PresentLoad, servo_state->PresentTemperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_STATE, (const char *)servo_state, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_SERVO_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_servo_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, uint64_t timestamp, float GoalPosition, float MovingSpeed, float PresentPosition, float PresentSpeed, float PresentLoad, uint32_t PresentTemperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, GoalPosition);
    _mav_put_float(buf, 12, MovingSpeed);
    _mav_put_float(buf, 16, PresentPosition);
    _mav_put_float(buf, 20, PresentSpeed);
    _mav_put_float(buf, 24, PresentLoad);
    _mav_put_uint32_t(buf, 28, PresentTemperature);
    _mav_put_uint8_t(buf, 32, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_STATE, buf, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
#else
    mavlink_servo_state_t *packet = (mavlink_servo_state_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->GoalPosition = GoalPosition;
    packet->MovingSpeed = MovingSpeed;
    packet->PresentPosition = PresentPosition;
    packet->PresentSpeed = PresentSpeed;
    packet->PresentLoad = PresentLoad;
    packet->PresentTemperature = PresentTemperature;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SERVO_STATE, (const char *)packet, MAVLINK_MSG_ID_SERVO_STATE_MIN_LEN, MAVLINK_MSG_ID_SERVO_STATE_LEN, MAVLINK_MSG_ID_SERVO_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE SERVO_STATE UNPACKING


/**
 * @brief Get field ID from servo_state message
 *
 * @return  ID
 */
static inline uint8_t mavlink_msg_servo_state_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field timestamp from servo_state message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_servo_state_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field GoalPosition from servo_state message
 *
 * @return  GoalPosition
 */
static inline float mavlink_msg_servo_state_get_GoalPosition(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field MovingSpeed from servo_state message
 *
 * @return  MovingSpeed
 */
static inline float mavlink_msg_servo_state_get_MovingSpeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field PresentPosition from servo_state message
 *
 * @return  PresentPosition
 */
static inline float mavlink_msg_servo_state_get_PresentPosition(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field PresentSpeed from servo_state message
 *
 * @return  PresentSpeed
 */
static inline float mavlink_msg_servo_state_get_PresentSpeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field PresentLoad from servo_state message
 *
 * @return  PresentLoad
 */
static inline float mavlink_msg_servo_state_get_PresentLoad(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field PresentTemperature from servo_state message
 *
 * @return  PresentTemperature
 */
static inline uint32_t mavlink_msg_servo_state_get_PresentTemperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Decode a servo_state message into a struct
 *
 * @param msg The message to decode
 * @param servo_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_servo_state_decode(const mavlink_message_t* msg, mavlink_servo_state_t* servo_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    servo_state->timestamp = mavlink_msg_servo_state_get_timestamp(msg);
    servo_state->GoalPosition = mavlink_msg_servo_state_get_GoalPosition(msg);
    servo_state->MovingSpeed = mavlink_msg_servo_state_get_MovingSpeed(msg);
    servo_state->PresentPosition = mavlink_msg_servo_state_get_PresentPosition(msg);
    servo_state->PresentSpeed = mavlink_msg_servo_state_get_PresentSpeed(msg);
    servo_state->PresentLoad = mavlink_msg_servo_state_get_PresentLoad(msg);
    servo_state->PresentTemperature = mavlink_msg_servo_state_get_PresentTemperature(msg);
    servo_state->ID = mavlink_msg_servo_state_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SERVO_STATE_LEN? msg->len : MAVLINK_MSG_ID_SERVO_STATE_LEN;
        memset(servo_state, 0, MAVLINK_MSG_ID_SERVO_STATE_LEN);
    memcpy(servo_state, _MAV_PAYLOAD(msg), len);
#endif
}
