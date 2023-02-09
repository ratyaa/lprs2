#include <iostream>

using namespace std;

int countFactorialTrailingZeros (int);

int main() {
    int number = 0;
    
    cin >> number;
    cout << countFactorialTrailingZeros(number) << endl;

    return 0;
}

int countFactorialTrailingZeros (int number) {
    return number / 5;
}
