#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 3, 10};
    cout << "Max Adjacent Distance: " << sol.maxAdjacentDistance(nums) << endl;
    return 0;
}
// 📌 Problem Name:
// Maximum Adjacent Distance (including circular case)

// ❓ Problem Statement:
// Given a list of integers nums, find the maximum absolute difference between:

// Any two adjacent elements in the array, and

// Also include the difference between the first and last element (i.e., treat it as circular).

// 🧠 Basic Logic Behind the Code:
// We are trying to find the largest jump (difference) between any two neighboring numbers, including the circular case (first and last).

// 🧩 Approach:
// Start by calculating the absolute difference between the first and last element.

// Then, loop through the array and calculate absolute differences between all adjacent pairs.

// Keep updating the maximum difference found.

// Return the final result.

// ✅ Code Behavior Example:
// For input: [1, 5, 3, 10]
// Adjacent differences:

// |1 - 5| = 4

// |5 - 3| = 2

// |3 - 10| = 7

// |1 - 10| = 9 (first and last)

// Output: 9

// 🔚 Conclusion (In Short):
// This function helps find the maximum jump between neighboring elements in an array, treating it like a circle, where the last element wraps around to the first. This is useful in scenarios like ring buffers, circular queues, or circular plots.

// Let me know if you want to remove the circular part or make it flexible!














