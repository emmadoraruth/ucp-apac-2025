// Given an integer n and a sorted array of integers of size n-1 which contains all but one of the integers in the range 1-n, find the missing integer.

// Examples:
// Input Array: [1, 2, 3, 4, 6, 7]
// Input n: 7
// Output: 5

// Input Array: [1]
// Input n: 2
// Output: 2

// Input Array: [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12]
// Input n: 12
// Output: 9

//timetaken : 7min
//Time Complexity:O(n)
//Space Complexity:O(1)

#include<bits/stdc++.h>
using namespace std;
int findmissing(vector<int>& arr,int n){
    int  size=arr.size();
    for(int i=0;i<size;i++){
       if(i+1!=arr[i]){
          return i+1;
       }
    }
    return n;
}
int main(){
    vector<int> arr1={1, 2, 3, 4, 6, 7};
    vector<int> arr2={1};
    vector<int> arr3={1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    int n1=7;
    int n2=2;
    int n3=12;
    int miss1=findmissing(arr1,n1);
    int miss2=findmissing(arr2,n2);
    int miss3=findmissing(arr3,n3);
    cout<<miss1<<endl;
    cout<<miss2<<endl;
    cout<<miss3<<endl;
}