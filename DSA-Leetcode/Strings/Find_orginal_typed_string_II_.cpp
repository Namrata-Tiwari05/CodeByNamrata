// 🔍 Problem:
// Given a string word and an integer k, we want to:
// Count the number of valid strings formed using groups of repeated characters from word.
// A group is defined by consecutive repeated characters.
// The function likely returns the number of valid combinations of such groups with size ≥ k, modulo 1e9+7.

// 🧠 Logic:
// Count consecutive character group lengths.
// For "aaabbc", the groups are: ['a','a','a'], ['b','b'], ['c'] → freq = [3,2,1].
// Calculate total combinations (Product of group sizes).
// e.g., 3*2*1 = 6. Each group gives you x options to choose from, multiply across.
// If number of groups < k → return total combinations (you can't pick k groups anyway).
// Else, use dynamic programming to:
// Subtract invalid combinations (where less than k groups are chosen).

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;

        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int ans = 1;
        for (int o : freq) {
            ans = static_cast<long long>(ans) * o % mod;
        }

        if ((int)freq.size() < k) {
            return ans;
        }

        vector<int> f(k), g(k, 1);
        f[0] = 1;

        for (int i = 0; i < freq.size(); ++i) {
            vector<int> f_new(k);
            for (int j = 1; j < k; ++j) {
                f_new[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
                }
            }

            vector<int> g_new(k);
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }

            f = move(f_new);
            g = move(g_new);
        }

        return (ans - g[k - 1] + mod) % mod;
    }

private:
    static const int mod = 1000000007;
};

int main() {
    Solution sol;
    string word;
    int k;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter value of k: ";
    cin >> k;

    int result = sol.possibleStringCount(word, k);
    cout << "Possible String Count: " << result << endl;

    return 0;
}
