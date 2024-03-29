//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_SRC_LEXING_TOKEN_SUBTRACTION_H_
#define GIOVANNA_SRC_LEXING_TOKEN_SUBTRACTION_H_

// Name of a subtraction token.
static const char *SUBTRACTION_TOKEN_NAME = "subtraction";

// Creates a subtraction token with the given value if it is a match.
void *maybe_tokenize_as_subtraction(char *value);

#endif
