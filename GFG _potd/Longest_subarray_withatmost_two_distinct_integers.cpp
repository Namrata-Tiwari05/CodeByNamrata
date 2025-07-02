// ✅ Goal:
// Find the length of the longest subarray with at most two distinct integers.

// 👇 Approach:
// Use two pointers left and right to maintain a window.

// Use a hashmap to store the frequency of each number in the window.

// Expand the window by moving right.

// Shrink the window from the left until there are at most two distinct integers.

// Track the maximum window size throughout.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarrayWithTwoDistinct(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> count;
    int left = 0, maxLen = 0;

    for (int right = 0; right < n; ++right) {
        count[arr[right]]++;

        while (count.size() > 2) {
            count[arr[left]]--;
            if (count[arr[left]] == 0) {
                count.erase(arr[left]);
            }
            ++left;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};

    int result = longestSubarrayWithTwoDistinct(arr);
    cout << "Length of longest subarray with at most two distinct integers: " << result << endl;

    return 0;
}
// Output: Length of longest subarray with at most two distinct integers: 4