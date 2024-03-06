//
// Created by Jean Barros Silva on 04/03/24.
//

#include "../tokenizer.h"

#ifndef GIOVANNA_SRC_LEXING_TOKEN_NUMERIC_H_
#define GIOVANNA_SRC_LEXING_TOKEN_NUMERIC_H_

// Name of a token whose value is a number.
const char *NUMERIC_TOKEN_NAME;

// Creates a numeric token with the given value if it is a match.
Token *maybe_tokenize_as_numeric(char *value);

#endif
