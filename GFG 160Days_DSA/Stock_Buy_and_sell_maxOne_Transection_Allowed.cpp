// C++ Program to solve stock buy and sell
// using one traversal

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  
    int minSoFar = prices[0], res = 0;
  
    for (int i = 1; i < prices.size(); i++) {

        // Update the minimum value seen so
        // far if we see smaller
        if (prices[i] < minSoFar)
            minSoFar = prices[i];
        if (prices[i] - minSoFar > res)
            res = prices[i] - minSoFar;
        // Update result if we get more profit                
        // by selling at current price
    }
    return res;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}