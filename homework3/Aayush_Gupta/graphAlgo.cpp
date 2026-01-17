#include<bits/stdc++.h>
using namespace std;

bool dfs(int source,int target,map<int,vector<int>>&adj,vector<int>&vis){
    if(source==target) return true;
    vis[source]=1;
    for(int neighbour:adj[source]){
        if(!vis[neighbour]){
            if(dfs(neighbour,target,adj,vis)) return true;
        }
    }
    return false;
}

bool bfs(int source,int target,map<int,vector<int>>&adj,vector<int>&vis){
    queue<int>nodes;
    nodes.push(source);
    vis[source]=1;
    while(!nodes.empty()){
        int currNode=nodes.front();
        nodes.pop();
        if(currNode==target) return true;
        for(int neighbours:adj[currNode]){
            if(!vis[neighbours]){
                vis[neighbours]=1;
                nodes.push(neighbours);
            }
        }
    }
    return false;
}

vector<int> topoSortBfs(map<int,vector<int>>&adj){
    map<int,int> indegree;
    for(auto vertex:adj){
        if(!indegree.count(vertex.first))
            indegree[vertex.first]=0;
        for(int neighbour:vertex.second){
            indegree[neighbour]++;
        }
    }

    queue<int>nodes;
    for(auto x:indegree){
        if(x.second==0)
            nodes.push(x.first);
    }

    vector<int>topoSort;
    while(!nodes.empty()){
        int currNode=nodes.front();
        nodes.pop();
        topoSort.push_back(currNode);
        for(int neighbours:adj[currNode]){
            indegree[neighbours]--;
            if(indegree[neighbours]==0)
                nodes.push(neighbours);
        }
    }
    return topoSort;
}

void topoSortDfs(int source,map<int,vector<int>>&adj,vector<int>&visited,stack<int>&topoSort){
    visited[source]=1;
    for(int neighbours:adj[source]){
        if(!visited[neighbours]){
            topoSortDfs(neighbours,adj,visited,topoSort);
        }
    }
    topoSort.push(source);
}

map<int,vector<int>> createAdjacency(vector<pair<int,int>>&edges){
    map<int,vector<int>>adj;
    for(auto edge:edges){
        int sourceVertex=edge.first;
        int destVertex=edge.second;
        adj[sourceVertex].push_back(destVertex);
        if(!adj.count(destVertex))
            adj[destVertex]={};
    }
    return adj;
}

int main(){
    vector<pair<int,int>>edges={{1,2},{2,3},{1,3},{3,2},{2,0}};
    map<int,vector<int>>adj=createAdjacency(edges);

    for(auto x:adj){
        cout<<x.first<<" : ";
        for(int y:x.second) cout<<y<<" ";
        cout<<endl;
    }

    vector<int>vis(10,0);
    cout<<dfs(1,0,adj,vis)<<endl;

    fill(vis.begin(),vis.end(),0);
    cout<<bfs(1,0,adj,vis)<<endl;

    vector<int>topo1=topoSortBfs(adj);
    for(int x:topo1) cout<<x<<" ";
    cout<<endl;

    vector<int>visited(10,0);
    stack<int>st;
    for(auto x:adj){
        if(!visited[x.first])
            topoSortDfs(x.first,adj,visited,st);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}
