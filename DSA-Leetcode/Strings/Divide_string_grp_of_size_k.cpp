#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        int curr = 0;
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcdefg";
    int k = 3;
    char fill = 'x';

    vector<string> result = sol.divideString(s, k, fill);
    for (const string &group : result) {
        cout << "\"" << group << "\" ";
    }
    return 0;
}
// 🧠 Problem Name:
// Divide a String Into Groups of Size k

// ✅ Problem Logic:
// Given a string s, divide it into substrings of length k. If the last group has fewer than k characters, fill it with a given character fill to make it length k.

