#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark pair_sum_bruteforce_average_benchmark(
        &pairSumBruteForce, &fillWithNonegativeIntegerSequence,
        "data/pairsumbf_average.csv");
    pair_sum_bruteforce_average_benchmark.run();

    return 0;
}
