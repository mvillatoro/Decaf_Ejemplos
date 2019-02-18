cmake_minimum_required(VERSION 2.6)
project(test_lexer)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)

add_executable(test_lexer ../lexer.cpp test_lexer.cpp)

enable_testing()
add_test(NAME test_lexer COMMAND test_lexer)