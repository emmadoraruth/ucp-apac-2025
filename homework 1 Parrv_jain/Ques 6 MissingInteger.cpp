#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// tc=O(n)
// sc=O(n) 
// Approach: Use a hashmap to track positive integers and find the smallest missing one.
// TIMETAKEN:20MINS

int MissingInteger(vector<int> arr) {
    unordered_map<int, bool> mp;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0)
            mp[arr[i]] = true;
    }
    for (int i = 1; i <= arr.size() + 1; i++) {
        if (mp.find(i) == mp.end()) {
            return i;
        }
    }
    return -1;
}

int main(){
cout << MissingInteger({1, 2, 3, 4, 6, 7}) << endl;          // Expected: 5
cout << MissingInteger({1}) << endl;                         // Expected: 2
cout << MissingInteger({1,2,3,4,5,6,7,8,10,11,12}) << endl;  // Expected: 9
}


