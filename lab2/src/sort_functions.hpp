#pragma once

#include <random>

void swap(int *, unsigned const, unsigned const);
void fillWithRandomIntegers(int *, unsigned const,
                            std::uniform_int_distribution<int> *,
                            std::default_random_engine *);

unsigned forward_step(int *, unsigned const, unsigned const);
unsigned backward_step(int *, unsigned const, unsigned const);

unsigned shaker_sort(int *, unsigned const);
unsigned bubble_forward_sort(int *, unsigned const);
unsigned bubble_backward_sort(int *, unsigned const);
