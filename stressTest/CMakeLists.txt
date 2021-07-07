cmake_minimum_required(VERSION 2.8...3.13)

set(PBSRCS
    ../proto/testBuffer.pb.cc)

set(SRCS
    StressTest.cpp
    ../base/public.cpp
    main.cpp)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(../proto/)
include_directories(../base/)
add_executable(StressTest ${SRCS} ${PBSRCS})

target_link_libraries(StressTest ${Protobuf_LIBRARIES})

