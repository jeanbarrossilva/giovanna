//
// Created by Jean Barros Silva on 05/03/24.
//

#include "lexing/tokenizer.h"

#ifndef GIOVANNA_SRC_COMPILING_COMPILER_H_
#define GIOVANNA_SRC_COMPILING_COMPILER_H_

/*
 * Exit code that indicates that a numeric token has been provided when either an addition or
 * subtraction one was expected.
 */
static const int UNEXPECTED_NUMERIC_TOKEN = -1;

/*
 * Exit code that indicates that either an addition or subtraction token has been provided when a
 * numeric one was expected.
 */
static const int UNEXPECTED_OPERATION_TOKEN = -2;

// Compiles a giovanna script.
int compile(Token *tokens);

#endif
