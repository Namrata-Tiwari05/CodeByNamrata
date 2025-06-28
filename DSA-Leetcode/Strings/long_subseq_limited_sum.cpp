// ✅ Problem Name:
// Longest Subsequence With Limited Sum

// 📘 Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K

// ✅ Problem Statement Summary:
// Given a binary string s and an integer k, return the maximum length of a subsequence of s such that the binary number represented by the subsequence is less than or equal to k.

// You can delete any number of characters from s to form the subsequence.
// ✅ Key Idea:
// Start from the right end (least significant bits).

// Include all '0's (they add no value).

// For each '1', include it only if adding its value (2^i) keeps the total ≤ k.

// ✅ Why from right to left?
// Because rightmost bits matter less in binary value — they’re cheaper to include.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Sample Input
    string s = "1001010";
    int k = 5;

    int result = sol.longestSubsequence(s, k);
    cout << "Longest valid subsequence length: " << result << endl;

    return 0;
}
