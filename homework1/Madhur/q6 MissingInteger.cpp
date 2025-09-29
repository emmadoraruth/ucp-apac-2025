/*
Time Complexity: O(n)      // Single pass through the array
Space Complexity: O(1)     // Only a few variables used
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing integer in 1..n
int missingInteger(const vector<int>& arr, int n) {
    int expectedSum = n * (n + 1) / 2; // Sum of 1..n
    int actualSum = 0;
    for (int num : arr) actualSum += num;
    return expectedSum - actualSum;
}

// Test cases
int main() {
    cout << missingInteger({1, 2, 3, 4, 6, 7}, 7) << endl;          // Expected: 5
    cout << missingInteger({1}, 2) << endl;                         // Expected: 2
    cout << missingInteger({1,2,3,4,5,6,7,8,10,11,12}, 12) << endl; // Expected: 9
    return 0;
}
