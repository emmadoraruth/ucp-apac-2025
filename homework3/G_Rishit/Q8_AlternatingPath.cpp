#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("Q8_input.txt");
    ofstream out("Q8_output.txt");
    
    int edges;
    in>>edges;
    
    map<char,vector<pair<char,string>>>adj;
    
    for(int i=0;i<edges;i++){
        char u,v;
        string color;
        in>>u>>v>>color;
        adj[u].push_back({v,color});
    }
    
    char origin,dest;
    in>>origin>>dest;
    
    queue<tuple<char,int,string>>q;
    map<pair<char,string>,int>visited;
    
    q.push({origin,0,""});
    visited[{origin,""}]=0;
    
    int result=-1;
    
    while(!q.empty()){
        auto [node,dist,lastColor]=q.front();
        q.pop();
        
        if(node==dest){
            result=dist;
            break;
        }
        
        for(auto [next,color]:adj[node]){
            if(lastColor==""||lastColor!=color){
                if(!visited.count({next,color})||visited[{next,color}]>dist+1){
                    visited[{next,color}]=dist+1;
                    q.push({next,dist+1,color});
                }
            }
        }
    }
    
    out<<result<<endl;
    
    in.close();
    out.close();
    return 0;
}
