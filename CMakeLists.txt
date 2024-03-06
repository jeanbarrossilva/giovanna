add_executable(giovanna src/main.c
        src/lexing/tokenizer.h
        src/lexing/tokenizer.c
        src/lexing/generation/generator.h
        src/lexing/generation/generator.c
        src/lexing/token/addition.h
        src/lexing/token/addition.c
        src/lexing/token/subtraction.c
        src/lexing/token/subtraction.h
        src/lexing/token/numeric.c
        src/lexing/token/numeric.h
)
cmake_minimum_required(VERSION 3.27)
project(giovanna C)
set(CMAKE_C_STANDARD 23)
