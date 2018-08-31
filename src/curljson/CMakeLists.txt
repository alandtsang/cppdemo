project(client)
cmake_minimum_required(VERSION 2.8)
SET(CMAKE_CXX_COMPILER "/usr/bin/g++")

include_directories(${PROJECT_SOURCE_DIR}/include /usr/include)
message(STATUS "include path：${PROJECT_SOURCE_DIR}/include")

link_directories(${PROJECT_SOURCE_DIR}/lib /usr/local/lib)
message(STATUS "library path：${PROJECT_SOURCE_DIR}/lib")

SET(CMAKE_CXX_FLAGS "-g -Wall -Wextra -ffunction-sections -O3 -pthread -msse4.2")

add_definitions(--std=c++11)

AUX_SOURCE_DIRECTORY(./src APP_SRC)                        

add_executable(client ${APP_SRC})

target_link_libraries(client -Wl,--whole-archive
  pthread
  curl
  rt
  m
  z
  ssl
  crypto
  dl
  -Wl,--no-whole-archive)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
