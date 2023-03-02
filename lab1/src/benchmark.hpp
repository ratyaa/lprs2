#pragma once

#include "search_functions.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

struct call_result
{
    unsigned array_length;
    double time_span;
};

struct benchmark_defaults
{
    static constexpr unsigned const &initial_array_length       = 1;
    static constexpr unsigned const &array_length_step          = 1;
    static constexpr unsigned const &iterations_per_call_amount = 10000;
    static constexpr unsigned const &calls_amount               = 5000;
} static const benchmark_defaults;

class SearchBenchmark {
    unsigned (*search)(int *, unsigned const, int const);
    void (*fill)(int *, unsigned const);

    static constexpr unsigned seed = 20602;

    unsigned initial_array_length;
    unsigned array_length_step;

    unsigned iterations_per_call_amount;
    unsigned calls_amount;

    char const *output_file_name;

    call_result call(unsigned const);
    unsigned safe_read_input(unsigned const);

  public:
    SearchBenchmark(unsigned (*)(int *, unsigned const, int const),
                    void (*)(int *, unsigned const), char const *);

    void run();
};
