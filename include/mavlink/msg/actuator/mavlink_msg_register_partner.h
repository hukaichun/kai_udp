#pragma once
// MESSAGE REGISTER_PARTNER PACKING

#define MAVLINK_MSG_ID_REGISTER_PARTNER 2


typedef struct __mavlink_register_partner_t {
 uint64_t timestamp; /*<  timestamp*/
 uint32_t port; /*<  port*/
 uint16_t ip_0; /*<  ip*/
 uint16_t ip_1; /*<  ip*/
 uint16_t ip_2; /*<  ip*/
 uint16_t ip_3; /*<  ip*/
} mavlink_register_partner_t;

#define MAVLINK_MSG_ID_REGISTER_PARTNER_LEN 20
#define MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN 20
#define MAVLINK_MSG_ID_2_LEN 20
#define MAVLINK_MSG_ID_2_MIN_LEN 20

#define MAVLINK_MSG_ID_REGISTER_PARTNER_CRC 151
#define MAVLINK_MSG_ID_2_CRC 151



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_REGISTER_PARTNER { \
    2, \
    "REGISTER_PARTNER", \
    6, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_register_partner_t, timestamp) }, \
         { "ip_0", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_register_partner_t, ip_0) }, \
         { "ip_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_register_partner_t, ip_1) }, \
         { "ip_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_register_partner_t, ip_2) }, \
         { "ip_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_register_partner_t, ip_3) }, \
         { "port", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_register_partner_t, port) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_REGISTER_PARTNER { \
    "REGISTER_PARTNER", \
    6, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_register_partner_t, timestamp) }, \
         { "ip_0", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_register_partner_t, ip_0) }, \
         { "ip_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_register_partner_t, ip_1) }, \
         { "ip_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_register_partner_t, ip_2) }, \
         { "ip_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_register_partner_t, ip_3) }, \
         { "port", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_register_partner_t, port) }, \
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
 * @param ip_0  ip
 * @param ip_1  ip
 * @param ip_2  ip
 * @param ip_3  ip
 * @param port  port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_register_partner_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint16_t ip_0, uint16_t ip_1, uint16_t ip_2, uint16_t ip_3, uint32_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, port);
    _mav_put_uint16_t(buf, 12, ip_0);
    _mav_put_uint16_t(buf, 14, ip_1);
    _mav_put_uint16_t(buf, 16, ip_2);
    _mav_put_uint16_t(buf, 18, ip_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;
    packet.port = port;
    packet.ip_0 = ip_0;
    packet.ip_1 = ip_1;
    packet.ip_2 = ip_2;
    packet.ip_3 = ip_3;

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
 * @param ip_0  ip
 * @param ip_1  ip
 * @param ip_2  ip
 * @param ip_3  ip
 * @param port  port
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_register_partner_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint16_t ip_0,uint16_t ip_1,uint16_t ip_2,uint16_t ip_3,uint32_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, port);
    _mav_put_uint16_t(buf, 12, ip_0);
    _mav_put_uint16_t(buf, 14, ip_1);
    _mav_put_uint16_t(buf, 16, ip_2);
    _mav_put_uint16_t(buf, 18, ip_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;
    packet.port = port;
    packet.ip_0 = ip_0;
    packet.ip_1 = ip_1;
    packet.ip_2 = ip_2;
    packet.ip_3 = ip_3;

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
    return mavlink_msg_register_partner_pack(system_id, component_id, msg, register_partner->timestamp, register_partner->ip_0, register_partner->ip_1, register_partner->ip_2, register_partner->ip_3, register_partner->port);
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
    return mavlink_msg_register_partner_pack_chan(system_id, component_id, chan, msg, register_partner->timestamp, register_partner->ip_0, register_partner->ip_1, register_partner->ip_2, register_partner->ip_3, register_partner->port);
}

/**
 * @brief Send a register_partner message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param ip_0  ip
 * @param ip_1  ip
 * @param ip_2  ip
 * @param ip_3  ip
 * @param port  port
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_register_partner_send(mavlink_channel_t chan, uint64_t timestamp, uint16_t ip_0, uint16_t ip_1, uint16_t ip_2, uint16_t ip_3, uint32_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_REGISTER_PARTNER_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, port);
    _mav_put_uint16_t(buf, 12, ip_0);
    _mav_put_uint16_t(buf, 14, ip_1);
    _mav_put_uint16_t(buf, 16, ip_2);
    _mav_put_uint16_t(buf, 18, ip_3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, buf, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#else
    mavlink_register_partner_t packet;
    packet.timestamp = timestamp;
    packet.port = port;
    packet.ip_0 = ip_0;
    packet.ip_1 = ip_1;
    packet.ip_2 = ip_2;
    packet.ip_3 = ip_3;

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
    mavlink_msg_register_partner_send(chan, register_partner->timestamp, register_partner->ip_0, register_partner->ip_1, register_partner->ip_2, register_partner->ip_3, register_partner->port);
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
static inline void mavlink_msg_register_partner_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint16_t ip_0, uint16_t ip_1, uint16_t ip_2, uint16_t ip_3, uint32_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, port);
    _mav_put_uint16_t(buf, 12, ip_0);
    _mav_put_uint16_t(buf, 14, ip_1);
    _mav_put_uint16_t(buf, 16, ip_2);
    _mav_put_uint16_t(buf, 18, ip_3);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_REGISTER_PARTNER, buf, MAVLINK_MSG_ID_REGISTER_PARTNER_MIN_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN, MAVLINK_MSG_ID_REGISTER_PARTNER_CRC);
#else
    mavlink_register_partner_t *packet = (mavlink_register_partner_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->port = port;
    packet->ip_0 = ip_0;
    packet->ip_1 = ip_1;
    packet->ip_2 = ip_2;
    packet->ip_3 = ip_3;

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
 * @brief Get field ip_0 from register_partner message
 *
 * @return  ip
 */
static inline uint16_t mavlink_msg_register_partner_get_ip_0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field ip_1 from register_partner message
 *
 * @return  ip
 */
static inline uint16_t mavlink_msg_register_partner_get_ip_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field ip_2 from register_partner message
 *
 * @return  ip
 */
static inline uint16_t mavlink_msg_register_partner_get_ip_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field ip_3 from register_partner message
 *
 * @return  ip
 */
static inline uint16_t mavlink_msg_register_partner_get_ip_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field port from register_partner message
 *
 * @return  port
 */
static inline uint32_t mavlink_msg_register_partner_get_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
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
    register_partner->port = mavlink_msg_register_partner_get_port(msg);
    register_partner->ip_0 = mavlink_msg_register_partner_get_ip_0(msg);
    register_partner->ip_1 = mavlink_msg_register_partner_get_ip_1(msg);
    register_partner->ip_2 = mavlink_msg_register_partner_get_ip_2(msg);
    register_partner->ip_3 = mavlink_msg_register_partner_get_ip_3(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_REGISTER_PARTNER_LEN? msg->len : MAVLINK_MSG_ID_REGISTER_PARTNER_LEN;
        memset(register_partner, 0, MAVLINK_MSG_ID_REGISTER_PARTNER_LEN);
    memcpy(register_partner, _MAV_PAYLOAD(msg), len);
#endif
}
