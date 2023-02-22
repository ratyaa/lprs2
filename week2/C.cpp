#ifndef N
#define N 5
#endif

#include <iostream>

void shiftRight(int (&)[N], unsigned);
void printArray(int (&)[N]);

int main() {
    int array[N];
    unsigned shift_length;

    std::cin >> shift_length;
    
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
    
    shiftRight(array, shift_length);
    printArray(array);

    return 0;
}

void shiftRight(int (&array)[N], unsigned shift_length) {
    shift_length %= N;
    
    int tmp_slice[shift_length];
    for (int i = 1; i <= shift_length; i++)
        tmp_slice[shift_length - i] = array[N - i];
    
    for (int i = N - 1; i > shift_length - 1; i--)
        array[i] = array[i - shift_length];

    for (int i = 0; i < shift_length; i++)
        array[i] = tmp_slice[i];
}

void printArray(int (&array)[N]) {
    for (int n : array)
        std::cout << n << ' ';
    std::cout << std::endl;
}
