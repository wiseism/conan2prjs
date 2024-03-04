cmake_minimum_required(VERSION 3.15)
project(conan2opencvtest CXX)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/conan2opencvtest.cpp src/main.cpp
        src/opencvtest.cpp)

target_link_libraries(${PROJECT_NAME} OpenCV::OpenCV)


install(TARGETS ${PROJECT_NAME} DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
