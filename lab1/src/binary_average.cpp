#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark binary_average_benchmark(&binarySearch,
                                             &fillWithNonegativeIntegerSequence,
                                             "data/binary_average.csv");
    binary_average_benchmark.run();

    return 0;
}
