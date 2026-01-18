#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(const string& town,
             unordered_map<string, vector<string>>& adj,
             unordered_set<string>& visited) {
        visited.insert(town);
        for (const auto& nei : adj[town]) {
            if (!visited.count(nei)) {
                dfs(nei, adj, visited);
            }
        }
    }

public:
    int roadNetworks(vector<string>& towns,
                     vector<pair<string, string>>& roads) {

        // If there are no roads, no networks
        if (roads.empty()) return 0;

        unordered_map<string, vector<string>> adj;

        // Initialize adjacency list
        for (const auto& town : towns) {
            adj[town] = {};
        }

        // Build undirected graph
        for (auto& r : roads) {
            adj[r.first].push_back(r.second);
            adj[r.second].push_back(r.first);
        }

        unordered_set<string> visited;
        int networks = 0;

        // Count connected components
        for (const auto& town : towns) {
            if (!visited.count(town) && !adj[town].empty()) {
                networks++;
                dfs(town, adj, visited);
            }
        }

        return networks;
    }
};

int main() {
    vector<string> towns = {
        "Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth",
        "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center",
        "Healy", "Anchorage"
    };

    vector<pair<string, string>> roads = {
        {"Anchorage", "Homer"},
        {"Glacier Bay", "Gustavus"},
        {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"},
        {"Copper Center", "Fairbanks"},
        {"Healy", "Fairbanks"},
        {"Healy", "Anchorage"}
    };

    Solution s;
    cout << s.roadNetworks(towns, roads); 
    return 0;
}
