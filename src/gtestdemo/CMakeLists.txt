cmake_minimum_required(VERSION 2.8)

project(gtestdemoCXX)

option(test "Build gtestdemo's unit tests" OFF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})

if(test)
  add_subdirectory(test)
else()
  add_subdirectory(src)
endif()

