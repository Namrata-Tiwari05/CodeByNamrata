#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        auto change = [&](int x, int y) {
            string num_s = to_string(num);
            for (char& digit : num_s) {
                if (digit - '0' == x) {
                    digit = '0' + y;
                }
            }
            return num_s;
        };

        int min_num = num;
        int max_num = num;
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                string res = change(x, y);
                if (res[0] != '0') {
                    int res_i = stoi(res);
                    min_num = min(min_num, res_i);
                    max_num = max(max_num, res_i);
                }
            }
        }

        return max_num - min_num;
    }
};

int main() {
    Solution sol;
    int num = 555;
    cout << "Max difference: " << sol.maxDiff(num) << endl;
    return 0;
}
// ✅ Problem Name: Minimize Maximum Difference
// 💡 Logic Behind the Code:
// change(x, y) function:

// Replaces all digits equal to x with y in the number's string.

// Returns the modified string version of the number.

// Brute-force Simulation:

// Try all digit pairs (x, y) from 0 to 9 (total 100 combinations).

// Replace every occurrence of digit x with digit y.

// Ignore if the result starts with '0' (invalid as leading zeros not allowed).

// Track the minimum and maximum valid numbers obtained this way.

// Finally, return the maximum difference:
// max_num - min_num.

// 🧠 Key Approach:
// Digit manipulation via brute-force replacement (nested loop).

// Validation to avoid invalid numbers (leading zeros).

// Tracking extremes (max & min) for calculating the result.

