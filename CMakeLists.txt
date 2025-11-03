cmake_minimum_required(VERSION 3.31.6)
project(cpp_brainfuck_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_brainfuck_interpreter src/main.cpp
        include/utils/build_bracket_map.h
        src/utils/build_bracket_map.cpp
        src/utils/open_brainfuck_file.cpp
        include/utils/open_brainfuck_file.h
        src/utils/clean_the_code.cpp
        include/utils/clean_the_code.h
        src/interpreter.cpp
        include/interpreter.h)

target_include_directories(cpp_brainfuck_interpreter PRIVATE ${CMAKE_SOURCE_DIR}/include)
