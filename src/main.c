//
// Created by Jean Barros Silva on 04/03/24.
//

#include "compiling/compiler.h"
#include "compiling/lexing/tokenizer.h"

int main() {
  Token *tokens = tokenize("2 mais 1");
  int exit_code = compile(tokens);
  free(tokens);
  return exit_code;
}
