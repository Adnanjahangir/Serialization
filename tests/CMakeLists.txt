cmake_minimum_required(VERSION "3.6")
set(VENDOR_SOURCE_DIR "${CMAKE_BINARY_DIR}/thirdparty")

enable_testing()


include_directories("${VENDOR_SOURCE_DIR}/googletest/googletest/include")
add_executable(test_all tests.cpp)
target_link_libraries(test_all gtest)

add_test(
    NAME AllTests
    COMMAND test_all
)