//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>
#include <stdlib.h>

#include "generator.h"

// Creates a generator.
static Generator *create_generator(Continuation *continuation, Generator *next) {
  Generator *generator = malloc(sizeof(Generator));
  generator->continuation = continuation;
  generator->next = (struct Generator *) next;
  return generator;
}

void use_generator(Continuation *continuation, Generator *next, Usage usage) {
  Generator *generator = create_generator(continuation, next);
  usage(generator);
  free(generator);
}

void generate(Continuation continuation, Generator *next) {
  Generator *current = create_generator(continuation, next);
  void *yielded = NULL;
  do {
    yielded = current->continuation(yielded);
    current = (Generator *) current->next;
  } while (current != NULL);
}
