// Question 1: ZeroSum
// Given an array of integers, return the number of pairs of integers in the array that sum to 0 assuming you can use the element at each index at most once.
#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[]={1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
    unordered_map<int,int> app;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        app[arr[i]]++;
    }
    int sum=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[1]);i++){
        int b=-arr[i];
        if(app.find(b)!=app.end()){
            sum++;
        }
    }
    cout<<sum/2;
}
