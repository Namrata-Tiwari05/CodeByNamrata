#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;

        // Step 1: Count character frequencies
        for (char ch : word) {
            cnt[ch]++;
        }

        int res = word.size();

        // Step 2: Try each character frequency as baseline
        for (auto it1 = cnt.begin(); it1 != cnt.end(); ++it1) {
            int a = it1->second;
            int deleted = 0;

            for (auto it2 = cnt.begin(); it2 != cnt.end(); ++it2) {
                int b = it2->second;

                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }

            res = min(res, deleted);
        }

        return res;
    }
};

int main() {
    Solution sol;
    string word;
    int k;

    cout << "Enter the word: ";
    cin >> word;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = sol.minimumDeletions(word, k);
    cout << "Minimum deletions needed: " << result << endl;

    return 0;
}
// ✅ Problem Name: Minimum Deletions to Make Character Frequencies Equal
// 🧠 Problem Logic / Intuition
// You are given a string word and an integer k. The task is to make the difference between the frequency of any two characters at most k, by deleting as few characters as possible.

// 🔍 Key Observations:
// For each character frequency a in the map:

// You try to make all other frequencies b such that abs(a - b) ≤ k.

// If b < a, and b is too small → delete all occurrences of b.

// If b > a + k, then we need to delete b - (a + k) characters to bring it into the [a, a+k] range.

// Repeat this for every frequency a as a base, and calculate the minimum deletions required.

