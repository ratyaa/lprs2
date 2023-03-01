#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark bubble_backward_benchmark(&bubble_backward_sort,
                                            "data/bubbleb.csv");
    bubble_backward_benchmark.run();

    return 0;
}
