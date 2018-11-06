cmake_minimum_required(VERSION 2.8)

project(gtestdemo CXX)

set(CMAKE_CXX_FLAGS "-g -Wall")

add_library(sample ${CMAKE_CURRENT_SOURCE_DIR}/sample.cpp)
add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(demo sample)
