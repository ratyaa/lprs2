#pragma once

#include <limits.h>

unsigned binarySearch(int const *array, unsigned const array_length,
                      int const number);
unsigned bruteForceSearch(int const *array, unsigned const array_length,
                          int const number);

void fillWithNonegativeIntegerSequence(int *array, unsigned const array_length);
void fillWithMinusOne(int *array, unsigned const array_length);
