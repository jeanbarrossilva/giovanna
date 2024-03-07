//
// Created by Jean Barros Silva on 06/03/24.
//

#include "../lexing/tokenizer.h"

#ifndef GIOVANNA_SRC_COMPILING_INVALIDATION_CHECKER_H_
#define GIOVANNA_SRC_COMPILING_INVALIDATION_CHECKER_H_

// Checks whether the script starts with either an addition or subtraction token.
bool is_initial_token_that_of_an_operation(Token *previous_token, const char *current_token_name);

// Checks whether both the previous and the current token are numeric.
bool are_previous_and_current_token_numeric(Token *previous_token, const char *current_token_name);

#endif
