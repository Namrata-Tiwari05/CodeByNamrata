// 🧠 Problem Name: Kth Smallest Product of Two Sorted Arrays
// ✅ Problem Summary:
// Given two sorted arrays nums1 and nums2, and an integer k, the task is to find the k-th smallest product that can be formed by multiplying one element from nums1 with one from nums2.

// ⚙️ Key Concepts:
// Binary Search on answer space (product values).

// Two-pointer/binary search to count how many products are ≤ x.

// 🧠 Logic
// We are given two sorted arrays nums1 and nums2, and a number k. We want to find the k-th smallest product that can be formed by multiplying one number from each array.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper: Count of nums2[j] such that nums1[i] * nums2[j] <= v
    int f(vector<int>& nums2, long long x1, long long v) {
        int n2 = nums2.size();
        int left = 0, right = n2 - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if ((x1 >= 0 && nums2[mid] * x1 <= v) ||
                (x1 < 0 && nums2[mid] * x1 > v)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return x1 >= 0 ? left : n2 - left;
    }

    // Main function to find kth smallest product
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size();
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;

            for (int i = 0; i < n1; i++) {
                count += f(nums2, nums1[i], mid);
            }

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {-4, -2, 0, 3};
    vector<int> nums2 = {-3, -1, 2, 4};
    long long k = 6;

    cout << "K-th Smallest Product: " << sol.kthSmallestProduct(nums1, nums2, k) << endl;

    return 0;
}
