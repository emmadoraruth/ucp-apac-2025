// Given a list of integer pairs representing the low and high end of an interval, inclusive, return a list in which overlapping intervals are merged.

// Examples:

// Input: [(2, 3), (4, 8), (1, 2), (5, 7), (9, 12)]
// Output: [(4, 8), (1, 3), (9, 12)]

// Input: [(5, 8), (6, 10), (2, 4), (3, 6)]
// Output: [(2, 10)]

// Input: [(10, 12), (5, 6), (7, 9), (1, 3)]
// Output: [(10, 12), (5, 6), (7, 9), (1, 3)]

//timetaken: 25 min
//Time complexity:O(nlogn)   due to sorting of the array
//Space Complexity:O(n)

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> mergeinterval(vector<pair<int,int>> arr){
    vector<pair<int,int>> ans;
    int n=arr.size();
    if(n==0){
        return ans;
    }
    sort(arr.begin(),arr.end());  //will sort in ascending order by pair;s first element

    stack<pair<int,int>> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        pair<int,int> topof=s.top();
        if(arr[i].first<=topof.second)
             s.top().second=max(s.top().second,arr[i].second);
        else{
            s.push(arr[i]);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    sort(ans.begin(),ans.end());  //will sort the ans

    return ans;
}
int main(){
    vector<pair<int,int>> arr1={{2, 3}, {4, 8}, {1,2}, {5, 7}, {9, 12}};
    vector<pair<int,int>> arr2={{5, 8}, {6, 10}, {2, 4}, {3, 6}};
    vector<pair<int,int>> arr3={{10, 12}, {5, 6}, {7, 9}, {1, 3}};
    vector<pair<int,int>> merge1=mergeinterval(arr1);
    vector<pair<int,int>> merge2=mergeinterval(arr2);
    vector<pair<int,int>> merge3=mergeinterval(arr3);
    cout<<"Interval of first case is :"<<endl;
    for(auto& i:merge1){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
     cout<<"Interval of Secondṇ case is :"<<endl;
    for(auto& i:merge2){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl; cout<<"Interval of Third case is :"<<endl;
    for(auto& i:merge3){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
}
