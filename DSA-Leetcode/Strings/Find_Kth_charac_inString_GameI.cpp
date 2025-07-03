#include<cmath>
class Solution{
public:
    char kthCharacter(int k){
        int ans=0;
        int t;
        while(k!=1){
            t = static_cast<int>(log2(k));
            if((1<<k)==k){
                t--;


            }
            k=k-(1<<t);
        ans++;
         }
         return 'a'+ans;
    }
};
#include<iostream>
#include<string>    
using namespace std;

int main() {
    Solution sol;
    int k = 5;  // Example input
    char result = sol.kthCharacter(k);
    cout << "The " << k << "th character is: " << result << endl;
    return 0;
}
// Problem name (short):
// Find the K-th Character in a Binary String Game
// Given a binary string generation rule (e.g., generate by replacing 0 → 01 and 1 → 10 repeatedly), find the k-th character in the generated string without actually building the whole string.

//The generated binary string at each level doubles and flips — its length at level n is 2^n - 1.
// ️⃣ The position k can be located recursively by figuring out which half (left/middle/right) it belongs to, using the highest power of 2 ≤ k.
// 4⃣log2(k) gives you the highest bit — and from that you can infer which part of the construction it’s in.
// ️⃣ Reduce k accordingly and repeat.

