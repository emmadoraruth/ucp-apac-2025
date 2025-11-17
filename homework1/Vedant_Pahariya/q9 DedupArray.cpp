// Problem Statement
/* Given a sorted array of non-negative integers, modify the array by removing duplicates so each element only appears once. If arrays are static (aka, not dynamic/resizable) in your language of choice, the remaining elements should appear in the left-hand side of the array and the extra space in the right-hand side should be padded with -1s.*/

// Technique: Two-pointer approach
// Time Complexity: O(n), n is the length of the array
// Space Complexity: Modifing the original array, O(1) extra space for mainting count variable

#include <bits/stdc++.h>
using namespace std;

vector<int> dedupArray(vector<int> &arr){

    // cout << arr.size() << "\n";
    int count_dup = 0;

    for(int i=1 ; i < arr.size(); i++){
        if (arr[i]== arr[i-1]){
            count_dup++;
        }
        else {
            arr[i-count_dup]=arr[i];
        }
    }

    if(count_dup > 0){
        for(int i = arr.size() - count_dup; i < arr.size(); i++){
            arr[i] = -1;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    dedupArray(arr);
    for(int num : arr){
        cout << num << " ";
    }
    cout << "\n";

    arr = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    dedupArray(arr);
    for(int num : arr){
        cout << num << " ";
    }
    cout << "\n";

    arr = {1, 3, 4, 8, 10, 12};
    dedupArray(arr);
    for(int num : arr){
        cout << num << " ";
    }
    cout << "\n";

    arr = {};
    dedupArray(arr);
    for(int num : arr){
        cout << num << " ";
    }
    cout << "\n";
}

// Thinking Process
/*
This was straight forward question, got its approach in first attempt. 
As sorted array was already given and we have to remove duplicates, duplicates will be consecutively arranged because of sorting so we can just have to check adjacent elements.

And the number of duplicate elements will be the number of -1 in the array so initialized a counter variable for mainting duplicate counts. At the end, updated the last elements with -1 according to the counter.
*/