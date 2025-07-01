#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int substrCount(string s, int k) {
        if (k > s.length())
            return 0;

        vector<int> cnt(26, 0);
        int ans = 0, distinctCnt = 0;

        for (int i = 0; i < k - 1; i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;
        }

        for (int i = k - 1; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;

            if (distinctCnt == k - 1)
                ans++;

            char removeChar = s[i - k + 1];
            cnt[removeChar - 'a']--;
            if (cnt[removeChar - 'a'] == 0)
                distinctCnt--;
        }

        return ans;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.substrCount(s, k);

    cout << "Result: " << result << endl;
    return 0;
}


// ✅ Problem Name:
// Count Substrings of Length k with Exactly k-1 Distinct Characters

// ✅ Short Approach:
// Use a sliding window of size k to scan all substrings of length k.

// Track character frequencies using a 26-size array.

// Maintain a count of distinct characters in the current window.

// For each window:

// If it contains exactly k-1 distinct characters, increment the result.

// Slide the window by updating frequencies and the distinct count.