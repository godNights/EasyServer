cmake_minimum_required(VERSION 2.8...3.13)

set(PBSRCS
    ../proto/Login.pb.cc)

set(SRCS
    main.cpp)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(../proto/)
add_executable(EasyServer ${SRCS} ${PBSRCS})



target_link_libraries(EasyServer ${Protobuf_LIBRARIES})

