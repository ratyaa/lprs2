#ifndef N
#define N 3
#endif

#include <iostream>

void reverseArray(int (&)[N]);
void printArray(int (&)[N]);

int main() {
    int array[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
    

    reverseArray(array);
    printArray(array);

    return 0;
}

void reverseArray(int (&array)[N]) {
    for (int i = 0; i < N/2; i++) {
        int tmp = array[i];
        array[i] = array[N - i - 1];
        array[N - i - 1] = tmp;
    }
}

void printArray(int (&array)[N]) {
    for (int n : array)
        std::cout << n << ' ';
    std::cout << std::endl;
}
