#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// Problem name (short):
// Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>freqmap;
        for( int num : arr){
            freqmap[num]++;
        }
            int maxLucky =-1;
    for(auto it = freqmap.begin(); it != freqmap.end(); ++it){
        int num = it->first;
        int freq = it->second;
        if(num == freq){
            maxLucky = std::max(maxLucky, num);
        }
    }
return maxLucky;
    }
    
};
int main() {
    Solution sol;
    vector<int> arr = {2, 2, 3, 4};
    int lucky = sol.findLucky(arr);
    if (lucky != -1) {
        cout << "Lucky Integer: " << lucky << endl;
    } else {
        cout << "No Lucky Integer found." << endl;
    }
    return 0;
}

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), for storing the frequency map.
// The code defines a function to find the lucky integer in an array, which is an integer that appears in the array exactly as many times as its value.
// It uses an unordered map to count the frequency of each integer and then checks for lucky integers by comparing the integer with its frequency. The maximum lucky integer is returned, or -1 if no lucky integer exists.
// The main function demonstrates the usage of the Solution class by creating an instance, calling the findLucky method with a sample array, and printing the result. The code is efficient and straightforward, adhering to the problem's requirements.