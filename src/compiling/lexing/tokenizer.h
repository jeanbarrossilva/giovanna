//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdbool.h>
#include <stdlib.h>

#ifndef GIOVANNA_SRC_TOKENIZER_H_
#define GIOVANNA_SRC_TOKENIZER_H_

// Contextualized whitespace-split string to which meaning is attributed within a giovanna script.
typedef struct {
  // Identifies this token for intelligible error messages.
  const char *name;

  // Keyword or value that has been input.
  const char *value;

  // Names of the token that can succeed this one.
  const char *next;
} Token;

// Whether both strings are structurally equal.
bool is(const char *first, const char *second);

// Creates a token.
Token *create_token(const char *name, const char *value, const char *next);

// Extracts the tokens contained in the expression.
Token *tokenize(char *expression);

#endif
