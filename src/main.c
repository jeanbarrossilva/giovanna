//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>

#include "generation/generator.h"

void *hello() {
  printf("Hello, ");
  return NULL;
}

void *generateHello(Generator *next) {
  generate(hello, next);
  return NULL;
}

void *world() {
  printf("world!\n");
  return NULL;
}

int main() {
  use_generator(world, NULL, generateHello);
  return 0;
}
