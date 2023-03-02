#include "search_functions.hpp"

void swap(int *array, unsigned const first, unsigned const second) {
    array[first] += array[second];
    array[second] = array[first] - array[second];
    array[first]  = array[first] - array[second];
}

int bruteForceSearch(int *array, unsigned const array_length,
                     int const number) {
    int result = not_found_code;

    for (unsigned i = 0; i < array_length; i++)
        if (array[i] == number) {
            result = i;
            break;
        }

    return result;
}

int binarySearch(int *array, unsigned const array_length, int const number) {
    unsigned result = not_found_code;
    unsigned left   = 0;
    unsigned right  = array_length;
    unsigned current_pos;
    unsigned current_value;

    while (left <= right) {
        current_pos   = left + (right - left) / 2;
        current_value = array[current_pos];

        if (current_value == number) {
            result = current_pos;
            break;
        } else if (current_value > number && current_pos != 0)
            right = current_pos - 1;
        else if (current_value < number && current_pos != UINT_MAX)
            left = current_pos + 1;
        else
            break;
    }

    return result;
}

void fillWithNonegativeIntegerSequence(int *array,
                                       unsigned const array_length) {
    for (unsigned i = 0; i < array_length; i++)
        array[i] = (int)i;
}

void fillWithMinusOne(int *array, unsigned const array_length) {
    for (unsigned i = 0; i < array_length; i++)
        array[i] = -1;
}

void fillWithZeros(int *array, unsigned const array_length) {
    for (unsigned i = 0; i < array_length; i++)
        array[i] = 0;
}

int pairSumBruteForce(int *array, unsigned const array_length, int const sum) {
    unsigned result_first  = 0;
    unsigned result_second = 0;

    for (unsigned first = 0; first < array_length; first++) {
        for (unsigned second = 0; second < array_length; second++)
            if (array[first] + array[second] == sum) {
                result_first  = first;
                result_second = second;
                break;
            }
        if (array[result_first] + array[result_second] == sum)
            break;
    }

    // return std::pair<unsigned, unsigned>(first, second)
    return 0;
}

int pairSumFast(int *array, unsigned const array_length, int const sum) {
    unsigned result_first  = 0;
    unsigned result_second = 0;
    unsigned first         = 0;
    unsigned second        = array_length - 1;

    while (first != second) {
        if (array[first] + array[second] == sum) {
            result_first  = first;
            result_second = second;
            break;
        } else if (array[first] + array[second] < sum)
            first++;
        else
            second--;
    }

    // return std::pair<unsigned, unsigned>(first, second)
    return 0;
}

unsigned freqUsed_A(int *array, unsigned const array_length, int const number) {
    int result = bruteForceSearch(array, array_length, number);

    if (result != not_found_code)
        swap(array, result, 0);

    return result;
}

unsigned freqUsed_B(int *array, unsigned const array_length, int const number) {
    int result = bruteForceSearch(array, array_length, number);

    if (result != not_found_code && result != 0)
        swap(array, result, result - 1);

    return result;
}

unsigned freqUsed_C(int *array, unsigned const array_length, int const number) {
    int result = bruteForceSearch(array, array_length, number);

    if (result != not_found_code && result != 0)
        swap(array, result, result - 1);

    return result;
}

void dummy_permutate(int *array, int *status, int const search_result) {}

void freqUsed_A_permutate(int *array, int *status, int const search_result) {
    if (search_result != not_found_code)
        swap(array, search_result, 0);
}

void freqUsed_B_permutate(int *array, int *status, int const search_result) {
    if (search_result != not_found_code && search_result != 0)
        swap(array, search_result, search_result - 1);
}

void freqUsed_C_permutate(int *array, int *status, int const search_result) {
    if (search_result != not_found_code) {
        status[search_result]++;
        if (search_result != 0)
            if (status[search_result] > status[search_result - 1])
                swap(array, search_result, search_result - 1);
    }
}
