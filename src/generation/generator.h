//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_GENERATOR_H
#define GIOVANNA_GENERATOR_H

/*
 * Method that continues a generator execution chain, receiving the value with which the previous
 * continuation has been value.
 */
typedef void *Continuation(void *value);

/*
 * Promise-like structure whose continuation receives the return value of a previous continuation or
 * NULL if there was none prior to it. When it finishes generating, its next generator's
 * continuation is executed.
 *
 * "Yielding" is extensively referred to in this documentation. Essentially, it just means returning
 * a value from a continuation for it to be passed into another from a generator that follows the
 * first's in the execution chain.
 *
 *          -------------------              ---------------------------------------------
 *         |                   |            |                                             |
 *         |         1         |            |                      2                      |
 *         |     GENERATOR     | =========> |                  GENERATOR                  |
 *         | Returns "Hello, " |            | Prints previously yielded value + " world!" |
 *         |                   |            |                                             |
 *          -------------------              ---------------------------------------------
 *
 * In the example above, the first generator returns a string to the next whose continuation will be
 * run, which, in turn, prefixes the message it prints with the value received from the previous
 * one.
 */
typedef struct Generator {
  /*
   * Method to be invoked that receives the previously yielded value and continues the execution
   * chain, with the possibility of it yielding a value to be passed to the next generator's
   * continuation.
   */
  Continuation *continuation;

  /*
   * Generator that will be continued afterward, into whose continuation this one's yielded value
   * will be passed.
   */
  struct Generator *next;
} Generator;

/* Method that uses a generator. */
typedef void *Usage(Generator *generator);

/** Creates a generator that is passed into the given usage and is later deallocated. */
void use_generator(Continuation *continuation, Generator *next, Usage usage);

/*
 * Invokes the given continuation and runs the next generator with the initially yielded value,
 * doing the same for the nested ones it might point to until none is found in the execution chain.
 */
void generate(Continuation continuation, Generator *next);

#endif
