#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Greedy approach to count how many valid pairs can be formed
    int countValidPairs(vector<int>& nums, int threshold) {
        int index = 0, count = 0;
        while (index < nums.size() - 1) {
            if (nums[index + 1] - nums[index] <= threshold) {
                count++;
                index++; // Skip the next index
            }
            index++; // Move to next
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (countValidPairs(nums, mid) >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;

    // Sample input
    vector<int> nums = {1, 3, 6, 19, 20};
    int p = 2;

    // Output result
    int result = solution.minimizeMax(nums, p);
    cout << "Minimum Maximum Difference: " << result << endl;

    return 0;
}
// 🧠 Problem Name: Minimize the Maximum Difference of Pairs
// 📄 Problem Summary:
// Given an array nums of integers and an integer p, you need to form exactly p pairs of indices such that:

// Each index is used at most once.

// The maximum absolute difference among all selected pairs is minimized.

// Return the minimum possible value of the maximum absolute difference of the formed p pairs.

// 🧩 Core Logic and Greedy + Binary Search Approach:
// Sort the array: Sorting helps because you can form the closest pairs (smallest differences) greedily.

// Binary Search on the Answer:

// Define left = 0 (minimum difference possible).

// Define right = max possible difference = nums[n-1] - nums[0].

// For each midpoint mid, use a greedy approach to count how many pairs can be formed such that the difference between paired elements is ≤ mid.

// If you can form at least p such pairs:

// Try a smaller threshold → set right = mid.

// Otherwise, try a larger threshold → set left = mid + 1.

// Continue until left == right. That’s your answer.

// ✅ Helper Function: countValidPairs(nums, threshold)
// Greedily count how many valid (non-overlapping) pairs exist where the difference between the two numbers in a pair is ≤ threshold.

// If a valid pair is formed, skip both elements to avoid reusing indices.

// 🔁 Key Function: minimizeMax(nums, p)
// Runs a binary search over the range of possible max differences.

// At each step, checks if it's possible to form at least p valid pairs for a given threshold.

// Finds the smallest threshold that satisfies the condition.

