#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark bruteforce_average_benchmark(
        &bruteForceSearch, &fillWithNonegativeIntegerSequence,
        "data/bruteforce_average.csv");
    bruteforce_average_benchmark.run();

    return 0;
}
