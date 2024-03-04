cmake_minimum_required(VERSION 3.15)
project(conan2asiotest CXX)

find_package(asio REQUIRED)

include_directories(C:/Users/edida/.conan2/p/asiof472f53aca4d3/p/include)

add_executable(conan2asiotest src/conan2asiotest.cpp src/main.cpp)
add_executable(async_tcp_echo_server src/async_tcp_echo_server.cpp)

install(TARGETS conan2asiotest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
