cmake_minimum_required(VERSION 3.15)

project(ServerForBooking-gRPC)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -pedantic")

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
