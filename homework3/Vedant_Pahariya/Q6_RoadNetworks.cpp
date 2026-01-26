// In some states, it is not possible to drive between any two towns because they are not connected to the same road network. Given a list of towns and a list of pairs representing roads between towns, return the number of road networks. (For example, a state in which all towns are connected by roads has 1 road network, and a state in which none of the towns are connected by roads has 0 road networks.)


// Assumption: I am assuming that the roads are bidirectional i.e we can travel both ways to and fro.

// Time Complexity: O (V + E)
// Space Complexity: O (V +E) where V is vertices(towns) & E is edges(roads)
#include <bits/stdc++.h>
using namespace std;


void dfs(unordered_map<string, set<string>> adj, string town, set<string> &visit){
    visit.insert(town);
    for(auto it : adj[town]){
        if(visit.find(it) == visit.end()){
            dfs(adj, it, visit);
        }
    }
}

int roadnet(vector<string> towns, vector<pair<string,string>> roads){
    // first we have create adjacency list
    // vector<vector<string>> adj_list;
    unordered_map<string, set<string>> adj;

    for(auto it : roads){
        string u = it.first;
        string v = it.second;
        adj[u].insert(v);
        adj[v].insert(u);
        // Following the assumption, adding to the both sides in adj_list
    }

    int count = 0;
    set<string> visit;
    for(auto town : towns){
        if(visit.find(town)== visit.end() && adj[town].size()){
            dfs(adj, town, visit);
            count++;
        }
    }

    return count;
}


int main() {
    // Test case 1
    vector<string> cities1 = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};
    vector<pair<string, string>> edges1 = {
        {"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}
    };
    cout << roadnet(cities1, edges1) << "\n"; // 2

    // Test case 2
    vector<string> cities2 = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"};
    vector<pair<string, string>> edges2 = {
        {"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"},
        {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"}
    };
    cout << roadnet(cities2, edges2) << "\n"; // 3

    return 0;
}