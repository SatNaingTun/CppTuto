#File
FILE(READ "src/main.cpp" MAIN_text)
message("${MAIN_text}")
message(("--------------------"))

FILE(STRINGS "src/main.cpp" MAIN_text)
message("${MAIN_text}")
message(("--------------------"))

FILE(STRINGS "src/main.cpp" MAIN_text REGEX) 
message("${MAIN_text}")
message(("--------------------"))

FILE(READ "src/main.cpp" MAIN_text)
message(REGEX_REPLACE "int"  "void" OUT ${MAIN_text})
message("${OUT}")
message(("--------------------"))

set(globalvariable 10)
macro(funname x)
    message("${x}")
    message("${${x}}")
    set(globalvariable 15)    
endmacro()

message("${globalvariable}")
funname(globalvariable)
message("${globalvariable}")
message(("--------------------"))

set(globalvariable 10)
function(funname x)
    message("${x}")
    message("${${x}}")
    set(globalvariable 15)  
endfunction()

message("${globalvariable}")
funname(globalvariable)
message("${globalvariable}")
message(("--------------------"))

set(globalvariable 10)
function(funname x)
    message("${x}")
    message("${${x}}")
    set(globalvariable 15 PARENT_SCOPE)  
endfunction()

message("${globalvariable}")
funname(globalvariable)
message("${globalvariable}")
message(("--------------------"))