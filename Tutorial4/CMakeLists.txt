cmake_minimum_required(VERSION 3.16)

project(ROBOTAPP VERSION 2.3)

function(happynewyear arg1)
    message("ARG1 ${arg1}")#name fo variable
    message("ARG1 ${${arg1}}")#value of variable
    message("ARG1 ${ARGC}")
    message("ARG1 ${ARGN}")
    
endfunction()
set(var 2 0 2 2)
happynewyear(var)
