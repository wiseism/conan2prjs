cmake_minimum_required(VERSION 3.6)
project(PackageTest CXX)
SET(CONAN_DISABLE_CHECK_COMPILER true)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(example example.cpp)
target_link_libraries(example ${CONAN_LIBS})

# array_tests.cpp
add_executable(array_tests array_tests.cpp)
target_link_libraries(array_tests ${CONAN_LIBS} )

add_executable(json_test json_test.cc)
target_link_libraries(json_test ${CONAN_LIBS})

# CTest is a testing tool that can be used to test your project.
# enable_testing()
# add_test(NAME example
#          WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#          COMMAND example)

add_executable(greeter_server greeter_server.cc protos/helloworld.pb.cc protos/helloworld.grpc.pb.cc)
target_link_libraries(greeter_server ${CONAN_LIBS})

add_executable(greeter_client greeter_client.cc protos/helloworld.pb.cc protos/helloworld.grpc.pb.cc)
target_link_libraries(greeter_client ${CONAN_LIBS})