//
// Created by Jean Barros Silva on 04/03/24.
//

#include <string.h>

#include "tokenizer.h"
#include "token/addition.h"
#include "token/numeric.h"
#include "token/subtraction.h"

// Amount of tokens that are recognizable by giovanna.
static const short TOKEN_COUNT = 3;

// String that indicates the end of a token and possibly the beginning of another one.
static const char *DELIMITER = " ";

// Counts the amount of times a value that may be that of a token appears in the string.
static unsigned long count_potential_token_values(const char *string) {
  int delimiter_index, delimiter_count;
  for (delimiter_index = 0, delimiter_count = 0; string[delimiter_index]; delimiter_index++) {
    delimiter_count += (string[delimiter_index] == *DELIMITER);
  }
  return delimiter_count + 1;
}

// Creates a token that best suits the given delimited value extracted from an expression.
static Token *tokenize_value(char *value) {
  void **strategies = malloc(sizeof(Token *) * TOKEN_COUNT);
  strategies[0] = maybe_tokenize_as_addition(value);
  strategies[1] = maybe_tokenize_as_numeric(value);
  strategies[2] = maybe_tokenize_as_subtraction(value);
  Token *token;
  while (*strategies && token == NULL) {
    token = *strategies++;
  }
  return token;
}

bool is(const char *first, const char *second) {
  return strcmp(first, second) == 0;
}

Token *create_token(const char *name, const char *value, const char *next) {
  Token *token = malloc(sizeof(Token));
  token->name = name;
  token->value = value;
  token->next = next;
  return token;
}

Token *tokenize(char *expression) {
  char *_expression = strdup(expression);
  char *value = NULL;
  Token *tokens = malloc(sizeof(Token) * count_potential_token_values(expression));
  unsigned long index = 0;
  while ((value = strsep(&_expression, DELIMITER))) {
    Token *token = tokenize_value(value);
    tokens[index++] = *token;
  }
  free(value);
  free(_expression);
  return tokens;
}
