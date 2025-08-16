// Problem Statement
/* Given an array of integers, return the number of pairs of integers in the array that sum to 0 assuming you can use the element at each index at most once. */

// Time Complexity: O(n), n is the length of the array
// Space Complexity: O(n) for map in worst case if all elements are unique.

#include <bits/stdc++.h>
using namespace std;

int pairs (vector<int> arr){
    unordered_map<int,int> count;

    for(int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
    }

    int ans = 0;
    for(auto it : count){
        int x = it.first;
        if(x < 0) continue;
        if(x == 0) {
            ans += it.second / 2;
            continue;
        }
        int y = -x;
        if(count.find(y) != count.end()){
            ans += min(it.second, count[y]);
        }
    }
    return ans;
}


// Modified pairs for follow question
int mod_pairs (vector<int> arr) {
    unordered_map<int,int> count;

    for(int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
    }
    int ans = 0;
    for(auto it : count){
        int x = it.first;
        if(x < 0) continue;
        if(x == 0) {
            ans += it.second * (it.second-1) / 2;
            continue;
        }
        int y = -x;
        if(count.find(y) != count.end()){
            ans += it.second* count[y];
        }
    }
    return ans;
}

int main(){
     vector<vector<int>> testCases = {
        {1, 10, 8, 3, 2, 5, 7, 2, -2, -1},
        {1, 10, 8, -2, 2, 5, 7, 2, -2, -1},
        {4, 3, 3, 5, 7, 0, 2, 3, 8, 6},
        {4, 3, 3, 5, 7, 0, 2, 3, 8, 0}
    };

   for (int i = 0; i < testCases.size(); i++) {
    cout << mod_pairs(testCases[i]) << endl;
   }
}

// First pair function took 12 mins then next follow up in 5 mins, so about 20 mins including testing all cases.
