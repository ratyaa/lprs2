#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark binary_worst_benchmark(&binarySearch, &fillWithMinusOne,
                                           "data/binary_worst.csv");
    binary_worst_benchmark.run();

    return 0;
}
