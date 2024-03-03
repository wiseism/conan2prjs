cmake_minimum_required(VERSION 3.15)
project(conan2grpctest CXX)



add_executable(conan2grpctest src/conan2grpctest.cpp src/main.cpp
       )



install(TARGETS conan2grpctest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
