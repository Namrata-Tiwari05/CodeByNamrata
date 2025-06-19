#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Regular sort
        int ans = 1;
        int rec = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - rec > k) {
                ans++;
                rec = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;
    cout << "Minimum partitions: " << sol.partitionArray(nums, k) << endl;
    return 0;
}
// ✅ Problem Name:
// 2294. Partition Array Such That Maximum Difference Is K

// 💡 Logic:
// Sort the Array – This ensures that close numbers stay together.

// Greedy Grouping – Start with the smallest number and try to include as many numbers as possible in the same group as long as their difference with the group's first number is ≤ k.

