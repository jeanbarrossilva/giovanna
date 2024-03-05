//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>

#include "generation/generator.h"

void *hello() {
  return "Hello";
}

void *generate_hello(Generator *next) {
  generate(hello, next);
  return NULL;
}

void *world(void *value) {
  printf("%s, world!\n", (char *) value);
  return NULL;
}

int main() {
  use_generator(world, NULL, generate_hello);
}
