cmake_minimum_required(VERSION "3.6")
project(miniProject)
set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
#include(CTest)
include_directories("${CMAKE_SOURCE_DIR}/src")
#add_subdirectory("${CMAKE_SOURCE_DIR}/tests")        # for GMockCatchListener.h

set(VENDOR_SOURCE_DIR "${CMAKE_SOURCE_DIR}/thirdparty")

## google test configuration
#add_subdirectory("${VENDOR_SOURCE_DIR}/googletest")
#include_directories("${VENDOR_SOURCE_DIR}/googletest/googletest/include")


set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(main ${SOURCES})

