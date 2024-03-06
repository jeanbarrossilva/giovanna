//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>

#include "numeric.h"
#include "subtraction.h"

// Value of a subtraction token.
static const char *SUBTRACTION_TOKEN_VALUE = "menos";

const char *SUBTRACTION_TOKEN_NAME = "subtraction";

/*
 * Creates a token that denotes that subtraction between a previously provided numeric value and the
 * next one should be performed.
 */
static Token *create_subtraction_token() {
  return create_token(SUBTRACTION_TOKEN_NAME, SUBTRACTION_TOKEN_VALUE, NUMERIC_TOKEN_NAME);
}

Token *maybe_tokenize_as_subtraction(char *value) {
  if (is(value, SUBTRACTION_TOKEN_VALUE)) {
    return create_subtraction_token();
  } else {
    return NULL;
  }
}
