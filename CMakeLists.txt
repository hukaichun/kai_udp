cmake_minimum_required(VERSION 3.0.0)

project(UDP_NODE)

set(MAVLINK_GENERATOR ${PROJECT_SOURCE_DIR}/Tools/mavlink/pymavlink/tools/mavgen.py)
set(MAVLINK_OPTION --lang=C++11 --wire-protocol=2.0)
set(MAVLINK_OUTPUT ${PROJECT_SOURCE_DIR}/include/mavlink/msg)
set(MAVLINK_MSG_DEFINITION ${PROJECT_SOURCE_DIR}/msg_definition/actuator.xml)

message(STATUS "UDP_NODE_DIR : " ${PROJECT_SOURCE_DIR})
execute_process(
    COMMAND python3 ${MAVLINK_GENERATOR} ${MAVLINK_OPTION} --output=${MAVLINK_OUTPUT} ${MAVLINK_MSG_DEFINITION}
)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# mavlink_msg
add_subdirectory(src/mavlink)

# kai_udp
add_subdirectory(src/kai_udp)

# udp_node
add_subdirectory(src/udp_node)


if(${BUILD_TEST})
    add_subdirectory(src/test_kai_udp)
endif()