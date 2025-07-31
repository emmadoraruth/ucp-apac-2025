#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums){        // intial question

      
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    
    unordered_map<int,int> numToIndexMap;
    int count=0;
    for(int i=0;i<nums.size();i++){
           int complement=-nums[i];
           if(numToIndexMap.find(complement)!=numToIndexMap.end()){
                 count++;
                 numToIndexMap.erase(complement);
           }
           else{
              numToIndexMap[nums[i]]=i;
           }
    }
    return count;
}

int countPairsReuse(vector<int>& nums){     // follow up

      
    //Time Complexity: O(n)
    //Space Complexity: O(n)
    
      unordered_map<int,vector<int>>numToIndexMap;
      int count=0;
      for(int i=0;i<nums.size();i++){
          int complement=-nums[i];
          if(numToIndexMap.find(complement)!=numToIndexMap.end()){
                count+=numToIndexMap[complement].size();
          }
          numToIndexMap[nums[i]].push_back(i);
      }
      return count;
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
    cout<<countPairs(v)<<endl;
    cout<<countPairsReuse(v)<<endl;

    return 0;
}