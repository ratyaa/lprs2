#ifndef N
#define N 5
#endif

#include <iostream>

void shiftRight(int (&)[N]);
void printArray(int (&)[N]);

int main() {
    int array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
    

    shiftRight(array);
    printArray(array);

    return 0;
}

void shiftRight(int (&array)[N]) {
    int tmp = array[N - 1];
    for (int i = N - 1; i > 0; i--)
        array[i] = array[i - 1];

    array[0] = tmp;
}

void printArray(int (&array)[N]) {
    for (int n : array)
        std::cout << n << ' ';
    std::cout << std::endl;
}
