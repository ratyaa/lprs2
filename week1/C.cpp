#include <iostream>

using namespace std;

const char* yearIsLeap (int);

int main() {
    int year = 0;
    
    cin >> year;
    cout << yearIsLeap(year) << endl;

    return 0;
}

const char* yearIsLeap (int year) {
    return (year % 4 == 0 ? "yes" : "no");
}
