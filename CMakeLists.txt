add_executable(giovanna src/main.c
        src/compiling/compiler.c
        src/compiling/compiler.h
        src/compiling/invalidation/invalidator.c
        src/compiling/invalidation/invalidator.h
        src/compiling/lexing/tokenizer.c
        src/compiling/lexing/tokenizer.h
        src/compiling/lexing/token/addition.c
        src/compiling/lexing/token/addition.h
        src/compiling/lexing/token/numeric.c
        src/compiling/lexing/token/numeric.h
        src/compiling/lexing/token/subtraction.c
        src/compiling/lexing/token/subtraction.h
)
cmake_minimum_required(VERSION 3.27)
project(giovanna C)
set(CMAKE_C_STANDARD 23)
