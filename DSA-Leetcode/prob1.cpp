#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
// Problem: Two Sum

// 🎯 Goal:
// Find two indices i and j such 

// ✅ Key Concepts Used:

// Hash Map (unordered_map) to store numbers and their indices.

// Instead of checking every pair (which is slow), we check for the complement of each number in the map.

// This approach gives fast lookups (O(1)).



// ---

// ✅ Final Code Logic:

// 1. Create an empty hash map (mp).
// 2. Loop through the array:
//    a. Calculate the complement: target - nums[i]
//    b. If complement is in map → return {index of complement, current index}
//    c. Otherwise → store nums[i] in the map with its index.
// 3. If no pair is found → return empty vector.


// ---

// ✅ Time & Space Complexity:

// Time: O(n) → Only one pass through the array.

// Space: O(n) → For storing elements in the map.