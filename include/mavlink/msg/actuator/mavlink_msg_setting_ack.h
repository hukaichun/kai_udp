#pragma once
// MESSAGE SETTING_ACK PACKING

#define MAVLINK_MSG_ID_SETTING_ACK 4


typedef struct __mavlink_setting_ack_t {
 uint8_t ID; /*<  ID*/
 uint8_t STATUS; /*<  Setting status*/
} mavlink_setting_ack_t;

#define MAVLINK_MSG_ID_SETTING_ACK_LEN 2
#define MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN 2
#define MAVLINK_MSG_ID_4_LEN 2
#define MAVLINK_MSG_ID_4_MIN_LEN 2

#define MAVLINK_MSG_ID_SETTING_ACK_CRC 137
#define MAVLINK_MSG_ID_4_CRC 137



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETTING_ACK { \
    4, \
    "SETTING_ACK", \
    2, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_setting_ack_t, ID) }, \
         { "STATUS", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_setting_ack_t, STATUS) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETTING_ACK { \
    "SETTING_ACK", \
    2, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_setting_ack_t, ID) }, \
         { "STATUS", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_setting_ack_t, STATUS) }, \
         } \
}
#endif

/**
 * @brief Pack a setting_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID  ID
 * @param STATUS  Setting status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setting_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, uint8_t STATUS)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_ACK_LEN];
    _mav_put_uint8_t(buf, 0, ID);
    _mav_put_uint8_t(buf, 1, STATUS);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETTING_ACK_LEN);
#else
    mavlink_setting_ack_t packet;
    packet.ID = ID;
    packet.STATUS = STATUS;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETTING_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETTING_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
}

/**
 * @brief Pack a setting_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID  ID
 * @param STATUS  Setting status
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setting_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,uint8_t STATUS)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_ACK_LEN];
    _mav_put_uint8_t(buf, 0, ID);
    _mav_put_uint8_t(buf, 1, STATUS);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETTING_ACK_LEN);
#else
    mavlink_setting_ack_t packet;
    packet.ID = ID;
    packet.STATUS = STATUS;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETTING_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETTING_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
}

/**
 * @brief Encode a setting_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param setting_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setting_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_setting_ack_t* setting_ack)
{
    return mavlink_msg_setting_ack_pack(system_id, component_id, msg, setting_ack->ID, setting_ack->STATUS);
}

/**
 * @brief Encode a setting_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setting_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setting_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_setting_ack_t* setting_ack)
{
    return mavlink_msg_setting_ack_pack_chan(system_id, component_id, chan, msg, setting_ack->ID, setting_ack->STATUS);
}

/**
 * @brief Send a setting_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param ID  ID
 * @param STATUS  Setting status
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_setting_ack_send(mavlink_channel_t chan, uint8_t ID, uint8_t STATUS)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_ACK_LEN];
    _mav_put_uint8_t(buf, 0, ID);
    _mav_put_uint8_t(buf, 1, STATUS);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING_ACK, buf, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
#else
    mavlink_setting_ack_t packet;
    packet.ID = ID;
    packet.STATUS = STATUS;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING_ACK, (const char *)&packet, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
#endif
}

/**
 * @brief Send a setting_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_setting_ack_send_struct(mavlink_channel_t chan, const mavlink_setting_ack_t* setting_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_setting_ack_send(chan, setting_ack->ID, setting_ack->STATUS);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING_ACK, (const char *)setting_ack, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_SETTING_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_setting_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, uint8_t STATUS)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, ID);
    _mav_put_uint8_t(buf, 1, STATUS);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING_ACK, buf, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
#else
    mavlink_setting_ack_t *packet = (mavlink_setting_ack_t *)msgbuf;
    packet->ID = ID;
    packet->STATUS = STATUS;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING_ACK, (const char *)packet, MAVLINK_MSG_ID_SETTING_ACK_MIN_LEN, MAVLINK_MSG_ID_SETTING_ACK_LEN, MAVLINK_MSG_ID_SETTING_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE SETTING_ACK UNPACKING


/**
 * @brief Get field ID from setting_ack message
 *
 * @return  ID
 */
static inline uint8_t mavlink_msg_setting_ack_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field STATUS from setting_ack message
 *
 * @return  Setting status
 */
static inline uint8_t mavlink_msg_setting_ack_get_STATUS(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a setting_ack message into a struct
 *
 * @param msg The message to decode
 * @param setting_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_setting_ack_decode(const mavlink_message_t* msg, mavlink_setting_ack_t* setting_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    setting_ack->ID = mavlink_msg_setting_ack_get_ID(msg);
    setting_ack->STATUS = mavlink_msg_setting_ack_get_STATUS(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SETTING_ACK_LEN? msg->len : MAVLINK_MSG_ID_SETTING_ACK_LEN;
        memset(setting_ack, 0, MAVLINK_MSG_ID_SETTING_ACK_LEN);
    memcpy(setting_ack, _MAV_PAYLOAD(msg), len);
#endif
}
