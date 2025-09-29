/*
Technique: Fixed-size Sliding Window
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum mean of a subarray of size k
double maxMeanSubArray(vector<int> arr, int k) {
    if (arr.size() < k || k <= 0) return 0;

    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    int maxSum = sum;

    for (int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];   // Sliding through the window
        if (sum > maxSum) maxSum = sum;
    }

    return (double)maxSum / k;
}

// Test cases given to check the function are used below
int main() {
    cout << maxMeanSubArray({4, 5, -3, 2, 6, 1}, 2) << endl; // Expected: 4.5
    cout << maxMeanSubArray({4, 5, -3, 2, 6, 1}, 3) << endl; // Expected: 3
    cout << maxMeanSubArray({1, 1, 1, 1, -1, -1, 2, -1, -1}, 3) << endl; // Expected: 1
    cout << maxMeanSubArray({1, 1, 1, 1, -1, -1, 2, -1, -1, 6}, 5) << endl; // Expected: 1
    cout << maxMeanSubArray({}, 3) << endl; // Expected: 0 (Edge case: empty array)
    cout << maxMeanSubArray({5}, 1) << endl; // Expected: 5 (Single element)
    return 0;
}
