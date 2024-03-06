add_executable(giovanna src/main.c
        src/lexing/tokenizer.c
        src/lexing/tokenizer.h
        src/lexing/token/addition.c
        src/lexing/token/addition.h
        src/lexing/token/numeric.c
        src/lexing/token/numeric.h
        src/lexing/token/subtraction.c
        src/lexing/token/subtraction.h
)
cmake_minimum_required(VERSION 3.27)
project(giovanna C)
set(CMAKE_C_STANDARD 23)
