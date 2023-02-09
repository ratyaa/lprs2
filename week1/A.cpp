#include <iostream>

constexpr int DECIMAL_BASE = 10;

using namespace std;

bool isPalindrome (int);
int reverseNumber (int, int = DECIMAL_BASE);

int main() {
    int number = 0;
    cin >> number;
    cout << (isPalindrome(number) ? "yes" : "no") << endl;

    return 0;
}

bool isPalindrome (int number) {
    return (number == reverseNumber(number));
}

int reverseNumber (int initial, int numeral_base) {
    int reversed = 0;
    
    while (initial > 0) {
        reversed = reversed * numeral_base + initial % numeral_base;
        initial /= numeral_base;
    }
    
    return reversed;
}
