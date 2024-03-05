cmake_minimum_required(VERSION 3.15)
project(conan2asiotest CXX)

find_package(asio)
add_executable(conan2asiotest src/conan2asiotest.cpp src/main.cpp)
add_executable(async_tcp_echo_server src/async_tcp_echo_server.cpp)
target_link_libraries(conan2asiotest asio::asio)
target_link_libraries(async_tcp_echo_server asio::asio)
install(TARGETS conan2asiotest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
