cmake_minimum_required(VERSION 3.15)
project(conan2opencvtest CXX)



add_executable(conan2opencvtest src/conan2opencvtest.cpp src/main.cpp
        src/opencvtest.cpp)



install(TARGETS conan2opencvtest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
