#ifndef N
#define N 5
#endif

#include <iostream>

void mergeArrays(int (&)[N], int (&)[N], int (&)[2 * N]);
void initFromStdin(int (&)[N]);
void printArray(int (&)[2 * N]);

int main() {
    int array_1[N];
    int array_2[N];
    int result[2 * N];
    
    initFromStdin(array_1);
    initFromStdin(array_2);

    mergeArrays(array_1, array_2, result);
    printArray(result);

    return 0;
}
void mergeArrays(int (&array_1)[N], int (&array_2)[N], int (&result)[2 * N]) {
    unsigned firstPosition = 0;
    unsigned secondPosition = 0;
    
    for (unsigned i = 0; i < 2 * N; i++) {
        if (firstPosition >= N) {
            result[i] = array_2[secondPosition];
            secondPosition++;
            continue;
        }

        if (secondPosition >= N) {
            result[i] = array_1[firstPosition];
            firstPosition++;
            continue;
        }
        
        if (array_1[firstPosition] < array_2[secondPosition]) {
            result[i] = array_1[firstPosition];
            firstPosition++;
        } else {
            result[i] = array_2[secondPosition];
            secondPosition++;
        }
    }
}

void printArray(int (&array)[2 * N]) {
    for (int n : array)
        std::cout << n << ' ';
    std::cout << std::endl;
}

void initFromStdin(int (&array)[N]) {
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
}
