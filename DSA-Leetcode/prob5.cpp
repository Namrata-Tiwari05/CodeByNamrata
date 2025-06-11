#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;

                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);

                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] = min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }

                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "0123401234";
    int k = 3;
    cout << sol.maxDifference(s, k) << endl;
    return 0;
}
// 🔍 Problem Summary
// You are given:

// A string s consisting of digits from '0' to '4'.

// An integer k.

// You need to find the maximum difference between the count of one digit a and another digit b (where a ≠ b, both between '0' and '4') in a substring of at least length k, and the substring must have at least 2 bs.

// Additionally, only substrings where the parity (odd/even) of a and b match in a certain way are allowed, based on the XOR logic applied.

// 🧠 Logic Behind the Code
// This code uses:

// Sliding window + bitmasking on parity of counts of two characters a and b.

// Stores minimum value of a_count - b_count for each parity status of the window.
// When the window has enough length and at least 2 bs, we try to update the maximum difference.
// 🧾 Step-by-step Explanation
// Loop over all combinations of a and b from '0' to '4' (total 20).

// Skip if a == b.

// Initialize a best[4] array (holds min a_count - b_count per parity type).

// Use a sliding window between left and right.

// For each window:

// Update counts of a and b.
// cnt_a += (s[right] == a);
// cnt_b += (s[right] == b);

// If window size is ≥ k and has ≥ 2 bs:

// Record the best for that parity state.

// Slide the window from left side.

// For current right side, check if there's a compatible left side (via parity match).