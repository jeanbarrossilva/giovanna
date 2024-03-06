//
// Created by Jean Barros Silva on 04/03/24.
//

#include "lexing/tokenizer.h"

int main() {
  Token *tokens = tokenize("2 mais 1");
  free(tokens);
}
