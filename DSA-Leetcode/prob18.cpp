#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n, false);  // mark[i] = true if i should be included

        // Step 1: Mark all valid indices
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    mark[i] = true;
                }
            }
        }

        // Step 2: Collect all marked indices
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-distant indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n, false);  // mark[i] = true if i should be included

        // Step 1: Mark all valid indices
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    mark[i] = true;
                }
            }
        }

        // Step 2: Collect all marked indices
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-distant indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
// 🧠 Problem Name:#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> mark(n, false);  // mark[i] = true if i should be included

        // Step 1: Mark all valid indices
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    mark[i] = true;
                }
            }
        }

        // Step 2: Collect all marked indices
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-distant indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
// 2200. Find All K-Distant Indices in an Array.
// You're given an integer array nums, an integer key, and an integer k.

// You must return all indices i in the array such that there exists some index j where:

// nums[j] == key and

// abs(i - j) <= k

// In short: Return all positions that are within distance k from any key in the array.

// 💡 Optimized Logic
// Instead of checking all (i, j) pairs (which is O(n²)):

// Scan the array and collect indices where nums[j] == key.

// For each such j, mark all positions from [j - k] to [j + k] as valid (make sure to stay within bounds).

// After marking, collect all marked positions into a result vector.

// This avoids redundant work and is much faster.