#pragma once
// MESSAGE ACTION PACKING

#define MAVLINK_MSG_ID_ACTION 4


typedef struct __mavlink_action_t {

} mavlink_action_t;

#define MAVLINK_MSG_ID_ACTION_LEN 0
#define MAVLINK_MSG_ID_ACTION_MIN_LEN 0
#define MAVLINK_MSG_ID_4_LEN 0
#define MAVLINK_MSG_ID_4_MIN_LEN 0

#define MAVLINK_MSG_ID_ACTION_CRC 176
#define MAVLINK_MSG_ID_4_CRC 176



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACTION { \
    4, \
    "ACTION", \
    0, \
    {  } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACTION { \
    "ACTION", \
    0, \
    {  } \
}
#endif

/**
 * @brief Pack a action message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *

 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                              )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTION_LEN];


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTION_LEN);
#else
    mavlink_action_t packet;


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACTION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
}

/**
 * @brief Pack a action message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into

 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_action_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTION_LEN];


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACTION_LEN);
#else
    mavlink_action_t packet;


        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACTION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACTION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
}

/**
 * @brief Encode a action struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_action_t* action)
{
    return mavlink_msg_action_pack(system_id, component_id, msg,);
}

/**
 * @brief Encode a action struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param action C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_action_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_action_t* action)
{
    return mavlink_msg_action_pack_chan(system_id, component_id, chan, msg,);
}

/**
 * @brief Send a action message
 * @param chan MAVLink channel to send the message
 *

 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_action_send(mavlink_channel_t chan,)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACTION_LEN];


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTION, buf, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
#else
    mavlink_action_t packet;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTION, (const char *)&packet, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
#endif
}

/**
 * @brief Send a action message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_action_send_struct(mavlink_channel_t chan, const mavlink_action_t* action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_action_send(chan,);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTION, (const char *)action, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACTION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_action_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan, )
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTION, buf, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
#else
    mavlink_action_t *packet = (mavlink_action_t *)msgbuf;


    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACTION, (const char *)packet, MAVLINK_MSG_ID_ACTION_MIN_LEN, MAVLINK_MSG_ID_ACTION_LEN, MAVLINK_MSG_ID_ACTION_CRC);
#endif
}
#endif

#endif

// MESSAGE ACTION UNPACKING



/**
 * @brief Decode a action message into a struct
 *
 * @param msg The message to decode
 * @param action C-struct to decode the message contents into
 */
static inline void mavlink_msg_action_decode(const mavlink_message_t* msg, mavlink_action_t* action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS

#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACTION_LEN? msg->len : MAVLINK_MSG_ID_ACTION_LEN;
        memset(action, 0, MAVLINK_MSG_ID_ACTION_LEN);
    memcpy(action, _MAV_PAYLOAD(msg), len);
#endif
}
