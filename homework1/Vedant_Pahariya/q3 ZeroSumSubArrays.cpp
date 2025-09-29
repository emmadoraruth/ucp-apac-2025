// Problem Statement
/* Given an array of integers, count the number of subarrays that sum to zero. */

// Technique: One-directional running computation/total (Hashing with Prefix Sums)
// Time Complexity: O(n), n is the length of the array
// Space Complexity: O(n) in the worst case, if all prefix sums are unique

#include <bits/stdc++.h>
using namespace std;

int countZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    int count = 0;

    // Initialize with prefix sum 0 occurring once
    prefixSumCount[0] = 1;

    for (int num : arr) {
        prefixSum += num;

        // If this prefix sum has been seen before, it means there are subarrays summing to zero
        if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum];
        }

        // Record the occurrence of this prefix sum
        prefixSumCount[prefixSum]++;
    }

    return count;
}

int main() {
    vector<vector<int>> testCases = {
        {4, 5, 2, -1, -3, -3, 4, 6, -7},
        {1, 8, 7, 3, 11, 9},
        {8, -5, 0, -2, 3, -4},
        {-1, -1, 1, 1},
        {0, 0, 0}
    };

    for (auto& testCase : testCases) {
        cout << "Array: ";
        for (int num : testCase) {
            cout << num << " ";
        }
        cout << "\nNumber of zero-sum subarrays: " << countZeroSumSubarrays(testCase) << "\n\n";
    }

    return 0;
}