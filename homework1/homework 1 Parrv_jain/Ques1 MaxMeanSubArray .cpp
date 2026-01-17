#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// T.C = O(n)
// S.C = O(1)
// Approach: Use a sliding window of size k to calculate the sum and mean, updating the maximum mean found.
// TIMETAKEN:30MINS

double MaxMeanSubArray(vector<int> arr, int k) {
    int sum = 0;
    double mean = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
        mean = (double)sum / k;
    }
    double Max_mean = mean;
    for (int i = k; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];
        mean = (double)sum / k;
        Max_mean = max(Max_mean, mean);
    }
    return Max_mean;
}
int main() {
    cout << MaxMeanSubArray({4, 5, -3, 2, 6, 1}, 2) << endl; // Expected: 4.5
    cout << MaxMeanSubArray({4, 5, -3, 2, 6, 1}, 3) << endl; // Expected: 3
    cout << MaxMeanSubArray({1, 1, 1, 1, -1, -1, 2, -1, -1}, 3) << endl; // Expected: 1
    cout << MaxMeanSubArray({1, 1, 1, 1, -1, -1, 2, -1, -1, 6}, 5) << endl; // Expected: 1
}