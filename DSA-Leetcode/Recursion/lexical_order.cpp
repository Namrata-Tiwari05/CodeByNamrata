#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> result;

    void dfs(int current, int n) {
        if (current > n) return;
        result.push_back(current);
        for (int i = 0; i <= 9; i++) {
            if (current * 10 + i > n) break;
            dfs(current * 10 + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            if (i > n) break;
            dfs(i, n);
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<int> output = sol.lexicalOrder(n);

    cout << "Lexicographical Order: ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// ✅ Problem Goal:

// Print all numbers from 1 to n in lexicographical (dictionary) order — like how words appear in a dictionary.


// ---

// 💡 Logic:

// Lexical order is like:

// 1, 10, 11, ..., 19, 2, 20, 21, ..., 3, ..., 9

// So instead of going linearly (1, 2, 3...), we go deep first:
// Start with 1 → then 10 → then 100, and so on...


// ---

// ⚙ Approach: (Using DFS)

// 1. Start from numbers 1 to 9 as roots.


// 2. For each number:

// Add to result.

// Multiply by 10 and explore (i.e., go deeper: 1 → 10 → 100...).

// Try adding digits 0 to 9 at the end.

// Stop when number exceeds n.



// 3. Use recursion (DFS) to go deep, then backtrack and try next numbers.




// ---

// 🧠 Why DFS?

// Because it lets us go deep first (like 1 → 10 → 11 → 12...), which is exactly how lexicographical order behaves.


// ---