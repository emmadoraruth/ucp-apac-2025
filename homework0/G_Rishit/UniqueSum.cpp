#include <bits/stdc++.h>
using namespace std;

int UniqueSum(const vector<int>& nums,int n){
    unordered_map<int,bool> umap;
    int sum=0;
    for (int i=0; i<n; i++){
        int j= nums[i];
        if (!umap[j]){      //if umap[j]==0 the number at index j has not been encountered before in the array and hence is unique
            sum+=j; 
            umap[j]=true;
        }
    }
    return sum;
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

    cout<< UniqueSum(nums, n)<< endl;
    return 0;
}
//took me about 10 minutes to solve this question and write the code for it
// T.C O(n)   S.C O(n)
