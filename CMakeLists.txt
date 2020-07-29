cmake_minimum_required(VERSION 3.0)

project(kai_udp)

set (CMAKE_CXX_STANDARD 11)

add_library(kai_udp
    kai_udp.cpp
)

if(${BUILD_EXAMPLE})
    add_executable(server server.cpp)
    target_link_libraries(server kaiudp)

    add_executable(client client.cpp)
    target_link_libraries(client kaiudp)
endif()