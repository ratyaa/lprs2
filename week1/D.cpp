#include <iostream>

using namespace std;

const char* moreLesserOrGreater (int);

int main() {
    int num_of_nums = 0;
    cin >> num_of_nums;

    const char* result = moreLesserOrGreater(num_of_nums);
    cout << result << endl;

    return 0;
}

const char* moreLesserOrGreater (int num_of_nums) {
    int previous = 0;
    int current = 0;
    int lesser_counter = 0;
    int greater_counter = 0;

    cin >> previous;

    while (num_of_nums > 1) {
        cin >> current;
        num_of_nums--;

        // If numbers are equal then do nothing
        if (current > previous)
            greater_counter++;
        else if (current < previous)
            lesser_counter++;
    }
    
    return (greater_counter >= lesser_counter ? "MAX" : "MIN");
}
