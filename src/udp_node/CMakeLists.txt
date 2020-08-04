cmake_minimum_required(VERSION 3.0)

project(kai_udp)

set (CMAKE_CXX_STANDARD 11)

add_library(udp_node
    udp_node.cpp 
    schedule/schedule_base.cpp
)

target_link_libraries(udp_node PUBLIC pthread kai_udp)

# if(${BUILD_EXAMPLE})

# endif()