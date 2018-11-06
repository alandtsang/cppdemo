cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "-g -Wall -Wextra -ffunction-sections -O3 -pthread -msse4.2")
add_definitions(--std=c++11)

set(TESTING_SOURCES
  ${MAIN_DIR}/src/sample.cpp
  )

add_library(testing STATIC ${TESTING_SOURCES})

set(TEST_TARGETS
  sample_test
  )

foreach(target ${TEST_TARGETS})
  add_executable(${target} ${target}.cpp main.cpp)
  target_link_libraries(${target} testing ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
  add_test(NAME ${target} COMMAND ${target})
endforeach(target)
