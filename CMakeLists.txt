cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

project(CodingSystem)

add_executable(CodingSystem src/CodingSystem.cpp src/GeneralInterface.cpp src/Settings.cpp src/StringProcess.cpp)

target_include_directories(CodingSystem PUBLIC include)
