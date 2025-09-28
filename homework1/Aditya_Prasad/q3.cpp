#include <bits/stdc++.h>
using namespace std;

int ZeroSumSubArrays(vector<int> v){
    unordered_map<int,int> freq; 
    int count =0;
    int sum =0;

    for(int num : v){
        sum += num;

        if(sum ==0) count++; // from start
        if(freq.find(sum)!= freq.end()) 
            count += freq[sum];

        freq[sum] ++;
    }

    return count;
}

int main() {
    cout<< ZeroSumSubArrays({4,5,2,-1,-3,-3,4,6,-7}) ;
}
