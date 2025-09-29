#include<bits/stdc++.h>
using namespace std;
//TC: O(n)
//SC: O(1)
double maxMean(vector<int>&nums,int subArraySize){
       if(subArraySize>nums.size()) return -1;
       double windowSum=0;
       for(int start=0;start<subArraySize;start++){
           windowSum+=nums[start];
       }
       double maxWindowSum=windowSum;
       for(int start=subArraySize;start<nums.size();start++){
           windowSum=windowSum+nums[start]-nums[start-subArraySize];
           maxWindowSum=max(windowSum,maxWindowSum);
       }
       double maximumMean=(maxWindowSum/subArraySize);
       return maximumMean;

}



int main(){
     int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    double result = maxMean(arr, k);
    if (result == -1)
        cout << "Invalid Input";
    else
        cout << result;
        
    return 0;
     
}