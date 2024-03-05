//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>
#include <stdlib.h>

#include "generator.h"

void use_generator(Continuation *continuation, Generator *next, Usage usage) {
  Generator *generator = malloc(sizeof(Generator));
  generator->continuation = continuation;
  generator->next = (struct Generator *) next;
  usage(generator);
  free(generator);
}

void generate(Continuation continuation, Generator *next) {
  Generator *current = malloc(sizeof(Generator));
  current->continuation = continuation;
  current->next = (struct Generator *) next;
  void *yielded = NULL;
  do {
    yielded = current->continuation(yielded);
    current = (Generator *) current->next;
  } while (current != NULL);
}
