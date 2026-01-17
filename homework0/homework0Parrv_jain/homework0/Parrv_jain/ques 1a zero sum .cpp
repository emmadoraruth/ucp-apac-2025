//Time complexity - O(n)
//Space complexity - O(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int twosum(int nums[] ,int size ,  int target){
    
    map<int,int> mpp;
    int pairs = 0 ; 
    
    for(int i = 0 ; i<size ; i++){

        int num = nums[i];
        int required = target - num;

        if(mpp.find(required) != mpp.end() && mpp[required] >0){
            pairs = pairs+1;
            mpp[required] = mpp[required] -1;
        }
        else{
            mpp[num] = mpp[num] +1 ;
        }
    }
    return pairs;
}

int main() {
    
    int arr[10] = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};
    cout <<twosum(arr ,10 , 0);
}

//Time taken - 30 min