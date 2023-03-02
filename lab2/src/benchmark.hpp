#pragma once

#include "sort_functions.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

struct call_result
{
    unsigned array_length;
    double time_span;
    double swaps_amount;
};

struct benchmark_defaults
{
    static constexpr unsigned const &initial_array_length       = 1;
    static constexpr unsigned const &array_length_step          = 1;
    static constexpr unsigned const &iterations_per_call_amount = 10000;
    static constexpr unsigned const &calls_amount               = 100;
} static const benchmark_defaults;

class SortBenchmark {
    unsigned (*sort)(int *, unsigned const);

    static constexpr unsigned seed = 20602;

    unsigned initial_array_length;
    unsigned array_length_step;

    unsigned iterations_per_call_amount;
    unsigned calls_amount;

    char const *output_file_name;

    call_result call(unsigned const);
    unsigned safe_read_input(unsigned default_value);

  public:
    SortBenchmark(unsigned (*)(int *, unsigned const), char const *);
    SortBenchmark(unsigned (*)(int *, unsigned const), unsigned const,
                  unsigned const, unsigned const, unsigned const, char const *);

    void run();
};
