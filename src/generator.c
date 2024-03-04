//
// Created by Jean Barros Silva on 04/03/24.
//

#include <stdio.h>
#include <stdlib.h>

#include "generator.h"

void use_generator(Generation *current, Generator *next, Usage usage) {
  Generator * generator = malloc(sizeof(Generator));
  generator->current = current;
  generator->next = (struct Generator *) next;
  usage(generator);
  free(generator);
}

void generate(Generation generation, Generator *next) {
  Generator * current = malloc(sizeof(Generator));
  current->current = generation;
  current->next = (struct Generator *) next;
  void * last_return = NULL;
  do {
    last_return = current->current(last_return);
    current = (Generator *) current->next;
  } while(current != NULL);
}
