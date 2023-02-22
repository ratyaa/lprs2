#ifndef N
#define N 5
#endif

#include <iostream>

int findUnique(int (&)[N]);
void initFromStdin(int (&)[N]);

int main() {
    int array[N];
    int result;
    
    initFromStdin(array);
    
    result = findUnique(array);
    std::cout << result << std::endl;

    return 0;
}

int findUnique(int (&array)[N]) {
    int result = 0;
    for (int n : array)
        result ^= n;

    return result;
}

void initFromStdin(int (&array)[N]) {
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
}
