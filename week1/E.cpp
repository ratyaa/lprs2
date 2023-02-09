#include <iostream>

using namespace std;

int recursive_power (int, int);

int main() {
    int base = 0;
    int power = 0;
    cin >> base >> power;

    cout << recursive_power(base, power) << endl;

    return 0;
}

int recursive_power(int base, int power) {
    return (power != 0 ? base * recursive_power(base, power - 1) : 1);
}
