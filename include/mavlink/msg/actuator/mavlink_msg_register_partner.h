#pragma once
// MESSAGE REGISTER_PARTNER PACKING

#define MAVLINK_MSG_ID_REGISTER_PARTNER 2


typedef struct __mavlink_register_partner_t {
 uint64_t timestamp; /*<  timestamp*/
} mavlink_register_partner_t;

#define MAVLINK_MSG_ID_REGISTER_PARTNER_LEN 8
#define MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN 8
#define MAVLINK_MSG_ID_2_LEN 8
#define MAVLINK_MSG_ID_2_MIN_LEN 8

#define MAVLINK_MSG_ID_REGISTER_PARTNER_CRC 110
#define MAVLINK_MSG_ID_2_CRC 110



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REGISTER_PARTNER { \
    2, \
    "REGISTER_PARTNER", \
    1, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_register_partner_t, timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REGISTER_PARTNER { \
    "REGISTER_PARTNER", \
    1, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_register_partner_t, timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a register_partner message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_register_partner_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REGISTER_PARTNER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
}

/**
 * @brief Pack a register_partner message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_register_partner_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_REGISTER_PARTNER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
}

/**
 * @brief Encode a register_partner struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param register_partner C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_register_partner_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_register_partner_t* register_partner)
{
    return mavlink_msg_register_partner_pack(system_id, component_id, msg, register_partner->timestamp);
}

/**
 * @brief Encode a register_partner struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param register_partner C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_register_partner_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_register_partner_t* register_partner)
{
    return mavlink_msg_register_partner_pack_chan(system_id, component_id, chan, msg, register_partner->timestamp);
}

/**
 * @brief Send a register_partner message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_register_partner_send(mavlink_channel_t chan, uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, buf, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, (const char *)&packet, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#endif
}

/**
 * @brief Send a register_partner message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_register_partner_send_struct(mavlink_channel_t chan, const mavlink_register_partner_t* register_partner)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_register_partner_send(chan, register_partner->timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, (const char *)register_partner, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#endif
}

#if MAVLINK_MSG_ID_REGISTER_PARTNER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_register_partner_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, buf, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#else
    mavlink_register_partner_t *packet = (mavlink_register_partner_t *)msgbuf;
    packet->timestamp = timestamp;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, (const char *)packet, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#endif
}
#endif

#endif

// MESSAGE REGISTER_PARTNER UNPACKING


/**
 * @brief Get field timestamp from register_partner message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_register_partner_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a register_partner message into a struct
 *
 * @param msg The message to decode
 * @param register_partner C-struct to decode the message contents into
 */
static inline void mavlink_msg_register_partner_decode(const mavlink_message_t* msg, mavlink_register_partner_t* register_partner)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    register_partner->timestamp = mavlink_msg_register_partner_get_timestamp(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REGISTER_PARTNER_LEN? msg->len : MAVLINK_MSG_ID_REGISTER_PARTNER_LEN;
        memset(register_partner, 0, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
    memcpy(register_partner, _MAV_PAYLOAD(msg), len);
#endif
}
