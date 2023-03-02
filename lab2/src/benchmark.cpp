#include "benchmark.hpp"

call_result SortBenchmark::call(unsigned const array_length) {
    int *array = new int[array_length];

    call_result result;
    result.swaps_amount = 0;

    std::default_random_engine rng(seed);
    std::uniform_int_distribution<int> dstr((-array_length + array_length / 2),
                                            (array_length / 2));

    auto begin = std::chrono::steady_clock::now();

    for (unsigned _ = 0; _ < iterations_per_call_amount; _++) {
        fillWithRandomIntegers(array, array_length, &dstr, &rng);
        result.swaps_amount += sort(array, array_length);
    }

    auto end = std::chrono::steady_clock::now();
    auto time_span =
        std::chrono::duration_cast<std::chrono::microseconds>(end - begin)
            .count();

    result.array_length = array_length;
    result.time_span    = (double)(time_span) / iterations_per_call_amount;
    result.swaps_amount = result.swaps_amount / iterations_per_call_amount;

    delete[] array;

    return result;
}

void SortBenchmark::run() {
    unsigned array_length = initial_array_length;
    call_result results[calls_amount];
    std::ofstream output_file(output_file_name, std::ofstream::trunc);

    for (auto row = 0; row < calls_amount; row++) {
        std::cout << "Call number " << row + 1 << std::endl;

        results[row] = call(array_length);

        array_length += array_length_step;
    }

    std::cout << output_file_name << std::endl;

    for (auto &row : results)
        output_file << row.array_length << ',' << row.time_span << ','
                    << row.swaps_amount << '\n';
}

unsigned SortBenchmark::safe_read_input(unsigned default_value) {
    unsigned result;

    if (std::cin.get() == '\n')
        result = default_value;
    else {
        std::cin.unget();
        std::cin >> result;
        std::cin.get();

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            result = default_value;
        }
    }

    return result;
}

SortBenchmark::SortBenchmark(unsigned (*sort)(int *, unsigned const),
                             unsigned const initial_array_length,
                             unsigned const array_length_step,
                             unsigned const iterations_per_call_amount,
                             unsigned const calls_amount,
                             char const *output_file_name)
    : initial_array_length(initial_array_length),
      array_length_step(array_length_step),
      iterations_per_call_amount(iterations_per_call_amount),
      calls_amount(calls_amount), output_file_name(output_file_name) {}

SortBenchmark::SortBenchmark(unsigned (*sort)(int *, unsigned const),
                             char const *output_file_name)
    : sort(sort), output_file_name(output_file_name) {
    std::cout << "Enter initial array length (default is "
              << benchmark_defaults.initial_array_length << "): ";
    this->initial_array_length =
        safe_read_input(benchmark_defaults.initial_array_length);

    std::cout << "Enter array length step (default is "
              << benchmark_defaults.array_length_step << "): ";
    this->array_length_step =
        safe_read_input(benchmark_defaults.array_length_step);

    std::cout << "Enter amount of iterations per benchmark call (default is "
              << benchmark_defaults.iterations_per_call_amount << "): ";
    this->iterations_per_call_amount =
        safe_read_input(benchmark_defaults.iterations_per_call_amount);

    std::cout << "Enter amount of benchmark calls (default is "
              << benchmark_defaults.calls_amount << "): ";
    this->calls_amount = safe_read_input(benchmark_defaults.calls_amount);
}
