#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> nums, int n) {
    int low = 0;
    int high = n - 2;
    
    // Binary search to find the position where the sequence breaks
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If element at mid equals mid+1, missing number is on right side
        if (nums[mid] == mid + 1) {
            low = mid + 1;
        } else {
            // Missing number is on left side
            high = mid - 1;
        }
    }
    
    // The missing number is low + 1
    return low + 1;
}

int main() {
    vector<int> test1 = {1, 2, 3, 4, 6, 7};
    vector<int> test2 = {1};
    vector<int> test3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    
    cout << findMissingNumber(test1, 7) << endl;  // Expected: 5
    cout << findMissingNumber(test2, 2) << endl;  // Expected: 2
    cout << findMissingNumber(test3, 12) << endl; // Expected: 9
    
    return 0;
}

// T.C = O(log n)
// S.C = O(1)
// Approach: Binary search on sorted array