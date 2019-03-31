cmake_minimum_required(VERSION "3.6")
set(VENDOR_SOURCE_DIR "${CMAKE_BINARY_DIR}/thirdparty")
#set(CMAKE_XCODE_GENERATE_SCHEME ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON)
enable_testing()
 

set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
#set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
#set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")


include_directories("${VENDOR_SOURCE_DIR}/googletest/googletest/include")
add_executable(test_all tests.cpp)
target_link_libraries(test_all gtest)

add_test(
    NAME AllTests
    COMMAND test_all
)