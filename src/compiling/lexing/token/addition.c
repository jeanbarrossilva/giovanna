//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>

#include "../tokenizer.h"
#include "addition.h"
#include "numeric.h"

// Value of an addition token.
static const char *ADDITION_TOKEN_VALUE = "mais";

/*
 * Creates a token that denotes that addition between a previously provided numeric value and the
 * next one should be performed.
 */
static Token *create_addition_token() {
  return create_token(ADDITION_TOKEN_NAME, ADDITION_TOKEN_VALUE, NUMERIC_TOKEN_NAME);
}

void *maybe_tokenize_as_addition(char *value) {
  if (is(value, ADDITION_TOKEN_VALUE)) {
    return create_addition_token();
  } else {
    return NULL;
  }
}
