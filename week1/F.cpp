#include <iostream>

using namespace std;

unsigned fibonacci(unsigned);
unsigned fib_iter(unsigned, unsigned, int);

int main() {
    int element_index = 0;
    cin >> element_index;

    cout << fibonacci(element_index) << endl;

    return 0;
}

unsigned fibonacci(unsigned element_index) {
    return fib_iter(1, 0, element_index);
}

unsigned fib_iter (unsigned grtr, unsigned lssr, int count){
    return (count == 0 ? lssr : fib_iter(lssr + grtr, grtr, count - 1));
}
