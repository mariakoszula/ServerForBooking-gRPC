cmake_minimum_required(VERSION 3.15)

project(ServerForBooking-gRPC)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -pedantic")


option(USE_SYSTEM_GRPC "Use system installed gRPC" ON)
if(USE_SYSTEM_GRPC)
  find_package(protobuf CONFIG REQUIRED)
  find_package(gRPC CONFIG REQUIRED)
else()
include(FetchContent)
    FetchContent_Declare(
    gRPC
    GIT_REPOSITORY https://github.com/grpc/grpc
    GIT_TAG        v1.47.5
    )
    set(FETCHCONTENT_QUIET OFF)
    FetchContent_MakeAvailable(gRPC)
endif()

add_library(booking_service_proto_lib booking_service.proto)
target_link_libraries(booking_service_proto_lib PUBLIC gRPC::grpc gRPC::grpc++ protobuf::libprotobuf)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET booking_service_proto_lib LANGUAGE cpp)
protobuf_generate(TARGET booking_service_proto_lib LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
