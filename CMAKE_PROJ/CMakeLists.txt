cmake_minimum_required(VERSION 3.19)

project(SevenSeg C CXX ASM)

add_library(MCAL STATIC lib/dio.c)

target_include_directories(MCAL PUBLIC)

add_executable(${PROJECT_NAME} src/dio.c src/main.c)

# 
# target_include_directories(${PROJECT_NAME} inc/)
include_directories(./inc/)

add_dependencies()