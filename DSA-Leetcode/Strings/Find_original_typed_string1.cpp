#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1; // initialize ans to 1 as requested
        // Add your logic here if needed, for now it just returns 1
        for (int i = i; i < n; ++i) {
            if (word[i-1]==word[i]) {
                ++ans; // double the count for each 'a' or 'b'
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string word;
    cout << "Enter a string: ";
    cin >> word;

    int result = sol.possibleStringCount(word);
    cout << "Possible original typed strings: " << result << endl;

    return 0;
}
// ✅ Problem Name:
// "Find Original Typed Strings"

// ✅ Approach:
// Initialize ans = 1 and return it directly (or apply problem-specific logic if needed). Ensure the function accepts a string, not int.