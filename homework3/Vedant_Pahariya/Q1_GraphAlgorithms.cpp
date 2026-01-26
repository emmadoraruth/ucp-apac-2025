// Given an array of pairs of values representing edges in an unweighted graph, create the equivalent adjacency list/set representation (a map from element to a list or set of elements). Pairs represent directed edges: (A, B) means there is an edge from A to B. If the pair (B, A) is also provided, then there is an undirected edge between A and B. For simplicity, you may assume that each node of the graph stores an integer rather than a generic data type and that the elements are distinct. Implement a basic DFS and BFS that search for a target value and two topological sorts (using each of DFS and Kahn’s algorithm)

// Total Time taken: about 2 hours 40 mins (including reading resources and watching videos in youtube)

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// Time Complextiy: O(E)
// Space Complexity: O(V + E)
map<int, set<int>> adjacencySet(vector<pair<int, int>> edges){

    map<int, set<int>> adjSet;
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        adjSet[u].insert(v);
    }
    return adjSet;
}

// Thinking Process-1
// As array of edges (Edge List) is given, while iterating through it, I will put the each edge in the map where key will be the starting node and value will be a set of all the nodes connected to it.

// Assumption: Here I am assuming that edges are given in directed fashion therefore I have just used adjSet[u].insert(v) (Not adjSet[V].insert(u) also)

/* Theory:

Ways for Graph Representation:
1) Edge List
2) Adjacency List
3) Adjacency Matrix

Adjacency List- Space: O(V + E); Time for edge check: O(V); 
Where V is number of vertices and E is number of edges. Best for Sparse Graphs.

Adjacency Matrix- Space: O(V^2); Time for edge check: O(1)
Where V is number of vertices. Best for Dense Graphs.

I used the following resource to understand the concepts:
https://share.google/aimode/pEpBydTXhOMkGU1sS
*/

// here, graph (adjacency list representation) and target value is given as input to search using BFS
// Time Complexity : O(V+E) because each node is visited once and each edge is visited once
// Space Complexity: O(2V) -> O(V) for visited + O(V) for queue so effectively O(V)
bool bfs(int target, map<int, set<int>> graph){
    set<int> visit;

    for (auto& entry : graph){
        int start = entry.first;
        if(visit.find(start) == visit.end()){
        queue<int> q;
        q.push(start);
        visit.insert(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            // if target, then return true
            if(node == target){
                return true;
            }

            for(auto neighbor : graph[node]){
                if(visit.find(neighbor) == visit.end()){
                    visit.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        }
    }
    return false; // if target not found
}

// Thinking Process-2
// For BFS, I will use a queue to explore the graph level by level. I will also maintain a set to keep track of visited nodes to avoid cycles. Starting from an arbitrary node, I will enqueue it and mark it as visited. Then, I will repeatedly dequeue a node, check if it is the target, and enqueue all its unvisited neighbors until the queue is empty or the target is found.

// Time Complextiy: O(V+E)
// Space Complexity: O(2V) 
bool dfs(int target, map<int, set<int>> graph){
    set<int> visit;

    for(auto& entry: graph){
        int start = entry.first;
        if(visit.find(start)==visit.end()){
            stack<int> s;

        s.push(start);

        while (!s.empty()){
            int node = s.top();
            s.pop();

            if (node == target){
                return true;
            }

            if(visit.find(node) == visit.end()){
                visit.insert(node);
                for (int neighbour : graph[node]) {
                    s.push(neighbour);
                }
            }
        }
     }
    }
    return false;
}

// Thinking Process-3
// For DFS, there are two possible ways in which I could have implemented. One I knew which is using recursion and maintaining a visited array but as the function signature was already given, I didn't want to change it so I have to use a helper function. But then I searched for other cleaner method in web so that if it is possible to do this without any helper function and came to know this stacking method which I already knew but didn't click in my mind while solving this function. 

// So, DFS -> Stack && BFS -> Queue


vector<int> topologicalSort(map<int, set<int>> graph){
    // using kahn's algorithm
    map<int, int> indegree;
    for(auto& entry : graph){
        for(auto neighbor : entry.second){
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for(auto& entry : graph){
        int node = entry.first;
        if(indegree[node] == 0){
            q.push(node);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto neighbor : graph[node]){
            indegree[neighbor]--;
            if(indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    return topo;  
}


/* Theory for Kahn's Algorithm (learned from web before implementing the above functions):

Kahn's algorithm is used for finding a topological sort of a directed acyclic graph (DAG). It uses in-degree count and a queue. If all nodes are processed, you have a valid topological order. If not, the graph has a cycle. Therefore, it can also be used for cycle detection as well.
Time Complexity: O(V + E)
*/

void dfsrecur(set<int>& visit, map<int, set<int>>& graph, int start, stack<int>& sort){

    if(visit.find(start) == visit.end()){
        visit.insert(start);
        for(auto it : graph[start]){
            dfsrecur(visit, graph, it, sort);
        }
        sort.push(start);
    }
}

vector<int> topologicalSortDfs(map<int, set<int>> graph){
    // set<int> visit;
    // int start = graph.begin()->first;

    // visit.insert(start);

    // stack<int> s;

    // for(auto it : graph[node]){
    //     if(visit.find(it))
    // }

    set<int> visit;
    stack<int> sort;
    for (auto& entry : graph){
        int start = entry.first;
        dfsrecur(visit, graph, start, sort);
    }
    vector<int> topo;
    while(!sort.empty()){
        topo.push_back(sort.top());
        sort.pop();
    }
    return topo;
}

// helper functions for testing the above functions 

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Helper to convert array<pair<int,int>> to vector<pair<int,int>> for C++ compatibility
vector<pair<int, int>> getSampleEdges() {
    return {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };
}

void testGraphAlgorithms() {
    auto edges = getSampleEdges();
    auto graph = adjacencySet(edges);

    cout << "BFS search for 1: " << (bfs(1, graph) ? "Found" : "Not Found") << endl;
    cout << "DFS search for 1: " << (dfs(1, graph) ? "Found" : "Not Found") << endl;

    cout << "Topological Sort (Kahn's): ";
    printArray(topologicalSort(graph));

    cout << "Topological Sort (DFS): ";
    printArray(topologicalSortDfs(graph));
}

int main() {
    testGraphAlgorithms();
    return 0;
}