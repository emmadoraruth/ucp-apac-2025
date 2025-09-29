#include<bits/stdc++.h>
using namespace std;
//TC: O(nlogn)
//SC: O(n)
vector<pair<int,int>> mergedIntervals(vector<pair<int,int>>&pairList){
      if(pairList.empty()) return {};
      sort(pairList.begin(),pairList.end());
      vector<pair<int,int>>mergedPairs;
      int currentStart=pairList[0].first;
      int currentEnd=pairList[0].second;
      for(int i=1;i<pairList.size();i++){
          int start=pairList[i].first;
          int end=pairList[i].second;
          if(start<=currentEnd){
               currentEnd=max(end,currentEnd);
          }
          else{
              mergedPairs.push_back({currentStart,currentEnd});
              currentStart=start;
              currentEnd=end;
          }
      }
      mergedPairs.push_back({currentStart,currentEnd});
      return mergedPairs;

}




int main(){
    int n;
    cin >> n;  
    vector<pair<int, int>> intervals(n);
    
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    vector<pair<int, int>> result = mergedIntervals(intervals);
    
    for (auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
       
}