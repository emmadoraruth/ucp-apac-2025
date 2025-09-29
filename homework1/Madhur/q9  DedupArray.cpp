/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates in a sorted array
void dedupArray(vector<int>& arr) {
    if(arr.empty()) return;

    int write = 0; // Position to write next unique element

    for(int read = 1; read < arr.size(); read++) {
        if(arr[read] != arr[write]) {
            write++;
            arr[write] = arr[read];
        }
    }

    // Fill the rest of the array with -1
    for(int i = write+1; i < arr.size(); i++) {
        arr[i] = -1;
    }
}

// Helper function to print array
void printArray(const vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << endl;
}

// Test cases
int main() {
    vector<int> v1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    dedupArray(v1);
    printArray(v1); // Expected: 1 2 3 4 -1 -1 -1 -1 -1 -1

    vector<int> v2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    dedupArray(v2);
    printArray(v2); // Expected: 0 1 4 5 8 9 10 11 15 -1 -1 -1 -1 -1

    vector<int> v3 = {1, 3, 4, 8, 10, 12};
    dedupArray(v3);
    printArray(v3); // Expected: 1 3 4 8 10 12
}
