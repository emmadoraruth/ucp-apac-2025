//Time complexity - O(n)
//Space complexity - O(n)

#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

int unique(int arr[] , int n ){
    
    map<int,int> mpp;
    int sum = 0 ; 
    for(int i = 0 ; i<n ; i++){
        mpp[arr[i]]++;
    }
    
    for(auto i : mpp){
        if(i.second >= 1 ){
            sum = sum + i.first;
        }
    }
    return sum ; 
}


int main(){
    
    int arr[50]={4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
    cout<<unique(arr , 50);
}

//Time taken - 10 min