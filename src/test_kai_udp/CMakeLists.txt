cmake_minimum_required(VERSION 3.0)


project(test_kai_udp)

add_executable(server server.cpp)
target_link_libraries(server kai_udp)

add_executable(client client.cpp)
target_link_libraries(client kai_udp)