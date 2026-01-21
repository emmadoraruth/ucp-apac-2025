// Question 6 : Number of Road Networks ; Technique Used : DFS
// Time Taken : 40 minutes

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void DFS(string town,
         unordered_map<string, vector<string>> &graph,
         unordered_set<string> &visited) {

    visited.insert(town);

    for (string nextTown : graph[town]) {
        if (visited.find(nextTown) == visited.end()) {
            DFS(nextTown, graph, visited);
        }
    }
}

int NumberOfRoadNetworks(vector<string> towns,
                         vector<pair<string, string>> roads) {

    
    unordered_map<string, vector<string>> graph;

    for (auto road : roads) {
        string a = road.first;
        string b = road.second;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    unordered_set<string> visited;
    int networks = 0;

   
    for (auto &entry : graph) {
        string town = entry.first;

        if (visited.find(town) == visited.end()) {
            networks++;
            DFS(town, graph, visited);
        }
    }

    return networks;
}

int main() {

    
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

    cout << NumberOfRoadNetworks(towns1, roads1) << endl; 
    cout << NumberOfRoadNetworks(towns2, roads2) << endl; 

    return 0;
}
