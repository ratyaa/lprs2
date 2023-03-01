#include "sort_functions.hpp"

void swap(int *array, unsigned const first, unsigned const second) {
    array[first] += array[second];
    array[second] = array[first] - array[second];
    array[first]  = array[first] - array[second];
}

void fillWithRandomIntegers(int *array, unsigned const array_length,
                            std::uniform_int_distribution<int> *dstr,
                            std::default_random_engine *rng) {
    for (unsigned i = 0; i < array_length; i++)
        array[i] = (*dstr).operator()(*rng);
}

unsigned forward_step(int *array, unsigned const begin_idx,
                      unsigned const end_idx) {
    unsigned swaps_amount = 0;

    for (unsigned i = begin_idx; i < end_idx; i++)
        if (array[i] > array[i + 1]) {
            swap(array, i, i + 1);
            swaps_amount++;
        }

    return swaps_amount;
}

unsigned backward_step(int *array, unsigned const begin_idx,
                       unsigned const end_idx) {
    unsigned swaps_amount = 0;

    for (unsigned i = end_idx; i > begin_idx; i--)
        if (array[i] < array[i - 1]) {
            swap(array, i, i - 1);
            swaps_amount++;
        }

    return swaps_amount;
}

unsigned shaker_sort(int *array, unsigned const array_length) {
    unsigned begin_idx = 0;
    unsigned end_idx   = array_length;

    unsigned swaps_amount          = 0;
    unsigned swaps_amount_per_step = 0;

    do {
        swaps_amount_per_step = forward_step(array, begin_idx, end_idx);
        end_idx--;
        swaps_amount += swaps_amount_per_step;

        swaps_amount_per_step = backward_step(array, begin_idx, end_idx);
        begin_idx++;
        swaps_amount += swaps_amount_per_step;
    } while (swaps_amount_per_step != 0);

    return swaps_amount;
}

unsigned bubble_forward_sort(int *array, unsigned const array_length) {
    unsigned begin_idx = 0;
    unsigned end_idx   = array_length;

    unsigned swaps_amount          = 0;
    unsigned swaps_amount_per_step = 0;

    do {
        swaps_amount_per_step = forward_step(array, begin_idx, end_idx);
        end_idx--;
        swaps_amount += swaps_amount_per_step;
    } while (swaps_amount_per_step != 0);

    return swaps_amount;
}

unsigned bubble_backward_sort(int *array, unsigned const array_length) {
    unsigned begin_idx = 0;
    unsigned end_idx   = array_length;

    unsigned swaps_amount          = 0;
    unsigned swaps_amount_per_step = 0;

    do {
        swaps_amount_per_step = backward_step(array, begin_idx, end_idx);
        begin_idx++;
        swaps_amount += swaps_amount_per_step;
    } while (swaps_amount_per_step != 0);

    return swaps_amount;
}
