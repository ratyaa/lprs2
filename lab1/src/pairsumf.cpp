#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark pair_sum_fast_benchmark(
        &pairSumFast, &fillWithNonegativeIntegerSequence, "data/pairsumf.csv");
    pair_sum_fast_benchmark.run();

    return 0;
}
