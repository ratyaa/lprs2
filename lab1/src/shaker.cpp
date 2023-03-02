#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark shaker_benchmark(&shaker_sort, "data/shaker.csv");
    shaker_benchmark.run();

    return 0;
}
