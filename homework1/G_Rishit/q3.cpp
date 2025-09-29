#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countZeroSumSubarrays(vector<int> arr) {
    unordered_map<int, int> prefixSumFreq;
    int zeroSumCount = 0;
    int currentSum = 0;

    for(int element : arr) {
        currentSum += element;

        if(currentSum == 0) zeroSumCount++;
        if(prefixSumFreq.find(currentSum) != prefixSumFreq.end()) 
            zeroSumCount += prefixSumFreq[currentSum];

        prefixSumFreq[currentSum]++;
    }

    return zeroSumCount;
}

int main() {
    cout << countZeroSumSubarrays({4, 5, 2, -1, -3, -3, 4, 6, -7}) << endl;  // Expected: 2
    cout << countZeroSumSubarrays({0, 0, 0}) << endl;                         // Expected: 6
    cout << countZeroSumSubarrays({1, 2, 3}) << endl;                         // Expected: 0
    cout << countZeroSumSubarrays({1, -1, 1, -1}) << endl;                    // Expected: 4
    return 0;
}

// T.C = O(n)
// S.C = O(n)
// Approach: Prefix sum with hash map