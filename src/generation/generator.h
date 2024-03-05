//
// Created by Jean Barros Silva on 04/03/24.
//

#ifndef GIOVANNA_GENERATOR_H
#define GIOVANNA_GENERATOR_H

/*
 * Method that continues a generator execution chain, receiving the value with which the previous
 * continuation has been yielded.
 */
typedef void *Continuation(void *value);

/*
 * Promise-like structure whose continuation receives the return value of a previous continuation or
 * NULL if there was none prior to it. When it returns, its next generator's continuation is
 * executed.
 *
 * "Yielding" is extensively referred to in this documentation. Essentially, it just means returning
 * a value from a continuation for it to be passed into another from a generator that follows the
 * previous one in the execution chain.
 *
 *      -------------------              -----------------------------------------------------
 *     |                   |            |                                                     |
 *     |         1         |            |                          2                          |
 *     |     GENERATOR     | ---------> |                      GENERATOR                      |
 *     | Returns "Hello, " |            | Prints value from previous continuation + " world!" |
 *     |                   |            |                                                     |
 *      -------------------              -----------------------------------------------------
 *
 * In the example above, the first generator returns a string to the next, whose continuation will
 * be run and, in turn, prefix the message it prints with the value received from the previous one.
 * Actually chaining these generators would be implemented as something like this, and, at the end,
 * "Hello, world!\n" would get printed out:
 *
 * =================================================================================================
 *
 * void *hello() {
 *   return "Hello, ";
 * }
 *
 * void *generate_hello(Generator *next) {
 *   generate(hello, next);
 *   return NULL;
 * }
 *
 * void *world(void *value) {
 *   printf("%s world!\n", (char *) value);
 *   return NULL;
 * }
 *
 * int main() {
 *   use_generator(world, NULL, generate_hello);
 * }
 *
 * =================================================================================================
 */
typedef struct Generator {
  /*
   * Method to be invoked that receives the previously yielded value and continues the execution
   * chain, with the possibility of it yielding a value to be passed to the next generator's
   * continuation.
   */
  Continuation *continuation;

  // Generator that will be continued with the value returned by this one's continuation afterward.
  struct Generator *next;
} Generator;

// Method that uses a generator.
typedef void *Usage(Generator *generator);

/** Creates a generator that is passed into the given usage and is later deallocated. */
void use_generator(Continuation *continuation, Generator *next, Usage usage);

/*
 * Invokes the given continuation and runs the next generator's with the initially returned value,
 * doing the same for the nested ones it might point to until none is left in the execution chain.
 */
void generate(Continuation continuation, Generator *next);

#endif
