#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicatesInPlace(vector<int> nums) {
    if (nums.empty()) return nums;
    
    int writeIndex = 0;
    
    for (int readIndex = 1; readIndex < nums.size(); readIndex++) {
        if (nums[readIndex] != nums[writeIndex]) {
            writeIndex++;
            nums[writeIndex] = nums[readIndex];
        }
    }
    
    // For static array ,fill remaining positions with -1
    for (int i = writeIndex + 1; i < nums.size(); i++) {
        nums[i] = -1;
    }
    
    return nums;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> test1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<int> result1 = removeDuplicatesInPlace(test1);
    printArray(result1);  // Expected: 1 2 3 4 -1 -1 -1 -1 -1 -1
    
    vector<int> test2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    vector<int> result2 = removeDuplicatesInPlace(test2);
    printArray(result2);  // Expected: 0 1 4 5 8 9 10 11 15 -1 -1 -1 -1 -1
    
    vector<int> test3 = {1, 3, 4, 8, 10, 12};
    vector<int> result3 = removeDuplicatesInPlace(test3);
    printArray(result3);  // Expected: 1 3 4 8 10 12
    
    return 0;
}

// T.C = O(n)
// S.C = O(1) - modifying array in place
// Approach: Two-pointer technique with -1 padding for static arrays