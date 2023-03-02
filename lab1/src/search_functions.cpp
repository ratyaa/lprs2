#include "search_functions.hpp"

unsigned bruteForceSearch(int *array, unsigned const array_length,
                          int const number) {
    int result = -1;

    for (unsigned i = 0; i < array_length; i++)
        if (array[i] == number) {
            result = i;
            break;
        }

    return result;
}

unsigned binarySearch(int *array, unsigned const array_length,
                      int const number) {
    unsigned result = -1;
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
        else if (current_pos != UINT_MAX)
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

unsigned pairSumBruteForce(int *array, unsigned const array_length,
                           int const sum) {
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

unsigned pairSumFast(int *array, unsigned const array_length, int const sum) {
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
