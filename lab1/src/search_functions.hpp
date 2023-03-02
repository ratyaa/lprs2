#pragma once

#include <limits.h>

unsigned binarySearch(int *array, unsigned const array_length,
                      int const number);
unsigned bruteForceSearch(int *array, unsigned const array_length,
                          int const number);
unsigned pairSumBruteForce(int *array, unsigned const array_length,
                           int const number);
unsigned pairSumFast(int *array, unsigned const array_length, int const number);

void fillWithNonegativeIntegerSequence(int *array, unsigned const array_length);
void fillWithMinusOne(int *array, unsigned const array_length);
