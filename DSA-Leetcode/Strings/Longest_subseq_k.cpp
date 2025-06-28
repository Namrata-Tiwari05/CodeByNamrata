// 🔍 Problem Name:
// Longest Subsequence Repeated k Times

// 💡 Problem Statement:
// Given a string s and an integer k, find the longest string t such that:

// t is a subsequence of s repeated k times.

// t itself can be repeated k times as a subsequence in s.

// Among all such strings, return the lexicographically largest one.

// ✅ Logic & Explanation:
// Character Frequency Pruning:

// If a character occurs less than k times, it can’t form a subsequence that appears k times. So we discard it.

// Remaining characters form a pool of candidates.

// BFS for Candidate Building:

// Start with single characters.

// Append characters from the candidate pool to build longer strings.

// At each step, check if the new string t is a subsequence repeated k times in s using isKRepeatedSubsequence.

// isKRepeatedSubsequence() Function:

// Walk through s and try to match characters of t in sequence.

// If you can match t k times, return true.

// Tracking the Best Answer:

// Keep updating the ans if current candidate has greater length or is lexicographically greater.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        vector<char> candidate;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.push_back('a' + i);
            }
        }

        queue<string> q;
        for (char ch : candidate) {
            q.push(string(1, ch));
        }

        string ans = "";
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.size() > ans.size() || (curr.size() == ans.size() && curr > ans)) {
                ans = curr;
            }
            for (char ch : candidate) {
                string next = curr + ch;
                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }

    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int pos = 0, matched = 0;
        int n = s.size(), m = t.size();
        for (char ch : s) {
            if (ch == t[pos]) {
                pos++;
                if (pos == m) {
                    pos = 0;
                    matched++;
                    if (matched == k) return true;
                }
            }
        }
        return false;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    string s = "letsleetcode";
    int k = 2;
    cout << "Output: " << sol.longestSubsequenceRepeatedK(s, k) << endl;
    return 0;
}
