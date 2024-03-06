//
// Created by Jean Barros Silva on 06/03/24.
//

#include "../lexing/token/numeric.h"
#include "invalidator.h"

bool is_initial_token_arithmetic(Token *previous_token, const char *current_token_name) {
  return previous_token == NULL && current_token_name != NUMERIC_TOKEN_NAME;
}

bool are_previous_and_current_token_numeric(Token *previous_token, const char *current_token_name) {
  return previous_token == NUMERIC_TOKEN_NAME && current_token_name == NUMERIC_TOKEN_NAME;
}

