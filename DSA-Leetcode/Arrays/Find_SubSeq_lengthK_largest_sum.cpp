// 🔸 Problem Name: Maximum Subsequence
// 🔸 Problem Statement (Simplified)
// You are given an array nums and an integer k. Return a subsequence of length k that has the largest possible sum.
// A subsequence keeps the relative order of elements.
// 🔸 Logic Explanation
// Store original indices:
// You want to track which element came from where, so you store each element with its index:
// vals = [(index, value)]

// Sort by value (desc):
// Sort the elements in descending order of their value to pick the top k largest values.

// Pick first k elements:
// These are the largest values, but you now need to retain original order, so...

// Sort by index:
// Sort the k elements back by their original index to preserve the original order of elements (since a subsequence must respect the original order).

// Build result:
// Collect the values in this newly sorted list and return them.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;

        // Store index and value
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }

        // Sort by value in descending order
        sort(vals.begin(), vals.end(), [&](auto x1, auto x2) {
            return x1.second > x2.second;
        });

        // Take top k and sort by original index
        sort(vals.begin(), vals.begin() + k);

        // Extract the values
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
        }

        return res;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.maxSubsequence(nums, k);

    cout << "Max subsequence of length " << k << " is:\n";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
