cmake_minimum_required(VERSION 2.8...3.13)

project(EasyServer CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O0")

add_subdirectory(src)
add_subdirectory(stressTest)