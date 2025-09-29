/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with sum = 0
int zeroSumSubArrays(vector<int> arr) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    // Initialize for the case when subarray itself starts from index 0
    prefixSumCount[0] = 1;

    for (int num : arr) {
        sum += num; // running prefix sum

        // If the same sum has been seen before, zero-sum subarray found i that case
        if (prefixSumCount.find(sum) != prefixSumCount.end()) {
            count += prefixSumCount[sum];
        }

        // Increment frequency of current sum by 1
        prefixSumCount[sum]++;
    }

    return count;
}

// Test cases
int main() {
    cout << zeroSumSubArrays({4, 5, 2, -1, -3, -3, 4, 6, -7}) << endl; // Expected: 2
    cout << zeroSumSubArrays({1, 8, 7, 3, 11, 9}) << endl;             // Expected: 0
    cout << zeroSumSubArrays({8, -5, 0, -2, 3, -4}) << endl;           // Expected: 2
    return 0;
}
