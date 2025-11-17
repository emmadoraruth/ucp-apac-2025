#include <iostream>
#include <vector>
#include <map>
using namespace std;
// tc=O(n)
// sc=O(n)
// Approach: Use a hashmap to store the frequency of prefix sums. For each prefix sum, if it has been seen before, it indicates a zero-sum subarray.
// TIMETAKEN:30MINS

int ZeroSumSubArrays(vector<int> arr) {
    map<int, int> mp;
    int cnt = 0;
    int prefixSum = 0;
    mp[0] = 1;
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        int rem = prefixSum;
        cnt += mp[rem];
        mp[prefixSum] += 1;
    }
    return cnt;
}

int main() {
cout << ZeroSumSubArrays({4, 5, 2, -1, -3, -3, 4, 6, -7}) << endl; // Expected: 2
cout << ZeroSumSubArrays({1, 8, 7, 3, 11, 9}) << endl;             // Expected: 0
cout << ZeroSumSubArrays({8, -5, 0, -2, 3, -4}) << endl;           // Expected: 2
}