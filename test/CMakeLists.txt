set(TEST_BINARY_NAME ${CMAKE_PROJECT_NAME}_test)

enable_testing()

option(USE_SYSTEM_GOOGLETEST "Use system installed googletest" ON)
if(USE_SYSTEM_GOOGLETEST)
    find_package(GTest CONFIG REQUIRED)
else()
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
endif()

set(SOURCES main.cpp test_BookingService.cpp test_InMemoryDatabase.cpp)

add_executable(${TEST_BINARY_NAME} ${SOURCES})
target_link_libraries(${TEST_BINARY_NAME} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest gmock booking_service_proto_lib)

include(GoogleTest)
gtest_discover_tests(${TEST_BINARY_NAME})