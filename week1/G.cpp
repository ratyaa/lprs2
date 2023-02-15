#include <iostream>

using namespace std;

const char* extremumRatio(int, int, int);
const char* extremumRatioResult(int);
int extremumRatioModifier(int, int, int);

int main() {
    int num_of_nums;
    int first, second;
    
    cin >> num_of_nums;
    cin >> first;
    cin >> second;
    
    cout << extremumRatio(first, second, num_of_nums) << endl;

    return 0;
}

const char* extremumRatio(int first, int second, int num_of_nums) {
    int previous = first;
    int current = second;
    int next;

    int ratio = 0;

    for (int _ = 2; _ < num_of_nums; _++) {
        cin >> next;
        ratio += extremumRatioModifier(previous, current, next);
    }

    const char* result = extremumRatioResult(ratio);
    return result;
}

const char* extremumRatioResult(int ratio) {
    if (ratio < 0)
        return "MIN";
    else if (ratio > 0)
        return "MAX";

    return "EQUAL";
}

int extremumRatioModifier(int previous, int current, int next) {
    if (current > next && current > previous)
        return 1;
    else if (current < next && current < previous)
        return -1;
    return 0;
}
