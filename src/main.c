//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>

#include "generator.h"

void * hello() {
  printf("Hello, ");
  return 0;
}

void * generateHello(Generator * next) {
  generate(hello, next);
  return NULL;
}

void * world() {
  printf("world!\n");
  return NULL;
}

int main() {
  use_generator(world, NULL, generateHello);
  return 0;
}