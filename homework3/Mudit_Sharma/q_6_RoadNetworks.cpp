//Question 6: RoadNetworks
//In some states, it is not possible to drive between any two towns because they are not connected to the 
//same road network. Given a list of towns and a list of pairs representing roads between towns, return the
// number of road networks. (For example, a state in which all towns are connected by roads has 1 road 
//network, and a state in which none of the towns are connected by roads has 0 road networks.)

// Examples: 
// Input: ["Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper 
// Center", "Healy", "Anchorage"],  
// [("Anchorage", "Homer"), ("Glacier Bay", "Gustavus"), ("Copper Center", "McCarthy"), ("Anchorage", "Copper Center"), 
// ("Copper Center", "Fairbanks"), ("Healy", "Fairbanks"), ("Healy", "Anchorage")] 
// Output: 2 (Networks are Gustavus-Glacier Bay and Anchorage-Fairbanks-McCarthy-Copper Center-Homer-Healy) 
 
// Input: ["Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"], [("Kona", 
// "Volcano"), ("Volcano", "Hilo"), ("Lahaina", "Hana"), ("Kahului", "Haiku"), ("Hana", "Haiku"), ("Kahului", "Lahaina"), 
// ("Princeville", "Lihue"), ("Lihue", "Waimea")]
//Output: 3 (Networks are Kona-Hilo-Volcano, Haiku-Kahului-Lahaina-Hana, and Lihue-Waimea-Princeville)

//-----------------------------------------------------------------------------------------------------------
//12:30-38
//2:15-26

//Approach:Basically here we need to make a graph which can also be disconnected so here actually 
//we need to find the no. of diconnected network can be done by bfs as well as dfs

//here,i am using bfs
//conceptually similar to that of No. of islands

#include<bits/stdc++.h>
using namespace std;
void bfs(string curr,unordered_map<string,vector<string>>& adj,unordered_map<string,bool>& visited){
    queue<string> q;
    q.push(curr);
    visited[curr]=true;
    while(!q.empty()){
        string front=q.front();
        q.pop();
        for(auto& neigh:adj[front]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=true;
            }
        }
    }
}
int findNetwork(pair<vector<string>,vector<pair<string,string>>>& network){
    vector<string> cities=network.first;
    vector<pair<string,string>> connection=network.second;
    unordered_map<string,vector<string>> adj;
    unordered_map<string,bool> visited;
    for(auto& i:cities){
        adj[i]={};
        visited[i]=false;
    }
    for(auto& i:connection){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    int noOfNetworks=0;
    for(auto& city:cities){
        if(!visited[city] && adj[city].size()!=0){
            bfs(city,adj,visited);
            noOfNetworks++;
        }
    }
    return noOfNetworks;
}
int main(){
    pair<vector<string>,vector<pair<string,string>>> roadnetwork1=
    {{"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"},  
{{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, 
{"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}}};
    int noOfNetworks1=findNetwork(roadnetwork1);
    cout<<"Number of Networks are : "<<noOfNetworks1<<endl;
    cout<<"----------------------------------------------------"<<endl;

     pair<vector<string>,vector<pair<string,string>>> roadnetwork2=
    {{"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"},  
{{"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, 
{"Princeville", "Lihue"}, {"Lihue", "Waimea"}}};
int noOfNetworks2=findNetwork(roadnetwork2);
    cout<<"Number of Networks are : "<<noOfNetworks2<<endl;
   

    
}