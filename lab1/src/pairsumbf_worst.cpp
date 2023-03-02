#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark pair_sum_bruteforce_worst_benchmark(
        &pairSumBruteForce, &fillWithMinusOne, "data/pairsumbf_worst.csv");
    pair_sum_bruteforce_worst_benchmark.run();

    return 0;
}
