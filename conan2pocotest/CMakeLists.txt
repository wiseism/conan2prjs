cmake_minimum_required(VERSION 3.15)
project(conan2pocotest CXX)



add_executable(conan2pocotest src/conan2pocotest.cpp src/main.cpp)



install(TARGETS conan2pocotest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
