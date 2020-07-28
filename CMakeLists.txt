cmake_minimum_required(VERSION 3.0)

project(kai_udp)

set (CMAKE_CXX_STANDARD 11)

add_library(kaiudp
    kai_udp.cpp
)

add_executable(server server.cpp)
target_link_libraries(server kai_udp)

add_executable(client client.cpp)
target_link_libraries(client kai_udp)