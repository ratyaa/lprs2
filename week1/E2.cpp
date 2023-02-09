#include <iostream>

using namespace std;

int my_power (int, int);

int main() {
    int base = 0;
    int power = 0;
    cin >> base >> power;

    cout << my_power(base, power) << endl;

    return 0;
}

int my_power(int base, int power) {
    int result = 1;
    
    for (int _ = 0; _ < power; _++) {
        result *= base;
    }

    return result;
}
