cmake_minimum_required(VERSION 4.0)
project(cpp_brainfuck_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_brainfuck_interpreter src/main.cpp
        include/utils/brainfuck_utils.h
        src/utils/brainfuck_utils.cpp)

target_include_directories(cpp_brainfuck_interpreter PRIVATE ${CMAKE_SOURCE_DIR}/include)
