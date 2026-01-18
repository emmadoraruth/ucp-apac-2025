// DS/Algo used - DFS

// Time Complexity O(V + E)

// Memory Complexity O(V + E)

// where V = number of towns and E = number of roads

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>> adj){
    visited[node] = true;
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            dfs(nbr, visited, adj);
        }
    }
}

int countRoadNetworks(vector<string> towns, vector<pair<string,string>>& roads) {
    int n = towns.size();
    vector<vector<int>> adj(n);

    unordered_map<string, int> id;
    for (int i = 0; i < n; i++){
        id[towns[i]] = i;
    }

    for (auto [u, v] : roads){
        int a = id[u];
        int b = id[v];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    int networks = 0;

    for(int i = 0; i < n; i++){
        if(adj[i].empty() == true) continue;
        if(visited[i] == false){
            dfs(i, visited, adj);
            networks++;
        }
    }

    return networks;
}

int main(){
    vector<string> towns1 = {
        "Skagway", "Juneau", "Gustavus", "Homer",
        "Port Alsworth", "Glacier Bay", "Fairbanks",
        "McCarthy", "Copper Center", "Healy", "Anchorage"
    };

    vector<pair<string,string>> roads1 = {
        {"Anchorage", "Homer"},
        {"Glacier Bay", "Gustavus"},
        {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"},
        {"Copper Center", "Fairbanks"},
        {"Healy", "Fairbanks"},
        {"Healy", "Anchorage"}
    };

    cout << countRoadNetworks(towns1, roads1) << endl; // 2

    vector<string> towns2 = {
        "Kona", "Hilo", "Volcano", "Lahaina",
        "Hana", "Haiku", "Kahului",
        "Princeville", "Lihue", "Waimea"
    };

    vector<pair<string,string>> roads2 = {
        {"Kona", "Volcano"},
        {"Volcano", "Hilo"},
        {"Lahaina", "Hana"},
        {"Kahului", "Haiku"},
        {"Hana", "Haiku"},
        {"Kahului", "Lahaina"},
        {"Princeville", "Lihue"},
        {"Lihue", "Waimea"}
    };

    cout << countRoadNetworks(towns2, roads2) << endl; // 3

    return 0;
}

// Time Taken - 13 min