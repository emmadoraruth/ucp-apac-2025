// Question 1 : Graph ALgorithms
// Time Taken : 1 hours 29 minutes

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

map<int, set<int>> BuildGraph(vector<pair<int,int>> edges){
    map<int, set<int>> graph;

    for(auto e : edges){
        int u = e.first;
        int v = e.second;

        graph[u].insert(v);

        // ensure v exists even if it has no outgoing edges
        if(graph.find(v) == graph.end()){
            graph[v] = {};
        }
    }

    return graph;
}

bool BFS(int target, map<int, set<int>> &graph){
    set<int> visited;
    queue<int> q;

    for(auto node : graph){
        int start = node.first;
        if(visited.count(start)) continue;

        q.push(start);
        visited.insert(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == target) return true;

            for(int nei : graph[curr]){
                if(!visited.count(nei)){
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
    }
    return false;
}

bool DFSHelper(int node, int target,
             map<int, set<int>> &graph,
             set<int> &visited){

    if(node == target) return true;

    visited.insert(node);

    for(int nei : graph[node]){
        if(!visited.count(nei)){
            if(DFSHelper(nei, target, graph, visited))
                return true;
        }
    }
    return false;
}

bool DFS(int target, map<int, set<int>> &graph){
    set<int> visited;

    for(auto node : graph){
        int start = node.first;
        if(!visited.count(start)){
            if(DFSHelper(start, target, graph, visited))
                return true;
        }
    }
    return false;
}

vector<int> TopologicalSort(map<int, set<int>> &graph){
    map<int, int> indegree;

    // initialize indegree
    for(auto node : graph){
        indegree[node.first] = 0;
    }

    for(auto node : graph){
        for(int nei : node.second){
            indegree[nei]++;
        }
    }

    queue<int> q;
    for(auto x : indegree){
        if(x.second == 0)
            q.push(x.first);
    }

    vector<int> topo;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for(int v : graph[u]){
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    return topo;
}

void TopoDFSHelper(int node,
                 map<int, set<int>> &graph,
                 set<int> &visited,
                 vector<int> &order){

    visited.insert(node);

    for(int nei : graph[node]){
        if(!visited.count(nei)){
            TopoDFSHelper(nei, graph, visited, order);
        }
    }

    order.push_back(node);
}

vector<int> TopologicalSortDFS(map<int, set<int>> &graph){
    set<int> visited;
    vector<int> order;

    for(auto node : graph){
        if(!visited.count(node.first)){
            TopoDFSHelper(node.first, graph, visited, order);
        }
    }

    reverse(order.begin(), order.end());
    return order;
}

int main(){
    
    // Testing the Graph Algorithms
   
    vector<pair<int,int>> edges = {
        {1,2}, {2,3}, {1,3}, {3,2}, {2,0}
    };

    auto graph = BuildGraph(edges);

    cout << BFS(3, graph) << endl; 
    cout << DFS(0, graph) << endl;  

    vector<int> topo1 = TopologicalSort(graph);
    vector<int> topo2 = TopologicalSortDFS(graph);

    for(int x : topo1) cout << x << " ";
    cout << endl;

    for(int x : topo2) cout << x << " ";
    cout << endl;

    return 0;
}
