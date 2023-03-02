#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark freqUsed_C_benchmark(
        &bruteForceSearch, &fillWithNonegativeIntegerSequence,
        &freqUsed_C_permutate, "data/freqused_c.csv");
    freqUsed_C_benchmark.run();

    return 0;
}
