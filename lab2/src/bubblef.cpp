#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark bubble_forward_benchmark(&bubble_forward_sort,
                                           "data/bubblef.csv");
    bubble_forward_benchmark.run();

    return 0;
}
