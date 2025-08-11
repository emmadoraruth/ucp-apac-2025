//Given an array of integers, return the number of pairs of integers in the array that sum to 0 assuming you can use the element at each index at most once.

//Time complexity: O(n)
//space complexity: O(n)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findzeropairs(vector<int>& nums){
    int pairs=0;
    unordered_map<int,int> cnt;
    for(auto& i:nums){
        if(cnt.count(-i) && cnt[-i]>0){
            pairs++;        
            cnt[-i]--;                   
        }
        else{
            cnt[i]++;
        }
    }
    return pairs;
}
int main(){
    vector<int> nums1={1, 10, 8, 3, 2, 5, 7, 2, -2, -1};  //gives output: 2
    vector<int> nums2={1, 10, 8, -2, 2, 5, 7, 2, -2, -1}; //gives output: 3
    vector<int> nums3={4, 3, 3, 5, 7, 0, 2, 3, 8, 6};     //gives output:0
    vector<int> nums4={4, 3, 3, 5, 7, 0, 2, 3, 8, 0};     //gives output:1
      
    cout<<" 1)Pairs to make a zero  :-  "<< findzeropairs(nums1)<<endl;
    cout<<" 2)Pairs to make a zero  :-  "<<findzeropairs(nums2)<<endl;
    cout<<" 3)Pairs to make a zero  :-  "<<findzeropairs(nums3)<<endl;
    cout<<" 4)Pairs to make a zero  :-  "<<findzeropairs(nums4)<<endl;
    
}