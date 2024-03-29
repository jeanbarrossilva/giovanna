//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_SRC_LEXING_TOKEN_NUMERIC_H_
#define GIOVANNA_SRC_LEXING_TOKEN_NUMERIC_H_

// Name of a token whose value is a number.
static const char *NUMERIC_TOKEN_NAME = "numeric";

// Creates a numeric token with the given value if it is a match.
void *maybe_tokenize_as_numeric(char *value);

#endif
