cmake_minimum_required(VERSION 3.19)

project(SevenSegment C CXX)

add_library(Classes
            SHARED 
            src/gpio.cpp
            src/IOStream.cpp
            src/IStream.cpp
            src/OStream.cpp
            src/Stream.cpp
            src/SevenSeg.cpp)

target_include_directories(Classes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} App/Task5.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Classes)