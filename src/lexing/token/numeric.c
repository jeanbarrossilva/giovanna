//
// Created by Jean Barros Silva on 04/03/24.
//

#include <ctype.h>
#include <stdbool.h>

#include "../tokenizer.h"
#include "addition.h"
#include "numeric.h"
#include "subtraction.h"

static const char *NUMERIC_TOKEN_NAME = "numeric";

// Whether all characters within the string are numeric. Returns false if it is empty.
static bool is_numeric(char *string) {
  while (*string) {
    if (isdigit(*string++)) {
      return true;
    }
  }
  return false;
}

// Creates a token for a numeric value.
static Token *create_numeric_token(const char *value) {
  char *next = malloc(sizeof(char) * 19);
  next[0] = *ADDITION_TOKEN_NAME;
  next[1] = *SUBTRACTION_TOKEN_NAME;
  return create_token(NUMERIC_TOKEN_NAME, value, next);
}

void *maybe_tokenize_as_numeric(char *value) {
  if (is_numeric(value)) {
    return create_numeric_token(value);
  } else {
    return NULL;
  }
}
