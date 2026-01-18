#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;

public:
    // Build adjacency list from edge list
    void addEdges(const vector<pair<int,int>>& edges) {
        for (auto &e : edges) {
            adj[e.first].push_back(e.second);
        }
    }

    // Print adjacency list
    void printGraph() {
        for (auto &p : adj) {
            cout << p.first << " -> ";
            for (int v : p.second) cout << v << " ";
            cout << endl;
        }
    }

    // DFS Search 
    bool dfsSearch(int start, int target) {
        unordered_set<int> visited;
        return dfsUtil(start, target, visited);
    }

    bool dfsUtil(int node, int target, unordered_set<int>& visited) {
        if (node == target) return true;
        visited.insert(node);

        for (int nei : adj[node]) {
            if (!visited.count(nei)) {
                if (dfsUtil(nei, target, visited)) return true;
            }
        }
        return false;
    }

    // BFS Search 
    bool bfsSearch(int start, int target) {
        unordered_set<int> visited;
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (node == target) return true;

            for (int nei : adj[node]) {
                if (!visited.count(nei)) {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
        return false;
    }

    //Topological Sort using DFS 
    vector<int> topoSortDFS() {
        unordered_set<int> visited;
        stack<int> st;

        for (auto &p : adj) {
            if (!visited.count(p.first)) {
                topoDFSUtil(p.first, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

    void topoDFSUtil(int node, unordered_set<int>& visited, stack<int>& st) {
        visited.insert(node);
        for (int nei : adj[node]) {
            if (!visited.count(nei)) {
                topoDFSUtil(nei, visited, st);
            }
        }
        st.push(node);
    }

    //topological Sort using Kahn 
    vector<int> topoSortKahn() {
        unordered_map<int,int> indegree;

    
        for (auto &p : adj) {
            if (!indegree.count(p.first))
                indegree[p.first] = 0;
            for (int v : p.second)
                indegree[v]++;
        }

        queue<int> q;
        for (auto &p : indegree) {
            if (p.second == 0)
                q.push(p.first);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (int nei : adj[node]) {
                if (--indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return topo;
    }
};

int main() {
    vector<pair<int,int>> edges = {
        {1,2}, {1,3}, {2,4}, {3,4}
    };

    Graph g;
    g.addEdges(edges);

    cout << "Adjacency List:\n";
    g.printGraph();

    cout << "\nDFS Search (1 -> 4): " << g.dfsSearch(1,4) << endl;
    cout << "BFS Search (1 -> 4): " << g.bfsSearch(1,4) << endl;

    cout << "\nTopological Sort (DFS): ";
    for (int x : g.topoSortDFS()) cout << x << " ";

    cout << "\nTopological Sort (Kahn): ";
    for (int x : g.topoSortKahn()) cout << x << " ";

    return 0;
}
