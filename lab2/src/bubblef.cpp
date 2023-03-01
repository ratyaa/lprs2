#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark shaker_benchmark(&bubble_forward_sort, "data/bubblef.csv");
    shaker_benchmark.run();

    return 0;
}
