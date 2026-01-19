/*
Approach:
Model towns as nodes and roads as undirected edges, then count the number of
connected components using DFS.

Time Complexity:
- O(T + R)
  where T = number of towns, R = number of roads

Space Complexity:
- O(T + R)

Time Taken:
29 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(const string& town,
             unordered_map<string, vector<string>>& graph,
             unordered_set<string>& visited) {

        visited.insert(town);

        for (auto& neighbor : graph[town]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, graph, visited);
            }
        }
    }

public:
    int countRoadNetworks(vector<string>& towns,
                          vector<pair<string, string>>& roads) {

        unordered_map<string, vector<string>> graph;

        // Initialize graph with all towns
        for (auto& town : towns) {
            graph[town] = {};
        }

        // Build undirected graph
        for (auto& road : roads) {
            graph[road.first].push_back(road.second);
            graph[road.second].push_back(road.first);
        }

        unordered_set<string> visited;
        int networks = 0;

        // Count connected components
        for (auto& town : towns) {
            if (!visited.count(town) && !graph[town].empty()) {
                networks++;
                dfs(town, graph, visited);
            }
        }

        return networks;
    }
};

int main() {
    Solution s;

    vector<string> towns1 = {
        "Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth",
        "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center",
        "Healy", "Anchorage"
    };

    vector<pair<string, string>> roads1 = {
        {"Anchorage", "Homer"},
        {"Glacier Bay", "Gustavus"},
        {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"},
        {"Copper Center", "Fairbanks"},
        {"Healy", "Fairbanks"},
        {"Healy", "Anchorage"}
    };

    vector<string> towns2 = {
        "Kona", "Hilo", "Volcano", "Lahaina", "Hana",
        "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"
    };

    vector<pair<string, string>> roads2 = {
        {"Kona", "Volcano"},
        {"Volcano", "Hilo"},
        {"Lahaina", "Hana"},
        {"Kahului", "Haiku"},
        {"Hana", "Haiku"},
        {"Kahului", "Lahaina"},
        {"Princeville", "Lihue"},
        {"Lihue", "Waimea"}
    };

    cout << s.countRoadNetworks(towns1, roads1) << endl; // Output: 2
    cout << s.countRoadNetworks(towns2, roads2) << endl; // Output: 3

    return 0;
}
