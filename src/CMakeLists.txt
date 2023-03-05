set(BINARY_NAME ${CMAKE_PROJECT_NAME})

option(USE_SYSTEM_GRPC "Use system installed gRPC" ON)
if(USE_SYSTEM_GRPC)
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
set(SOURCES main.cpp BookingService.cpp)

add_executable(${BINARY_NAME}_run ${SOURCES})
add_library(${BINARY_NAME}_lib STATIC ${SOURCES})