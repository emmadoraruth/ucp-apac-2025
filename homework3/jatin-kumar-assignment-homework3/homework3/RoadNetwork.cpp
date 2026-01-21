#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<bits/stdc++.h>
// DFS to count connected components in an undirected graph
// tc: O(V+E)
// sc: O(V+E) for adjacency list and O(V) for visited map
// time taken: 25 min
void dfs(string node,unordered_map<string,vector<string>>& mp,map<string,int>& vis){
    vis[node]=1;
    for(auto neighbor:mp[node]){
        if(!vis[neighbor]){
            dfs(neighbor,mp,vis);
        }
    }
}
int RoadNetwork(vector<string>towns,vector<pair<string,string>>roads){
    unordered_map<string,vector<string>> mp;
    for(auto town:towns){
        mp[town]={};
    }
    for(auto road:roads){
        mp[road.first].push_back(road.second);
        mp[road.second].push_back(road.first);
    }
    int cnt=0;
    map<string,int> vis;
    for(auto it:mp){
        if(!vis[it.first] && !it.second.empty()){
            dfs(it.first,mp,vis);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    // Test Case 1: Alaska towns
    // Input: ["Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"]
    // Roads: [("Anchorage", "Homer"), ("Glacier Bay", "Gustavus"), ("Copper Center", "McCarthy"), ("Anchorage", "Copper Center"), ("Copper Center", "Fairbanks"), ("Healy", "Fairbanks"), ("Healy", "Anchorage")]
    // Expected Output: 2 connected components
    vector<string> towns1 = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};
    
    vector<pair<string,string>> roads1 = {
        {"Anchorage","Homer"},
        {"Glacier Bay","Gustavus"},
        {"Copper Center","McCarthy"},
        {"Anchorage","Copper Center"},
        {"Copper Center","Fairbanks"},
        {"Healy","Fairbanks"},
        {"Healy","Anchorage"}
    };
    
    cout << "Test Case 1 (Alaska): " << RoadNetwork(towns1, roads1) << endl;

    // Test Case 2: Hawaii towns
    // Input: ["Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"]
    // Roads: [("Kona", "Volcano"), ("Volcano", "Hilo"), ("Lahaina", "Hana"), ("Kahului", "Haiku"), ("Hana", "Haiku"), ("Kahului", "Lahaina"), ("Princeville", "Lihue"), ("Lihue", "Waimea")]
    // Expected Output: 3 connected components
    vector<string> towns2 = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"};
    
    vector<pair<string,string>> roads2 = {
        {"Kona","Volcano"},
        {"Volcano","Hilo"},
        {"Lahaina","Hana"},
        {"Kahului","Haiku"},
        {"Hana","Haiku"},
        {"Kahului","Lahaina"},
        {"Princeville","Lihue"},
        {"Lihue","Waimea"}
    };

    cout << "Test Case 2 (Hawaii): " << RoadNetwork(towns2, roads2) << endl;  
}