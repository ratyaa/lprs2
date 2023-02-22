#ifndef N
#define N 5
#endif

#include <iostream>

void moveNegativeToEnd(int (&)[N]);
void initWithZeros(int (&)[N]);
void initFromStdin(int (&)[N]);
void printArray(int (&)[N]);

int main() {
    int array[N];
    
    initFromStdin(array);
    
    moveNegativeToEnd(array);
    printArray(array);

    return 0;
}

void moveNegativeToEnd(int (&array)[N]) {
    int positive[N];
    int negative[N];

    initWithZeros(positive);
    initWithZeros(negative);

    unsigned positivePosition = 0;
    unsigned negativePosition = 0;
    
    for (int n : array) {
        if (n >= 0) {
            positive[positivePosition] = n;
            positivePosition++;
        } else {
            negative[negativePosition] = n;
            negativePosition++;
        }
    }

    for (unsigned i = 0; i < positivePosition; i++)
        array[i] = positive[i];

    for (unsigned i = positivePosition; i < N; i++)
        array[i] = negative[i - positivePosition];
}

void printArray(int (&array)[N]) {
    for (int n : array)
        std::cout << n << ' ';
    std::cout << std::endl;
}

void initWithZeros(int (&array)[N]) {
    for (int i = 0; i < N; i++)
        array[i] = 0;
}

void initFromStdin(int (&array)[N]) {
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
}
