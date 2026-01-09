
// Assumptions:
// 1. Node 0 is assumed to be starting node in the graph traversal;
// 2. The graph is assumed to be a single connected component for traversal.

// adjList - TC: O(E), MC: O(V + E)
// bfs - TC: O(V + E), MC: O(V)
// dfs - TC: O(V + E), MC: O(V)
// topologicalSort - TC: O(V + E), MC: O(V)


#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjList(vector<vector<int>> edges){
    unordered_map<int,vector<int>> adj;

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v); // u -> v
        adj[v];
    }

    return adj;
}

bool bfs(int target, unordered_map<int, vector<int>>& graph){
    int startNode = 0;

    if(startNode == target) return true;
    queue<int> q;
    q.push(startNode);

    set<int> visited;
    visited.insert(startNode);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int nbr : graph[node]){
            if(nbr == target) return true;
            if(visited.count(nbr) == 0){
                q.push(nbr);
                visited.insert(nbr);
            }
        }
    }

    return false;

}

void dfsSearch(int node, int target, unordered_map<int, vector<int>>& graph, set<int>& visited, bool& found){

    if(found == true) return;

    visited.insert(node);

    if(node == target){
        found = true;
        return;
    }

    for(int nbr : graph[node]){
        if(visited.count(nbr) == 0){
            dfsSearch(nbr, target, graph, visited, found);
        }
    }
}

bool dfs(int target, unordered_map<int, vector<int>>& graph){
    int n = graph.size();

    set<int> visited;

    bool found = false;

    int startNode = 0;

    dfsSearch(startNode, target, graph, visited, found);

    return found;
}

vector<int> topologicalSort(unordered_map<int, vector<int>>& graph){
    int n = graph.size();

    unordered_map<int, int> indegree;

    for(auto [node, neighbours] : graph){
        indegree[node] = 0; 
    }

    for(auto [node, neighbours] : graph){
        for(int nbr : neighbours){
            indegree[nbr]++;
        }
    }

    queue<int> q;

    for(auto [node, neighbours] : graph){
        if(indegree[node] == 0) q.push(node); // pushing all the nodes with zero depedencies
    }

    vector<int> topoSort;

    while(!q.empty()){
        int node = q.front();
        topoSort.push_back(node);
        q.pop();

        

        for(int nbr : graph[node]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    return topoSort;
}

void dfsTopo(int node, unordered_map<int, vector<int>>& graph,  unordered_set<int>& visited, vector<int>& topoSort){
    visited.insert(node);

    for(int nbr : graph[node]){
        if(visited.count(nbr) == 0){
            dfsTopo(nbr, graph, visited, topoSort);
        }
    }
    topoSort.push_back(node);
}


vector<int> topologicalSortDfs(vector<vector<int>> edges){
    unordered_set<int> visited;
    vector<int> topoSort;
    int startNode = 0;

    unordered_set<int> nodes;

    unordered_map<int, vector<int>> graph;

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        nodes.insert(u);
        nodes.insert(v);
    }

    for (int node : nodes) {
        if(visited.count(node) == 0){
            dfsTopo(node, graph, visited, topoSort);
        }
    }

    reverse(topoSort.begin(), topoSort.end());

    return topoSort;

}

// Time Taken - 93 mins