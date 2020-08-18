/** @file
 *	@brief MAVLink comm testsuite protocol generated from actuator.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "actuator.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(actuator, SERVO_STATE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::SERVO_STATE packet_in{};
    packet_in.ID = 101;
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.TorqueEnable = 168;
    packet_in.GoalPosition = 73.0;
    packet_in.MovingSpeed = 101.0;
    packet_in.PresentPosition = 129.0;
    packet_in.PresentSpeed = 157.0;
    packet_in.PresentLoad = 185.0;
    packet_in.PresentTemperature = 963498920;

    mavlink::actuator::msg::SERVO_STATE packet1{};
    mavlink::actuator::msg::SERVO_STATE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ID, packet2.ID);
    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
    EXPECT_EQ(packet1.TorqueEnable, packet2.TorqueEnable);
    EXPECT_EQ(packet1.GoalPosition, packet2.GoalPosition);
    EXPECT_EQ(packet1.MovingSpeed, packet2.MovingSpeed);
    EXPECT_EQ(packet1.PresentPosition, packet2.PresentPosition);
    EXPECT_EQ(packet1.PresentSpeed, packet2.PresentSpeed);
    EXPECT_EQ(packet1.PresentLoad, packet2.PresentLoad);
    EXPECT_EQ(packet1.PresentTemperature, packet2.PresentTemperature);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, SERVO_STATE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_servo_state_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 129.0, 157.0, 185.0, 963498920, 101, 168
    };

    mavlink::actuator::msg::SERVO_STATE packet_in{};
    packet_in.ID = 101;
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.TorqueEnable = 168;
    packet_in.GoalPosition = 73.0;
    packet_in.MovingSpeed = 101.0;
    packet_in.PresentPosition = 129.0;
    packet_in.PresentSpeed = 157.0;
    packet_in.PresentLoad = 185.0;
    packet_in.PresentTemperature = 963498920;

    mavlink::actuator::msg::SERVO_STATE packet2{};

    mavlink_msg_servo_state_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ID, packet2.ID);
    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);
    EXPECT_EQ(packet_in.TorqueEnable, packet2.TorqueEnable);
    EXPECT_EQ(packet_in.GoalPosition, packet2.GoalPosition);
    EXPECT_EQ(packet_in.MovingSpeed, packet2.MovingSpeed);
    EXPECT_EQ(packet_in.PresentPosition, packet2.PresentPosition);
    EXPECT_EQ(packet_in.PresentSpeed, packet2.PresentSpeed);
    EXPECT_EQ(packet_in.PresentLoad, packet2.PresentLoad);
    EXPECT_EQ(packet_in.PresentTemperature, packet2.PresentTemperature);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::HEARTBEAT packet_in{};
    packet_in.timestamp = 93372036854775807ULL;

    mavlink::actuator::msg::HEARTBEAT packet1{};
    mavlink::actuator::msg::HEARTBEAT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_heartbeat_t packet_c {
         93372036854775807ULL
    };

    mavlink::actuator::msg::HEARTBEAT packet_in{};
    packet_in.timestamp = 93372036854775807ULL;

    mavlink::actuator::msg::HEARTBEAT packet2{};

    mavlink_msg_heartbeat_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, REGISTER_PARTNER)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::REGISTER_PARTNER packet_in{};
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.ip_0 = 163;
    packet_in.ip_1 = 230;
    packet_in.ip_2 = 41;
    packet_in.ip_3 = 108;
    packet_in.port = 17651;

    mavlink::actuator::msg::REGISTER_PARTNER packet1{};
    mavlink::actuator::msg::REGISTER_PARTNER packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
    EXPECT_EQ(packet1.ip_0, packet2.ip_0);
    EXPECT_EQ(packet1.ip_1, packet2.ip_1);
    EXPECT_EQ(packet1.ip_2, packet2.ip_2);
    EXPECT_EQ(packet1.ip_3, packet2.ip_3);
    EXPECT_EQ(packet1.port, packet2.port);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, REGISTER_PARTNER)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_register_partner_t packet_c {
         93372036854775807ULL, 17651, 163, 230, 41, 108
    };

    mavlink::actuator::msg::REGISTER_PARTNER packet_in{};
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.ip_0 = 163;
    packet_in.ip_1 = 230;
    packet_in.ip_2 = 41;
    packet_in.ip_3 = 108;
    packet_in.port = 17651;

    mavlink::actuator::msg::REGISTER_PARTNER packet2{};

    mavlink_msg_register_partner_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);
    EXPECT_EQ(packet_in.ip_0, packet2.ip_0);
    EXPECT_EQ(packet_in.ip_1, packet2.ip_1);
    EXPECT_EQ(packet_in.ip_2, packet2.ip_2);
    EXPECT_EQ(packet_in.ip_3, packet2.ip_3);
    EXPECT_EQ(packet_in.port, packet2.port);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, SETTING)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::SETTING packet_in{};
    packet_in.ID = 17;
    packet_in.DIR = 17235;
    packet_in.ZERO = 17339;

    mavlink::actuator::msg::SETTING packet1{};
    mavlink::actuator::msg::SETTING packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ID, packet2.ID);
    EXPECT_EQ(packet1.DIR, packet2.DIR);
    EXPECT_EQ(packet1.ZERO, packet2.ZERO);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, SETTING)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_setting_t packet_c {
         17235, 17339, 17
    };

    mavlink::actuator::msg::SETTING packet_in{};
    packet_in.ID = 17;
    packet_in.DIR = 17235;
    packet_in.ZERO = 17339;

    mavlink::actuator::msg::SETTING packet2{};

    mavlink_msg_setting_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ID, packet2.ID);
    EXPECT_EQ(packet_in.DIR, packet2.DIR);
    EXPECT_EQ(packet_in.ZERO, packet2.ZERO);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, COMMAND)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::COMMAND packet_in{};
    packet_in.ID = 53;
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.GoalPosition = 73.0;
    packet_in.MovingSpeed = 101.0;

    mavlink::actuator::msg::COMMAND packet1{};
    mavlink::actuator::msg::COMMAND packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ID, packet2.ID);
    EXPECT_EQ(packet1.timestamp, packet2.timestamp);
    EXPECT_EQ(packet1.GoalPosition, packet2.GoalPosition);
    EXPECT_EQ(packet1.MovingSpeed, packet2.MovingSpeed);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, COMMAND)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_command_t packet_c {
         93372036854775807ULL, 73.0, 101.0, 53
    };

    mavlink::actuator::msg::COMMAND packet_in{};
    packet_in.ID = 53;
    packet_in.timestamp = 93372036854775807ULL;
    packet_in.GoalPosition = 73.0;
    packet_in.MovingSpeed = 101.0;

    mavlink::actuator::msg::COMMAND packet2{};

    mavlink_msg_command_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ID, packet2.ID);
    EXPECT_EQ(packet_in.timestamp, packet2.timestamp);
    EXPECT_EQ(packet_in.GoalPosition, packet2.GoalPosition);
    EXPECT_EQ(packet_in.MovingSpeed, packet2.MovingSpeed);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, ACTION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::ACTION packet_in{};


    mavlink::actuator::msg::ACTION packet1{};
    mavlink::actuator::msg::ACTION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);


}

#ifdef TEST_INTEROP
TEST(actuator_interop, ACTION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_action_t packet_c {
        
    };

    mavlink::actuator::msg::ACTION packet_in{};


    mavlink::actuator::msg::ACTION packet2{};

    mavlink_msg_action_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);



#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(actuator, ACK)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::actuator::msg::ACK packet_in{};
    packet_in.MSG_TYPE = 963497464;
    packet_in.STATUS = 17;

    mavlink::actuator::msg::ACK packet1{};
    mavlink::actuator::msg::ACK packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.MSG_TYPE, packet2.MSG_TYPE);
    EXPECT_EQ(packet1.STATUS, packet2.STATUS);
}

#ifdef TEST_INTEROP
TEST(actuator_interop, ACK)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_ack_t packet_c {
         963497464, 17
    };

    mavlink::actuator::msg::ACK packet_in{};
    packet_in.MSG_TYPE = 963497464;
    packet_in.STATUS = 17;

    mavlink::actuator::msg::ACK packet2{};

    mavlink_msg_ack_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.MSG_TYPE, packet2.MSG_TYPE);
    EXPECT_EQ(packet_in.STATUS, packet2.STATUS);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
