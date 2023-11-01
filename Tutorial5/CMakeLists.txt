cmake_minimum_required(VERSION 3.16)

project(ROBOTAPP VERSION 2.3)

set(PRODUCT_YEAR 2023)

configure_file(defaultconfig.h.in defaultconfig.h)

add_executable(hellobot src/main.cpp)

target_include_directories(hellobot PUBLIC  ${PROJECT_BINARY_DIR})

target_compile_definitions(hellobot PUBLIC "STD_CXX=17")
target_compile_options(hellobot PUBLIC -march=native)

install(FILES "${PROJECT_BINARY_DIR}/hellobot"
DESTINATION "${PROJECT_BINARY_DIR}/executable"
)
