cmake_minimum_required(VERSION 2.8)

project(HelloWorld)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find Protobuf
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Protobuf REQUIRED)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
message(STATUS "Using protobuf ${protobuf_VERSION}")

# Find gRPC
find_package(GRPC REQUIRED)
set(_GRPC_GRPCPP_REFLECTION gRPC::grpc++_reflection)
message(STATUS "Using gRPC ${gRPC_VERSION}")

# Proto file
message(STATUS "CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
set(hw_proto ${CMAKE_CURRENT_SOURCE_DIR}/protos/helloworld.proto)

set(PROTO_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/proto-src)
file(MAKE_DIRECTORY ${PROTO_SRC_DIR})

# Include generated *.pb.h files
include_directories(${PROTO_SRC_DIR})

# Generated sources
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SRC_DIR} ${hw_proto})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${hw_proto})

# Targets greeter_(client|server)
foreach(_target
  greeter_client greeter_server)
  add_executable(${_target} "${CMAKE_CURRENT_LIST_DIR}/src/${_target}.cc"
    ${PROTO_SRCS}
    ${GRPC_SRCS})
  target_link_libraries(${_target}
    ${_GRPC_GRPCPP_REFLECTION}
    ${_PROTOBUF_LIBPROTOBUF})
endforeach()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
