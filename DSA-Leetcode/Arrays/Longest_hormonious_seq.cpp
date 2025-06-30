//  LeetCode 594: Longest Harmonious Subsequence,
//  Approach
// Use a Hash Map (unordered_map) to count the frequency of each number.

// Iterate through the map: For each key num, check if num + 1 exists.

// If it does, calculate the sum of frequencies freq[num] + freq[num + 1].

// Keep track of the maximum such sum found.

// This gives us the longest length of a harmonious subsequence in O(n) time.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int key = it->first;
            int value = it->second;
            if (freq.count(key + 1)) {
                maxLen = max(maxLen, value + freq[key + 1]);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Output for nums1: " << sol.findLHS(nums1) << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Output for nums2: " << sol.findLHS(nums2) << endl;

    vector<int> nums3 = {1, 1, 1, 1};
    cout << "Output for nums3: " << sol.findLHS(nums3) << endl;

    return 0;
}
