#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum average of any subarray of given size
float MaxMeanSubarray(vector<int> numbers, int windowSize) {
    int n = numbers.size();
    int currentSum = 0;
    
    // Calculate sum of first window
    for(int i = 0; i < windowSize; i++) {
        currentSum += numbers[i];
    }
    
    int maxWindowSum = currentSum;
    
    // Slide the window through the array
    for(int i = windowSize; i < n; i++) {
        // Update window sum by adding new element and removing first element of previous window
        currentSum = currentSum + numbers[i] - numbers[i - windowSize];
        
        // Update maximum sum if current window sum is larger
        if(currentSum > maxWindowSum) {
            maxWindowSum = currentSum;
        }
    }
    
    // Return the maximum average
    return (float)maxWindowSum / windowSize;
}

int main() {
    vector<int> test1 = {2, 3, -3, 4, 10, 11, -5, 10};
    vector<int> test2 = {1, 1, -1, 0, -1, -1, 0, -1, -1};
    vector<int> test3 = {1, 2, 3, 4, 5, -1, -2, -3, -4, 6};
    
    cout << MaxMeanSubarray(test1, 2) << endl;
    cout << MaxMeanSubarray(test1, 3) << endl;
    cout << MaxMeanSubarray(test2, 3) << endl;
    cout << MaxMeanSubarray(test3, 5) << endl;
    
    return 0;
}

// T.C = O(n)
// S.C = O(1)
// Approach: Fixed-size sliding window