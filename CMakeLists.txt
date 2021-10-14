cmake_minimum_required(VERSION 3.0)
set(PROJECT_NAME http2-server-sample)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_FILENAME_SUFFIX ${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})

include_directories(./lib/boost_1_77_0)
include_directories(./lib/nghttp2-1.45.1)

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#set(Boost_INCLUDE_DIR ~/boost)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(Boost REQUIRED COMPONENTS thread)
find_package(Boost REQUIRED COMPONENTS log)
find_package(OpenSSL REQUIRED)

set(NGHTTP2_SRC_DIR lib/nghttp2-1.45.1)
set(ENABLE_ASIO_LIB ON)
add_subdirectory(${NGHTTP2_SRC_DIR})

add_subdirectory(src)
