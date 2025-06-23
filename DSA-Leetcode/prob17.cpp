#include <iostream>
using namespace std;

class Solution {
private:
    int digit[100];

public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int length = -1;
            while (x) {
                ++length;
                digit[length] = x % k;
                x /= k;
            }
            for (int i = 0, j = length; i < j; ++i, --j) {
                if (digit[i] != digit[j]) {
                    return false;
                }
            }
            return true;
        };

        int left = 1, count = 0;
        long long ans = 0;
        while (count < n) {
            int right = left * 10;
            for (int op = 0; op < 2; ++op) {
                for (int i = left; i < right && count < n; ++i) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(combined)) {
                        ++count;
                        ans += combined;
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int k = 2, n = 5;
    cout << "Sum of first " << n << " k-mirror numbers: " << sol.kMirror(k, n) << endl;
    return 0;
}
// 🧠 Problem Name:
// K-Mirror Numbers

// 📝 Problem Description (inferred from code):
// Find the first n numbers that are palindromes both in base-10 and base-k, and return their sum.

// ✅ Logic Explanation:
// The core idea is to:

// Generate base-10 palindromes (in increasing order).

// Check if each of them is also a palindrome in base-k.

// Keep adding such numbers until you've found n of them.

// 🔍 Step-by-Step Breakdown:

// 🔁 isPalindrome(long long x)
// Converts number x to base k, stores digits in digit[], and checks if the sequence is a palindrome.

// 🔁 Main logic:
// left starts at 1, used to generate the first half of the palindromes.

// Two kinds of palindromes are built:

// Odd-length: Mirror i/10 (skip the last digit)

// Even-length: Mirror full i

// For each half number i, create full palindromes using digit reflection.

// For each palindrome:

// Check if it is also a palindrome in base k using isPalindrome.

// If yes, add it to the result and increment count.

// Increase the digit range (left = right) to explore higher digits.

