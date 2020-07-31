cmake_minimum_required(VERSION 3.0)

project(kai_udp)

set (CMAKE_CXX_STANDARD 11)

add_library(kai_udp
    kai_udp.cpp
)

# if(${BUILD_EXAMPLE})

# endif()