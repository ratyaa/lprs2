#ifndef N
#define N 5
#endif

#include <iostream>

int findLastZero(int (&)[N]);
void initFromStdin(int (&)[N]);

int main() {
    int array[N];
    int result;
    
    initFromStdin(array);
    
    result = findLastZero(array);
    std::cout << result << std::endl;

    return 0;
}

int findLastZero(int (&array)[N]) {
    int range = N / 4 + N % 4;
    int pos = N / 2;
    
    while (!(array[pos] == 0 && array[pos + 1] != 0) && (pos < N && pos >= 0)) {
        if (array[pos] == 0)
            pos += range;
        else
            pos -= range;
        
        range = range / 2 + range % 2;
    }
    if (pos == N)
        pos--;
    
    return pos;
}

void initFromStdin(int (&array)[N]) {
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
}
