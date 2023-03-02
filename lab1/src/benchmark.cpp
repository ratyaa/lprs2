#include "benchmark.hpp"

call_result SearchBenchmark::call(unsigned const array_length) {
    int *array = new int[array_length];
    int number;

    call_result result;

    std::default_random_engine rng(seed);
    std::uniform_int_distribution<int> dstr(0, array_length);

    auto begin = std::chrono::steady_clock::now();

    for (unsigned _ = 0; _ < iterations_per_call_amount; _++) {
        number = dstr(rng);
        fill(array, array_length);
        search(array, array_length, number);
    }

    auto end = std::chrono::steady_clock::now();
    auto time_span =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin)
            .count();

    result.array_length = array_length;
    result.time_span    = (double)(time_span) / iterations_per_call_amount;

    delete[] array;

    return result;
}

void SearchBenchmark::run() {
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
        output_file << row.array_length << ',' << row.time_span << '\n';
}

unsigned SearchBenchmark::safe_read_input(unsigned const default_value) {
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

SearchBenchmark::SearchBenchmark(unsigned (*search)(int const *, unsigned const,
                                                    int const),
                                 void (*fill)(int *, unsigned const),
                                 char const *output_file_name)
    : search(search), fill(fill), output_file_name(output_file_name) {
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
