cmake_minimum_required(VERSION 2.6)
project(test_parser)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)

add_executable(test_parser ../lexer.cpp ../parser.cpp test_parser.cpp)

enable_testing()
add_test(NAME test_parser COMMAND test_parser)