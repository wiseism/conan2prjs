cmake_minimum_required(VERSION 3.15)
project(conan2example CXX)
SET(CONAN_DISABLE_CHECK_COMPILER true)


add_library(conan2lib src/conanexample.cpp)
add_executable(conan2example src/conanexample.cpp src/main.cpp)
