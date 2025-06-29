// Sort the array and use two pointers to find valid (min, max) pairs such that min + max <= target. For each valid range, add 
// the count of pairs that can be formed with the elements in that range.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << sol.numSubseq(nums, target) << endl;
    return 0;
}
