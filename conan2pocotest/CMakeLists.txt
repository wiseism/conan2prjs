cmake_minimum_required(VERSION 3.15)
project(conan2pocotest CXX)
find_package(Poco REQUIRED)

add_executable(conan2pocotest
        src/pocoservertest.cpp)
target_link_libraries(conan2pocotest Poco::Poco)

install(TARGETS conan2pocotest DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
