cmake_minimum_required(VERSION 3.16)
project(cc)

set(CMAKE_CXX_STANDARD 20)

add_executable(cc main.cpp Scanner.cpp Error.cpp Parser.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
file(COPY assert.sh test.sh DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
