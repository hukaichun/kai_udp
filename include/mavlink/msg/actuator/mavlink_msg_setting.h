#pragma once
// MESSAGE SETTING PACKING

#define MAVLINK_MSG_ID_SETTING 1


typedef struct __mavlink_setting_t {
 int16_t DIR; /*<   Rotation Direction */
 uint16_t ZERO; /*<   Zero Position */
 uint8_t ID; /*<  ID*/
} mavlink_setting_t;

#define MAVLINK_MSG_ID_SETTING_LEN 5
#define MAVLINK_MSG_ID_SETTING_MIN_LEN 5
#define MAVLINK_MSG_ID_1_LEN 5
#define MAVLINK_MSG_ID_1_MIN_LEN 5

#define MAVLINK_MSG_ID_SETTING_CRC 251
#define MAVLINK_MSG_ID_1_CRC 251



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETTING { \
    1, \
    "SETTING", \
    3, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_setting_t, ID) }, \
         { "DIR", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_setting_t, DIR) }, \
         { "ZERO", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_setting_t, ZERO) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETTING { \
    "SETTING", \
    3, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_setting_t, ID) }, \
         { "DIR", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_setting_t, DIR) }, \
         { "ZERO", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_setting_t, ZERO) }, \
         } \
}
#endif

/**
 * @brief Pack a setting message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID  ID
 * @param DIR   Rotation Direction 
 * @param ZERO   Zero Position 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setting_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, int16_t DIR, uint16_t ZERO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_LEN];
    _mav_put_int16_t(buf, 0, DIR);
    _mav_put_uint16_t(buf, 2, ZERO);
    _mav_put_uint8_t(buf, 4, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETTING_LEN);
#else
    mavlink_setting_t packet;
    packet.DIR = DIR;
    packet.ZERO = ZERO;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETTING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETTING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
}

/**
 * @brief Pack a setting message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID  ID
 * @param DIR   Rotation Direction 
 * @param ZERO   Zero Position 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setting_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,int16_t DIR,uint16_t ZERO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_LEN];
    _mav_put_int16_t(buf, 0, DIR);
    _mav_put_uint16_t(buf, 2, ZERO);
    _mav_put_uint8_t(buf, 4, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETTING_LEN);
#else
    mavlink_setting_t packet;
    packet.DIR = DIR;
    packet.ZERO = ZERO;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETTING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETTING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
}

/**
 * @brief Encode a setting struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setting_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_setting_t* setting)
{
    return mavlink_msg_setting_pack(system_id, component_id, msg, setting->ID, setting->DIR, setting->ZERO);
}

/**
 * @brief Encode a setting struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setting C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setting_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_setting_t* setting)
{
    return mavlink_msg_setting_pack_chan(system_id, component_id, chan, msg, setting->ID, setting->DIR, setting->ZERO);
}

/**
 * @brief Send a setting message
 * @param chan MAVLink channel to send the message
 *
 * @param ID  ID
 * @param DIR   Rotation Direction 
 * @param ZERO   Zero Position 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_setting_send(mavlink_channel_t chan, uint8_t ID, int16_t DIR, uint16_t ZERO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETTING_LEN];
    _mav_put_int16_t(buf, 0, DIR);
    _mav_put_uint16_t(buf, 2, ZERO);
    _mav_put_uint8_t(buf, 4, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING, buf, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
#else
    mavlink_setting_t packet;
    packet.DIR = DIR;
    packet.ZERO = ZERO;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING, (const char *)&packet, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
#endif
}

/**
 * @brief Send a setting message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_setting_send_struct(mavlink_channel_t chan, const mavlink_setting_t* setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_setting_send(chan, setting->ID, setting->DIR, setting->ZERO);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING, (const char *)setting, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
#endif
}

#if MAVLINK_MSG_ID_SETTING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_setting_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, int16_t DIR, uint16_t ZERO)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int16_t(buf, 0, DIR);
    _mav_put_uint16_t(buf, 2, ZERO);
    _mav_put_uint8_t(buf, 4, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING, buf, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
#else
    mavlink_setting_t *packet = (mavlink_setting_t *)msgbuf;
    packet->DIR = DIR;
    packet->ZERO = ZERO;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETTING, (const char *)packet, MAVLINK_MSG_ID_SETTING_MIN_LEN, MAVLINK_MSG_ID_SETTING_LEN, MAVLINK_MSG_ID_SETTING_CRC);
#endif
}
#endif

#endif

// MESSAGE SETTING UNPACKING


/**
 * @brief Get field ID from setting message
 *
 * @return  ID
 */
static inline uint8_t mavlink_msg_setting_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field DIR from setting message
 *
 * @return   Rotation Direction 
 */
static inline int16_t mavlink_msg_setting_get_DIR(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field ZERO from setting message
 *
 * @return   Zero Position 
 */
static inline uint16_t mavlink_msg_setting_get_ZERO(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a setting message into a struct
 *
 * @param msg The message to decode
 * @param setting C-struct to decode the message contents into
 */
static inline void mavlink_msg_setting_decode(const mavlink_message_t* msg, mavlink_setting_t* setting)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    setting->DIR = mavlink_msg_setting_get_DIR(msg);
    setting->ZERO = mavlink_msg_setting_get_ZERO(msg);
    setting->ID = mavlink_msg_setting_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SETTING_LEN? msg->len : MAVLINK_MSG_ID_SETTING_LEN;
        memset(setting, 0, MAVLINK_MSG_ID_SETTING_LEN);
    memcpy(setting, _MAV_PAYLOAD(msg), len);
#endif
}
