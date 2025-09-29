
// Given an array of integers, return the sum of unique elements in the array.

// Examples:
// Input Array: [1, 10, 8, 3, 2, 5, 7, 2, -2, -1]
// Output: 33 (1+10+8+3+2+5+7+-2+-1)

// Input Array: [4, 3, 3, 5, 7, 0, 2, 3, 8, 6]
// Output: 35 (4+3+5+7+0+2+8+6)

//Time complexity: O(n)
//space complexity: O(n) worst case

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int finduniquesum(vector<int>& nums){
    int sum=0;
    unordered_map<int,int> cnt;
    for(auto& i:nums){
        cnt[i]++;
    }
    for(auto& i:cnt){
        sum+=i.first;
    }
    return sum;
}
int main(){
    vector<int> nums1={1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
    vector<int> nums2={4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
    cout<< " (2) "<<finduniquesum(nums1)<<endl;
    cout<<" (1) " <<finduniquesum(nums2)<<endl;
}