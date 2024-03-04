cmake_minimum_required(VERSION 3.15)
project(conan2grpctest CXX)

find_package(gRPC REQUIRED)


add_executable(conan2grpctest src/conan2grpctest.cpp src/main.cpp
       )

target_link_libraries(conan2grpctest grpc::grpc)


install(TARGETS conan2grpctest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
