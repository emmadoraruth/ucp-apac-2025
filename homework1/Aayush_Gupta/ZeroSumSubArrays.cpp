#include<bits/stdc++.h>
using namespace std;
//TC:O(n)
//SC:O(n)
int countZeroSumSubArrays(vector<int>&nums){
     unordered_map<int,int>sumFreqMap;
     int prefixSum=0;
     int count=0;
     for(int start=0;start<nums.size();start++){
         prefixSum+=nums[start];
         if(prefixSum==0) count++;
         if(sumFreqMap.find(prefixSum)!=sumFreqMap.end()){
            count+=sumFreqMap[prefixSum];
         }
         sumFreqMap[prefixSum]++;

     }
     return count;
}




int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << countZeroSumSubArrays(arr);
    return 0;
}