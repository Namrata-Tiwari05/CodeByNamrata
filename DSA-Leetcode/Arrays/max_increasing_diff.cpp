#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};

// Test the function
int main() {
    Solution sol;
    vector<int> nums = {7, 1, 5, 4};
    int result = sol.maximumDifference(nums);
    cout << "Maximum difference: " << result << endl;
    return 0;
}
// 🧠 Problem Name: Maximum Difference Between Increasing Elements
// 🔎 Problem Description (LeetCode Style)
// Given an array nums, find the maximum difference nums[j] - nums[i] such that j > i and nums[j] > nums[i].
// If no such pair exists, return -1.

// 💡 Logic Behind the Code
// Traverse the array while keeping track of the minimum element seen so far (premin).

// For every element, check if it's greater than premin. If so, calculate the difference and update the maximum difference (ans).

// If the element is smaller than premin, update premin.

// Return ans at the end.
// This is an O(n) time and O(1) space solution.

