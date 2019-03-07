cmake_minimum_required(VERSION 3.5.1)

# build libmul.a
add_library(mul STATIC mul.cpp)
target_link_libraries(mul add)

add_subdirectory(add)
