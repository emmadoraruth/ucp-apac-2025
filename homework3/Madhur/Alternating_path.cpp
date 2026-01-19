/*
Data Structure Used:
Graph (Adjacency List), Queue, Hashset

Algorithm:
Breadth-First Search

Approach:
Use BFS while tracking the current node and the color of the last edge used.

Time Complexity:
- O(V + E)

Space Complexity:
- O(V + E)

Time Taken:
32 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternatingPathLength(
        vector<tuple<string, string, string>>& edges,
        string origin,
        string destination
    ) {
        unordered_map<string, vector<pair<string, string>>> graph;

        // Building  graph
        for (auto& e : edges) {
            string u, v, color;
            tie(u, v, color) = e;
            graph[u].push_back({v, color});
        }

        // visited[node][color]
        unordered_set<string> visited;
        queue<tuple<string, string, int>> q;

        // Start BFS with no previous color
        q.push({origin, "none", 0});
        visited.insert(origin + "_none");

        while (!q.empty()) {
            auto [node, prevColor, dist] = q.front();
            q.pop();

            if (node == destination)
                return dist;

            for (auto& [next, color] : graph[node]) {
                if (color != prevColor) {
                    string state = next + "_" + color;
                    if (!visited.count(state)) {
                        visited.insert(state);
                        q.push({next, color, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution s;

    vector<tuple<string, string, string>> edges = {
        {"A", "B", "blue"},
        {"A", "C", "red"},
        {"B", "D", "blue"},
        {"B", "E", "blue"},
        {"C", "B", "red"},
        {"D", "C", "blue"},
        {"A", "D", "red"},
        {"D", "E", "red"},
        {"E", "C", "red"}
    };

    cout << s.alternatingPathLength(edges, "A", "E") << endl; // Output: 4
    cout << s.alternatingPathLength(edges, "E", "D") << endl; // Output: -1

    return 0;
}
