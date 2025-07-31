#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlogn)
//Space Complexity: O(n)


int uniqueSum(vector<int>&nums){
    int distinctSum=0;
    if(nums.size()==0){
        return 0;
    }
    set<int>s;
    for(int x:nums){
        s.insert(x);
    }
    for(int x:s){
        distinctSum+=x;
    }
    return distinctSum;
    
}



int main(){
        
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }

    cout<<uniqueSum(v)<<endl;


    return 0;
}