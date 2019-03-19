cmake_minimum_required(VERSION "3.6")
project(miniProject)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#include_directories(${PROJECT_SOURCE_DIR})



#set(SOURCE_FILES /src/main.cpp)

#add_library(Mymathlib STATIC ${SOURCE_FILES})

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/Myproject.cpp)
add_executable(main ${SOURCES})

#dd_executable(main .cpp)
#TARGET_LINK_LIBRARIES(main Mymathlib)



find_package(Boost REQUIRED COMPONENTS serialization)
IF (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
message("BOOST FOUND")
message(${Boost_INCLUDE_DIR})
endif()

target_link_libraries(main PUBLIC ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS} /archive)

#file(GLOB_RECURSE SOURCES *.cpp)



#file(GLOB_RECURSE source *.cpp)

#add_executable(main source.cpp)
#add_executable(main2 main2.cpp)
#add_executable(main3 main3.cpp)


#target_compile_definitions(main PRIVATE FRENCH)

