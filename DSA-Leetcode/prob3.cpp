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
