#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        vector<vector<int>> ans;

        // Step 2: Traverse in groups of 3
        for (int i = 0; i < nums.size(); i += 3) {
            // Step 3: Check condition
            if (nums[i + 2] - nums[i] > k) {
                return {};  // Not valid, return empty
            }
            // Step 4: Add valid group
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;

    vector<vector<int>> result = sol.divideArray(nums, k);

    // Print result
    if (result.empty()) {
        cout << "[]\n";
    } else {
        for (const auto& group : result) {
            cout << "[";
            for (int i = 0; i < group.size(); ++i) {
                cout << group[i] << (i < group.size() - 1 ? ", " : "");
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
// 🧠 Problem Name: Divide Array into Groups of Three