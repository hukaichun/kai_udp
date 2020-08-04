cmake_minimum_required(VERSION 3.0.0)

project(UDP_NODE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src/mavlink)
add_subdirectory(src/kai_udp)
add_subdirectory(src/udp_node)


if(${BUILD_TEST})
    add_subdirectory(src/test_kai_udp)
endif()