#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

// Build adjacency list from edges
map<int, vector<int>> adjacencySet(vector<pair<int, int>> edges) {
    map<int, vector<int>> graph;
    
    for(auto edge : edges) {
        int u = edge.first;
        int v = edge.second;  
        
        // Ensure both nodes exist in graph
        graph[u];
        graph[v];
        
        // Add directed edge u -> v
        graph[u].push_back(v);
    }
    
    // Sort adjacency lists
    for(auto& it : graph) {
        sort(it.second.begin(), it.second.end());
    }
    
    return graph;
}

// BFS to find target node
bool bfs(int target, map<int, vector<int>> graph) {
    if(graph.empty()) return false;
    vector<int> visited(graph.size()+1, 0);
     
    for(auto& it : graph) {
        if(!visited[it.first]) {
            queue<int> q;
            q.push(it.first);
            visited[it.first] = 1;
            
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                
                if(curr == target) return true;
                
                for(int neighbor : graph[curr]) {
                    if(!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    
    return false;
}

// DFS helper function
bool dfsHelper(int curr, int target, map<int, vector<int>>& graph, vector<int>& visited) {
    if(curr == target) {
        return true;
    }
    
    visited[curr] = 1;
    
    for(int neighbor : graph[curr]) {
        if(!visited[neighbor]) {
            if(dfsHelper(neighbor, target, graph, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

// DFS to find target node
bool dfs(int target, map<int, vector<int>> graph) {
    if(graph.empty()) return false;
    
    vector<int> visited(graph.size()+1, 0);
    
    // Try starting from each unvisited node
    for(auto& it : graph) {
        if(!visited[it.first]) {
            if(dfsHelper(it.first, target, graph, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

// Topological Sort using BFS (Kahn's Algorithm)
vector<int> topologicalSort(map<int, vector<int>> graph) {
    vector<int> result;
    vector<int> indegree(graph.size()+1, 0);
    
    // Initialize indegree for all nodes
    for(auto& it : graph) {
        for(int neighbor : it.second) {
            indegree[neighbor]++;
        }
    }
    
    // Find all nodes with indegree 0
    queue<int> q;
    for(int i = 0; i < indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Process nodes in topological order
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        
        // Reduce indegree for neighbors
        for(int neighbor : graph[curr]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    
    return result;
}

// DFS helper for topological sort
void topoDfsHelper(int node, map<int, vector<int>>& graph, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;
    
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            topoDfsHelper(neighbor, graph, visited, st);
        }
    }
    
    st.push(node);
}

// Topological Sort using DFS
vector<int> topologicalSortDfs(map<int, vector<int>> graph) {
    vector<int> visited(graph.size()+1, 0);
    stack<int> st;
    
    // Visit all nodes
    for(auto& it : graph) {
        if(!visited[it.first]) {
            topoDfsHelper(it.first, graph, visited, st);
        }
    }
    
    // Pop from stack to get topological order
    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

// Test function
int main() {
    // Example from problem
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    
    map<int, vector<int>> graph = adjacencySet(edges);
    
    cout << "Adjacency Set:" << endl;
    for(auto& p : graph) {
        cout << p.first << ": [";
        for(int neighbor : p.second) {
            cout << neighbor << " ";
        }
        cout << "]" << endl;
    }
    
    
    
    return 0;
}
