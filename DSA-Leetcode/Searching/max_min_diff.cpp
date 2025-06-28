#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;

        // Maximize the number
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }

        // Minimize the number
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');

        return stoi(s) - stoi(t);
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = sol.minMaxDifference(num);
    cout << "Min-Max Difference: " << result << endl;

    return 0;
}
// ✅ Problem Name: Minimize Maximum Difference (or commonly phrased as Min Max Difference)
// 🧠 Goal:
// Given a number num, transform it twice:

// Maximize the number by replacing any one digit (all its occurrences) with '9'.

// Minimize the number by replacing any one digit (all its occurrences) with '0' (but not leading zero if it's not already 0).
//     🧠 Core Logic:
// We are given an integer num. The task is to:

// Create the maximum number by replacing one digit (and all its occurrences) with 9.

// Create the minimum number by replacing one digit (and all its occurrences) with 0.

// Then find the difference between these two numbers.

// This concept is called Min-Max Difference.