//
// Created by Jean Barros Silva on 05/03/24.
//

#include <string.h>

#include "compiler.h"
#include "invalidation/invalidator.h"

// Returns an exit code if an error is found or NULL if the tokens are valid up until this point.
static const int *get_exit_code_for_error(Token *tokens, Token *previous_token) {
  const char *current_token_name = tokens == NULL ? NULL : strdup(tokens->name);
  if (is_initial_token_that_of_an_operation(previous_token, current_token_name)) {
    return &UNEXPECTED_OPERATION_TOKEN;
  }
  if (are_previous_and_current_token_numeric(previous_token, current_token_name)) {
    return &UNEXPECTED_NUMERIC_TOKEN;
  }
  return NULL;
}

int compile(Token *tokens) {
  Token *previous_token = malloc(sizeof(Token));
  int exit_code = 0;
  do {
    const int *error_exit_code = get_exit_code_for_error(tokens, previous_token);
    if (error_exit_code != NULL) {
      exit_code = *error_exit_code;
    }
    free((int *) error_exit_code);
    previous_token = tokens == NULL ? NULL : tokens++;
  } while (previous_token != NULL);
  free(previous_token);
  return exit_code;
}
