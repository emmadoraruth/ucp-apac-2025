// Given an array of integers and an integer, k, find the maximum mean of a subarray of size k.

// Examples:
// Input Array: [4, 5, -3, 2, 6, 1]
// Input k = 2
// Output: 4.5

// Input Array: [4, 5, -3, 2, 6, 1]
// Input k = 3
// Output: 3

// Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1]
// Input k = 3
// Output: 1

// Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1, 6]
// Input k = 5
// Output: 1

//6:04-

//Time taken:13 min
//Time Complexity:O(n)
//Space Complexity:O(1)
#include<bits/stdc++.h>
using namespace std;
float maxmeansubarray(vector<int>& arr,int k){
    int n=arr.size();
    if(n==0 || k>n) return 0;
    float sum=0;
    float maxmean=INT_MIN;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    maxmean=max(maxmean,sum/k);
    for(int i=k;i<n;i++){
        sum-=arr[i-k];
        sum+=arr[i];
        maxmean=max(maxmean,sum/k);
    }
    return maxmean;
}
int main(){
    vector<int> arr1={4, 5, -3, 2, 6, 1};
    vector<int> arr2={4, 5, -3, 2, 6, 1};
    vector<int> arr3={1, 1, 1, 1, -1, -1, 2, -1, -1};
    vector<int> arr4={1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
    int k1=2;
    int k2=3;
    int k3=3;
    int k4=5;

    float mean1=maxmeansubarray(arr1,k1);
    float mean2=maxmeansubarray(arr2,k2);
    float mean3=maxmeansubarray(arr3,k3);
    float mean4=maxmeansubarray(arr4,k4);
    cout<<"Max Mean of the Subarrays is :";
    cout<<"1)"<<mean1<<endl;
    cout<<"2)"<<mean2<<endl;
    cout<<"3)"<<mean3<<endl;
    cout<<"4)"<<mean4<<endl;
}