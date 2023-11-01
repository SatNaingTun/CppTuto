cmake_minimum_required(VERSION 3.22)

project(hello)
set(SRC_Files
    main.cpp message.cpp
)
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message("source files exist")
 else()
    message(FATAL_ERROR "source files not exist")
endif()

message("Compiling Source code at " ${CMAKE_SOURCE_DIR})
message(STATUS "Compiling your code" )
add_executable(output ${SRC_Files})

target_include_directories(output PUBLIC include)