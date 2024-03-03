cmake_minimum_required(VERSION 3.15)
project(conan2zlibtest CXX)

find_package(ZLIB REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)
install(TARGETS ${PROJECT_NAME} DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)