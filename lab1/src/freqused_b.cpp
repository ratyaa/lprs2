#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark freqUsed_B_benchmark(
        &bruteForceSearch, &fillWithNonegativeIntegerSequence,
        &freqUsed_B_permutate, "data/freqused_b.csv");
    freqUsed_B_benchmark.run();

    return 0;
}
