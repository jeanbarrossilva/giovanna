//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_SRC_LEXING_TOKEN_ADDITION_H_
#define GIOVANNA_SRC_LEXING_TOKEN_ADDITION_H_

// Name of an addition token.
static const char *ADDITION_TOKEN_NAME;

// Creates an addition token with the given value if it is a match.
void *maybe_tokenize_as_addition(char *value);

#endif
