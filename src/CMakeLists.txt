set(BINARY_NAME ${CMAKE_PROJECT_NAME})

set(SOURCES main.cpp BookingService.cpp)

add_executable(${BINARY_NAME}_run ${SOURCES})
add_library(${BINARY_NAME}_lib STATIC ${SOURCES})
target_link_libraries(${BINARY_NAME}_run booking_service_proto_lib)