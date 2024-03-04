//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_GENERATOR_H
#define GIOVANNA_GENERATOR_H

/* Method that generates a return value based on the one resulted from a previous generation. */
typedef void *Generation(void *returned);

/*
 * Promise-like structure whose generation receives the return value of a previous generation or
 * NULL if there was none prior to it. When it finishes generating, its next generation is executed.
 */
typedef struct {
  /*
   * Method to be invoked that receives the return value of the previous Generator's and generates
   * another for the next Generator.
   */
  Generation *current;

  /*
   * Method to be run after the current one, into whose current this one's return value will be
   * passed.
   */
  struct Generator *next;
} Generator;

/* Method that uses a generator. */
typedef void *Usage(Generator *generator);

/** Creates a generator that is passed into the given usage and is later deallocated. */
void use_generator(Generation *current, Generator *next, Usage usage);

/*
 * Invokes the given method and runs the generator with the resulting return value, doing the same
 * for the nested ones it might contain until none is found in the chain.
 */
void generate(Generation generation, Generator *next);
#endif
