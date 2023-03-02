#pragma once

#include <limits.h>

static constexpr int const &not_found_code = -1;

void swap(int *, unsigned const, unsigned const);

int binarySearch(int *, unsigned const, int const);
int bruteForceSearch(int *, unsigned const, int const);

int pairSumBruteForce(int *, unsigned const, int const);
int pairSumFast(int *, unsigned const, int const);

void fillWithNonegativeIntegerSequence(int *, unsigned const);
void fillWithMinusOne(int *, unsigned const);
void fillWithZeros(int *, unsigned const);

void dummy_permutate(int *, int *, int const);
void freqUsed_A_permutate(int *, int *, int const);
void freqUsed_B_permutate(int *, int *, int const);
void freqUsed_C_permutate(int *, int *, int const);
