#include "benchmark.hpp"
#include "search_functions.hpp"

int main() {
    SearchBenchmark bruteforce_average_benchmark(
        &bruteForceSearch, &fillWithMinusOne, "data/bruteforce_worst.csv");
    bruteforce_average_benchmark.run();

    return 0;
}
