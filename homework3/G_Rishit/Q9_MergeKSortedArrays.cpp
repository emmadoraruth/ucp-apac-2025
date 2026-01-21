#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("Q9_input.txt");
    ofstream out("Q9_output.txt");
    
    int k;
    in>>k;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<vector<int>>arrays(k);
    
    for(int i=0;i<k;i++){
        int sz;
        in>>sz;
        arrays[i].resize(sz);
        for(int j=0;j<sz;j++){
            in>>arrays[i][j];
        }
        pq.push({arrays[i][0],{i,0}});
    }
    
    vector<int>result;
    
    while(!pq.empty()){
        auto [val,indices]=pq.top();
        pq.pop();
        int arrIdx=indices.first;
        int elemIdx=indices.second;
        
        result.push_back(val);
        
        if(elemIdx+1<arrays[arrIdx].size()){
            pq.push({arrays[arrIdx][elemIdx+1],{arrIdx,elemIdx+1}});
        }
    }
    
    out<<"[";
    for(int i=0;i<result.size();i++){
        out<<result[i];
        if(i<result.size()-1) out<<", ";
    }
    out<<"]"<<endl;
    
    in.close();
    out.close();
    return 0;
}
