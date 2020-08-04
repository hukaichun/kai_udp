cmake_minimum_required(VERSION 3.0)

project(kai_udp)

set (CMAKE_CXX_STANDARD 11)

add_library(kai_udp
    kai_udp.cpp 
    udp_node.cpp 
    schedule/schedule_base.cpp
    address_book/address_book.cpp
)

target_link_libraries(kai_udp PUBLIC pthread)

# if(${BUILD_EXAMPLE})

# endif()