cmake_minimum_required(VERSION 3.5.1)
project(cmake_protobuf)

# Find protobuf
find_package(Protobuf REQUIRED)
if (PROTOBUF_FOUND)
    message("protobuf found")
else ()
    message(FATAL_ERROR "Cannot find Protobuf")
endif ()

# Compile the .proto file into .cpp and .h file
set(PROTO_FILES proto/test.proto)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")

set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -ffunction-sections -O0")

add_executable(cmake_protobuf
        src/person.cpp
        src/main.cpp

        ${PROTO_SRCS}
        ${PROTO_HDRS})

# Include dependent
target_include_directories(${PROJECT_NAME}
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PUBLIC ${PROTOBUF_INCLUDE_DIRS})

# Library dependent
target_link_libraries(${PROJECT_NAME} ${PROTOBUF_LIBRARIES})
