#include<bits/stdc++.h>
using namespace std;
//TC:O(n) where n is the size of array
//SC:O(1)

void dedupArray(vector<int>&nums){
       
    if (nums.empty()) return;
    int writeIndex = 1;
    
    for (int readIndex = 1; readIndex < nums.size(); readIndex++) {
        if (nums[readIndex] != nums[writeIndex - 1]) {
            nums[writeIndex] = nums[readIndex];
            writeIndex++;
        }
    }
    nums.resize(writeIndex);

       
}





int main(){
    int n;
    cin >> n;               
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    dedupArray(nums);
    
    for (int num : nums) cout << num << " ";
    




    return 0;
}