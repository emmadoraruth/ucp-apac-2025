#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("Q11_input.txt");
    ofstream out("Q11_output.txt");
    
    int edges;
    in>>edges;
    
    map<string,vector<pair<string,double>>>adj;
    
    for(int i=0;i<edges;i++){
        string u,v;
        double time;
        in>>u>>v>>time;
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
    }
    
    string origin;
    double k;
    in>>origin>>k;
    
    priority_queue<pair<double,string>,vector<pair<double,string>>,greater<pair<double,string>>>pq;
    map<string,double>dist;
    
    for(auto p:adj){
        dist[p.first]=1e9;
    }
    dist[origin]=0;
    pq.push({0,origin});
    
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        
        if(d>dist[node]) continue;
        
        for(auto [next,time]:adj[node]){
            double newDist=d+time+1;
            if(newDist<dist[next]&&newDist<=k){
                dist[next]=newDist;
                pq.push({newDist,next});
            }
        }
    }
    
    set<string>reachable;
    for(auto p:dist){
        if(p.first!=origin&&p.second<=k){
            reachable.insert(p.first);
        }
    }
    
    out<<"[";
    int i=0;
    for(auto city:reachable){
        out<<"\""<<city<<"\"";
        if(i<reachable.size()-1) out<<", ";
        i++;
    }
    out<<"]"<<endl;
    
    in.close();
    out.close();
    return 0;
}
