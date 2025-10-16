// Problem Statement
/* Given an integer n and a sorted array of integers of size n-1 which contains all but one of the integers in the range 1-n, find the missing integer.*/

// Technique: Mathematical Formula
// Time Complexity: O(n), n is the length of the array
// Space Complexity: O(1), just used few variables

#include <bits/stdc++.h>
using namespace std;

// Using Mathematical Formula O(n)
int missingInteger(vector<int> arr, int n){
    int total = n * (n + 1) / 2;
    int sum = 0;
    for(int num : arr){
        sum += num;
    }
    return total - sum;
}

// Using Binary Search O(log n)
int binsearch(vector<int> arr){
    int left = 0, right = arr.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == mid + 1){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 6, 7};
    cout << missingInteger(arr, arr.size()+1) << "\n"; // Output: 4
    cout << binsearch(arr) << "\n\n"; // Output: 4

    arr = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    cout << missingInteger(arr, arr.size()+1) << "\n"; // Output: 9
    cout << binsearch(arr) << "\n\n"; // Output: 9
}

