#include <bits/stdc++.h>
using namespace std;

int ZeroSum(vector<int>& nums, int n){
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++){
        freq[nums[i]]++;
    }

    int ans=0;
    for(auto& x:freq){
        int num=x.first;
        if(num>=0){
            if(num==0){
                ans+=freq[0]/2;
            } 
            else{
                auto it=freq.find(-num);
                if (it!=freq.end()){
                    ans+=min(x.second, it->second);
                }
            }
        }
    }
    return ans;
}

int ZeroSumFollowUp(const vector<int>& nums, int n){
    unordered_map<int, int> seen;
    int ans=0;
    for (int i=0; i<n; i++) {
        ans+=seen[-nums[i]];
        seen[nums[i]]++;
    }
    return ans;
}

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }

    cout<< ZeroSum(nums, n)<< endl;
    cout<< ZeroSumFollowUp(nums, n)<< endl;
    return 0;
}
