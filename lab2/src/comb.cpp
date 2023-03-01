#include "benchmark.hpp"
#include "sort_functions.hpp"

#include <iostream>

int main() {
    SortBenchmark comb_benchmark(&comb_sort, "data/comb.csv");
    comb_benchmark.run();

    return 0;
}
