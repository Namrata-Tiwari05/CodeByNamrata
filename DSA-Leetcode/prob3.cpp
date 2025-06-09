#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // We already count 1, so we start searching for the rest
        
        while (k > 0) {
            int step = countSteps(n, curr, curr + 1); // Steps between curr and curr+1
            if (step <= k) {
                // Move to the next sibling
                curr++;
                k -= step;
            } else {
                // Go to the next child
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

private:
    int countSteps(int n, long prefix1, long prefix2) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += min((long)(n + 1), prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};

// Driver code to run in VS Code
int main() {
    Solution sol;
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "K-th smallest number in lexicographical order: " << sol.findKthNumber(n, k) << endl;
    return 0;
}
// 🧠 Problem Explanation (LeetCode 440 - K-th Smallest in Lexicographical Order)
// Prompt:
// You are given two integers n and k. You need to return the k-th lexicographically smallest integer in the range [1, n].
// The lexicographical order is similar to dictionary order, where numbers are compared digit by digit.
// For example, for n = 13, the lexicographical order of numbers is: 1, 10, 11, 12, 13, 2, 3, ..., 9.
// 🔧 Step-by-Step Approach
// 🔹 Step 1: Start at prefix 1 (which is the first number in lexicographical order)
// 🔹 Step 2: At every step:
// Count how many numbers exist starting with current prefix (we call it step)

// If k > step:

// That means our answer is not in this subtree

// Move to next sibling (i.e., curr = curr + 1)

// Subtract step from k

// If k ≤ step:

// That means our answer is inside this subtree

// Move to child (i.e., curr = curr * 10)

// Decrease k by 1 (because we’re counting this move)

// Repeat this until k == 0.

// 🔹 Step 3: Return curr as the k-th number
// ⏱️ Time Complexity
// We only go as deep as the height of the tree, which is log₁₀(n), and in the worst case, we do this for about log n levels.

// So time complexity is approximately O(log n * log n)

