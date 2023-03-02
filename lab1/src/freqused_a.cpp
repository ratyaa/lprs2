#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark freqUsed_A_benchmark(
        &bruteForceSearch, &fillWithNonegativeIntegerSequence,
        &freqUsed_A_permutate, "data/freqused_a.csv");
    freqUsed_A_benchmark.run();

    return 0;
}
