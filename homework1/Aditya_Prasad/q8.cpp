// T.C = O(nlogn + n + n + n) = O(nlogn)
// M.C = O(n) due to stack
// Time Taken = 40 min, but took a lot of time in implementing it

#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> v){
    sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;  
    }); // O(nlogn)

    stack<pair<int,int>> st;
    
    for(auto interval : v){ // O(n)
        if(st.empty()) st.push(interval);
        else{
            if(interval.first <= st.top().second){ // they overlap
                st.top().second = max(st.top().second, interval.second); // largest interval will be considered
            }else{
                st.push(interval);
            }
        }
    }

    vector<pair<int,int>> ans;

    while(!st.empty()){ //O(n)
        ans.push_back({st.top().first, st.top().second});
        st.pop();
    } 

    return ans;
}
int main(){
    vector<pair<int,int>> v1Ans = mergeIntervals({{2,3},{4,8},{1,2},{5,7},{9,12}});
    
    for(auto pair : v1Ans){ // O(n)
        cout << "(" << pair.first << "," << pair.second << ") ";
    }
    cout << endl;
    
}