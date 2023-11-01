cmake_minimum_required(VERSION 3.16)

project(ROBOTAPP VERSION 2.3)

set(PRODUCT_YEAR "2022")

if(DEBUG)
    set(AUTHOR "Sat Naing Tun")
endif()

configure_file(defaultconfig.h.in defaultconfig.h)

add_executable(hellobot src/main.cpp)
target_include_directories(hellobot PUBLIC ${PROJECT_BINARY_DIR})

foreach(f IN ITEMS R O M R O B O T I C S)
    message(STATUS ${f})
endforeach()
  
set(DEVELOPER S A T N A I N G T U N)
foreach(G IN LISTS DEVELOPER)
   message(STATUS ${G})    
endforeach()

set(VAR 10)
while(VAR)
    message(${VAR})
    message(EXPR VAR "${VAR}-1")    
endwhile()


