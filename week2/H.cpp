#ifndef N
#define N 3
#define M 3
#endif

#include <iostream>

void print_transposed(int (&)[N][M]);
void initFromStdin(int (&)[N][M]);

int main() {
    int array[N][M];
    int result;
    
    initFromStdin(array);
    
    print_transposed(array);

    return 0;
}

void print_transposed(int (&array)[N][M]) {
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++)
            std::cout << array[n][m] << ' ';

        std::cout << std::endl;
    }
}

void initFromStdin(int (&array)[N][M]) {
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
            std::cin >> array[n][m];
}
