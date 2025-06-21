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
