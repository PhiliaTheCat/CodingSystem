cmake_minimum_required(VERSION 3.18)

project(CodingSystem C)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

add_executable(CodingSystem CodingSystem.c f_display.c f_process.c)
