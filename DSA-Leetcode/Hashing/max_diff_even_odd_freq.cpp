#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequencies
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i]]++;
        }

        // Step 2: Track max odd and min even frequencies
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        bool foundOdd = false, foundEven = false;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int count = it->second;
            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
                foundOdd = true;
            } else {
                minEven = min(minEven, count);
                foundEven = true;
            }
        }

        // Step 3: Handle edge cases
        if (!foundOdd || !foundEven) return 0;

        return maxOdd - minEven;
    }
};

int main() {
    Solution sol;

    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = sol.maxDifference(input);
    cout << "Result (max odd freq - min even freq): " << result << endl;

    return 0;
}
// 🧠 Problem Explanation (LeetCode - Maximum Difference Between Even and Odd Frequency I)

// 🧩 Problem Summary (Inferred):Maximum Difference Between Even and Odd Frequency I
// Given a string s, find the difference between the maximum frequency of any character with an odd frequency and the minimum frequency of any character with an even frequency.
// Return this difference as an integer.
// If there are no even or no odd frequencies, return 0.

// 🧠 Logic Behind the Code:
// Count the Frequency

// Use a hash map (unordered_map<char, int>) to count how many times each character appears in the string.

// Classify Frequencies as Odd or Even

// For each character frequency:

// If it is odd, keep track of the maximum odd frequency seen.

// If it is even, keep track of the minimum even frequency seen.

// Compute the Difference

// Return maxOdd - minEven as the result.

// Edge Case Handling (missing in your code but needed):

// If no odd or no even frequencies exist, the result may be invalid. A return value like 0 is often used in such cases.

// 🧭 Step-by-Step Approach:
// Initialize:

// unordered_map<char, int> freq to store character frequencies.

// maxOdd = INT_MIN (to keep track of highest odd frequency).

// minEven = INT_MAX (to keep track of lowest even frequency).

// Loop Through String:

// For each character ch in s, increment freq[ch].

// Process Frequencies:

// Loop through the values in the freq map.

// If value is odd → update maxOdd.

// If value is even → update minEven.

// Return Result:

// If maxOdd == INT_MIN or minEven == INT_MAX, return 0 (no valid comparison).

// Else, return maxOdd - minEven.
// 🔍 Example:
// Input: "aaabbcc"
// Frequencies: a:3, b:2, c:2

// Odd freq → 3 → maxOdd = 3

// Even freqs → 2 → minEven = 2
// Result: 3 - 2 = 1

