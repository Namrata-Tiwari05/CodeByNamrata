#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, m, k;
    vector<vector<vector<int>>> memo;

    int dp(int pos, int equal, int last) {
        if (equal > k) return 0;
        if (pos == n) return equal == k ? 1 : 0;
        if (memo[pos][equal][last] != -1) return memo[pos][equal][last];

        int res = 0;
        for (int num = 1; num <= m; ++num) {
            if (num == last)
                res = (res + dp(pos + 1, equal + 1, num)) % MOD;
            else
                res = (res + dp(pos + 1, equal, num)) % MOD;
        }

        return memo[pos][equal][last] = res;
    }

    int countGoodArrays(int n_, int m_, int k_) {
        n = n_;
        m = m_;
        k = k_;
        memo.assign(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 2, -1)));

        int res = 0;
        for (int first = 1; first <= m; ++first) {
            res = (res + dp(1, 0, first)) % MOD;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 3, m = 2, k = 1;
    cout << "Result: " << sol.countGoodArrays(n, m, k) << endl; // Expected: 4
    return 0;
}
// 🧠 Problem Name: Count Good Arrays
// 🔍 Logic (Short Version):
// We use recursive dynamic programming with memoization to build arrays of length n, tracking:

// Current position pos

// Count of adjacent equal pairs equal

// Last value placed last

// At each step, we try all values from 1 to m. If the next value equals last, we increment equal; otherwise, we don’t.

// We return the total number of such arrays with exactly k adjacent equal pairs.

