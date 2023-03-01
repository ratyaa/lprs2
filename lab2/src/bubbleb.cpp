#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark shaker_benchmark(&bubble_backward_sort, "data/bubbleb.csv");
    shaker_benchmark.run();

    return 0;
}
