cmake_minimum_required(VERSION "3.6")
set(VENDOR_SOURCE_DIR "${CMAKE_BINARY_DIR}/thirdparty")

## google test configuration
#add_subdirectory("${VENDOR_SOURCE_DIR}/googletest")
include_directories("${VENDOR_SOURCE_DIR}/googletest/googletest/include")
add_executable(test main.cpp)
target_link_libraries(test gtest)
