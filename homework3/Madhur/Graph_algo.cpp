/*
Approach:
1. Build the graph using an adjacency set (map<int, set<int>>) from the given edge list.
2. BFS:
   - Use a queue and a visited set.
   - Traverse all components (important for disconnected graphs).
   - Return true if target is found.

3. DFS:
   - Use recursion with a visited set.
   - Traverse all components.
   - Return true if target is found.

4. Topological Sort (Kahn’s Algorithm)

5. Topological Sort (DFS-based):

Time Complexity:
- Graph construction: O(E log V)
- BFS / DFS: O(V + E)
- Topological Sort (Kahn / DFS): O(V + E)

Time Taken: 1 hr 29 minutes (within 1 hr 40 min limit)
*/

#include <bits/stdc++.h>
using namespace std;

// Build graph representation
map<int, set<int>> buildGraph(const vector<pair<int, int>>& edges) {
    map<int, set<int>> graph;

    for (auto &e : edges) {
        int u = e.first;
        int v = e.second;
        graph[u].insert(v);

        // ensure v also exists in graph
        if (graph.find(v) == graph.end()) {
            graph[v] = {};
        }
    }
    return graph;
}

// BFS search
bool bfs(int target, map<int, set<int>>& graph) {
    unordered_set<int> visited;
    queue<int> q;

    for (auto &p : graph) {
        int start = p.first;
        if (visited.count(start)) continue;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == target) return true;

            for (int nei : graph[node]) {
                if (!visited.count(nei)) {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
    }
    return false;
}

// DFS helper
bool dfsHelper(int node, int target, map<int, set<int>>& graph,
               unordered_set<int>& visited) {
    if (node == target) return true;
    visited.insert(node);

    for (int nei : graph[node]) {
        if (!visited.count(nei)) {
            if (dfsHelper(nei, target, graph, visited))
                return true;
        }
    }
    return false;
}

// DFS search
bool dfs(int target, map<int, set<int>>& graph) {
    unordered_set<int> visited;

    for (auto &p : graph) {
        int node = p.first;
        if (!visited.count(node)) {
            if (dfsHelper(node, target, graph, visited))
                return true;
        }
    }
    return false;
}

// Topological Sort using Kahn’s Algorithm
vector<int> topologicalSort(map<int, set<int>>& graph) {
    unordered_map<int, int> indegree;

    for (auto &p : graph) {
        if (!indegree.count(p.first))
            indegree[p.first] = 0;

        for (int v : p.second) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (auto &p : indegree) {
        if (p.second == 0)
            q.push(p.first);
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int nei : graph[node]) {
            if (--indegree[nei] == 0)
                q.push(nei);
        }
    }

    return result;
}

// DFS-based Topological Sort helper
void topoDfs(int node, map<int, set<int>>& graph,
             unordered_set<int>& visited, vector<int>& order) {
    visited.insert(node);

    for (int nei : graph[node]) {
        if (!visited.count(nei))
            topoDfs(nei, graph, visited, order);
    }
    order.push_back(node);
}

// DFS-based Topological Sort
vector<int> topologicalSortDfs(map<int, set<int>>& graph) {
    unordered_set<int> visited;
    vector<int> order;

    for (auto &p : graph) {
        if (!visited.count(p.first)) {
            topoDfs(p.first, graph, visited, order);
        }
    }

    reverse(order.begin(), order.end());
    return order;
}


int main() {
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}
    };

    auto graph = buildGraph(edges);

    cout << "Adjacency List:\n";
    for (auto &p : graph) {
        cout << p.first << ": ";
        for (int v : p.second)
            cout << v << " ";
        cout << "\n";
    }

    cout << "\nBFS search for 3: " << bfs(3, graph) << endl;
    cout << "DFS search for 4: " << dfs(4, graph) << endl;

    auto topo1 = topologicalSort(graph);
    cout << "\nTopological Sort (Kahn): ";
    for (int x : topo1) cout << x << " ";

    auto topo2 = topologicalSortDfs(graph);
    cout << "\nTopological Sort (DFS): ";
    for (int x : topo2) cout << x << " ";

    return 0;
}
