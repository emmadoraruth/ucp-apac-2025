#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int tgt,map<int,vector<int>>&adj,vector<int>&vis){
    if(src==tgt) return true;
    vis[src]=1;
    for(int nb:adj[src]){
        if(!vis[nb]){
            if(dfs(nb,tgt,adj,vis)) return true;
        }
    }
    return false;
}

bool bfs(int src,int tgt,map<int,vector<int>>&adj,vector<int>&vis){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr==tgt) return true;
        for(int nb:adj[curr]){
            if(!vis[nb]){
                vis[nb]=1;
                q.push(nb);
            }
        }
    }
    return false;
}

vector<int> topoKahn(map<int,vector<int>>&adj){
    map<int,int> ind;
    for(auto v:adj){
        if(!ind.count(v.first))
            ind[v.first]=0;
        for(int nb:v.second){
            ind[nb]++;
        }
    }
    queue<int>q;
    for(auto x:ind){
        if(x.second==0)
            q.push(x.first);
    }
    vector<int>topo;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        topo.push_back(curr);
        for(int nb:adj[curr]){
            ind[nb]--;
            if(ind[nb]==0)
                q.push(nb);
        }
    }
    return topo;
}

void topoDfs(int src,map<int,vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[src]=1;
    for(int nb:adj[src]){
        if(!vis[nb]){
            topoDfs(nb,adj,vis,st);
        }
    }
    st.push(src);
}

map<int,vector<int>> buildAdj(vector<pair<int,int>>&edges){
    map<int,vector<int>>adj;
    for(auto edge:edges){
        int u=edge.first;
        int v=edge.second;
        adj[u].push_back(v);
        if(!adj.count(v))
            adj[v]={};
    }
    return adj;
}

int main(){
    ifstream in("Q1_input.txt");
    ofstream out("Q1_output.txt");

    int n;
    in>>n;
    vector<pair<int,int>>edges(n);
    int maxNode=0;
    for(int i=0;i<n;i++){
        in>>edges[i].first>>edges[i].second;
        maxNode=max(maxNode,max(edges[i].first,edges[i].second));
    }

    map<int,vector<int>>adj=buildAdj(edges);

    out<<"Adjacency List:"<<endl;
    for(auto x:adj){
        out<<x.first<<":";
        for(int y:x.second) out<<" "<<y;
        out<<endl;
    }
    out<<endl;

    int q;
    in>>q;
    out<<"DFS Results:"<<endl;
    for(int i=0;i<q;i++){
        int src,tgt;
        in>>src>>tgt;
        vector<int>vis(maxNode+1,0);
        bool res=dfs(src,tgt,adj,vis);
        out<<src<<" -> "<<tgt<<": "<<(res?"Found":"Not Found")<<endl;
    }
    out<<endl;

    in>>q;
    out<<"BFS Results:"<<endl;
    for(int i=0;i<q;i++){
        int src,tgt;
        in>>src>>tgt;
        vector<int>vis(maxNode+1,0);
        bool res=bfs(src,tgt,adj,vis);
        out<<src<<" -> "<<tgt<<": "<<(res?"Found":"Not Found")<<endl;
    }
    out<<endl;

    out<<"Topological Sort (Kahn's Algorithm):"<<endl;
    vector<int>topoK=topoKahn(adj);
    for(int x:topoK) out<<x<<" ";
    out<<endl;
    out<<endl;

    out<<"Topological Sort (DFS):"<<endl;
    vector<int>vis(maxNode+1,0);
    stack<int>st;
    for(auto x:adj){
        if(!vis[x.first])
            topoDfs(x.first,adj,vis,st);
    }
    while(!st.empty()){
        out<<st.top()<<" ";
        st.pop();
    }
    out<<endl;

    in.close();
    out.close();
    return 0;
}
