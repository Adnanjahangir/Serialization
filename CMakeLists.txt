cmake_minimum_required(VERSION "3.6")
project(miniProject)


include_directories(${PROJECT_SOURCE_DIR}/src)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
add_executable(main ${SOURCES})


