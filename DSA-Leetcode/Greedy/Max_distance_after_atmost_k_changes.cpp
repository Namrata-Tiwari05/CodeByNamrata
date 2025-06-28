#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for (char it : s) {
            switch (it) {
                case 'N': north++; break;
                case 'S': south++; break;
                case 'E': east++; break;
                case 'W': west++; break;
            }

            int times1 = min({north, south, k}); // max changes for N/S
            int times2 = min({east, west, k - times1}); // remaining changes for E/W

            ans = max(ans,
                      count(north, south, times1) + count(east, west, times2));
        }
        return ans;
    }

    int count(int dir1, int dir2, int times) {
        return abs(dir1 - dir2) + times * 2;
    }
};

int main() {
    Solution sol;
    string s = "NESWNS";
    int k = 2;
    cout << "Max Distance: " << sol.maxDistance(s, k) << endl;
    return 0;
}


//  Problem Name:
// Maximum Distance After At Most k Changes

// 📌 Problem Description (Inferred):
// You are given a string s consisting of directions: 'N', 'S', 'E', 'W'.
// Each character represents a movement in a 2D plane from the origin.
// You are allowed to change at most k characters in the string to maximize the final Manhattan distance from the origin.

// Return the maximum possible Manhattan distance from the origin after at most k changes.

// 🧠 Logic & Explanation:
// 🔹 Step-by-step:
// We simulate the traversal along the string s.

// Maintain counters for each direction:

// north, south, east, west

// For every character traversed:

// Update the appropriate direction count.

// Try to modify up to k characters to maximize distance.

// You can modify an N to S, or E to W (or vice versa) to stretch distance.

// For each step, compute the best modification possible using up to k operations and track the maximum Manhattan distance.

// 🔸 Modification Strategy:
// You want to increase the net distance between N-S and E-W.

// So, you're allowed to:

// Use up to k changes to amplify either of the two directions.

// Example: If N = 3 and S = 2, using one change on S → N makes it N = 4, S = 1 → |4 - 1| = 3.

// 🔹 Function: count(drt1, drt2, times)
// Calculates:
// abs(drt1 - drt2) + times * 2
// → the abs() gives current distance
// → times * 2 accounts for turning a move from one direction to its opposite, effectively stretching the distance by 2 per change.
