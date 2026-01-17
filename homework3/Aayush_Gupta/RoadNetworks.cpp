#include<bits/stdc++.h>
using namespace std;

void dfs(string node,map<string,vector<string>>&adj,map<string,int>&vis){
    vis[node]=1;
    for(string nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,adj,vis);
        }
    }
}

int roadNetworks(vector<string>& towns,vector<pair<string,string>>& roads){
    map<string,vector<string>> adj;
    for(string t:towns){
        adj[t]={};
    }

    for(auto r:roads){
        adj[r.first].push_back(r.second);
        adj[r.second].push_back(r.first);
    }

    map<string,int> vis;
    int networks=0;

    for(string t:towns){
        if(!vis[t]){
            networks++;
            dfs(t,adj,vis);
        }
    }
    return networks;
}

int main(){
    vector<string> towns={
        "Skagway","Juneau","Gustavus","Homer","Port Alsworth",
        "Glacier Bay","Fairbanks","McCarthy","Copper Center",
        "Healy","Anchorage"
    };

    vector<pair<string,string>> roads={
        {"Anchorage","Homer"},
        {"Homer","Glacier Bay"},
        {"Glacier Bay","Gustavus"},
        {"Copper Center","McCarthy"},
        {"Anchorage","Copper Center"},
        {"Copper Center","Fairbanks"},
        {"Healy","Fairbanks"},
        {"Healy","Anchorage"}
    };

    cout<<roadNetworks(towns,roads)<<endl;
    return 0;
}
