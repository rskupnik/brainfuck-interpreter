cmake_minimum_required(VERSION 2.8.9)
project(brainfuck-interpreter)

# Bring the headers into the project
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

add_executable(brainfuckInterpreter ${SOURCES})
