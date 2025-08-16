// Problem Statement
// Given an array of integers, return the sum of unique elements in the array.

// Time Complexity: O(n), n is the length of the array
// Space Complexity: O(n), for storing unique elements

#include <bits/stdc++.h>
using namespace std;

int unqsum(vector<int> arr){
    unordered_set<int> unqelements;
    for(int i = 0; i < arr.size(); i++){
        unqelements.insert(arr[i]);
    }
    
    long long int sum = 0;
    // assuming sum can be large after summation of ints.

    for(auto it : unqelements){
        sum += it;
    }
    return sum;
}

int main(){
    vector<vector<int>> arr = {{1, 10, 8, 3, 2, 5, 7, 2, -2, -1},{4, 3, 3, 5, 7, 0, 2, 3, 8, 6}};

    for (int i = 0; i < arr.size(); i++) {
        cout << unqsum(arr[i]) << endl;
    }
}

// As the question explicitly states that we need to find the sum of UNIQUE elements therefore we can get idea of using set. used unordered_set because no use of ordering (sum is associative) and insertion is O(1) on average.

// Took 15 mins at max including testing