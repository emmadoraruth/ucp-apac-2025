// Given an origin city, a maximum travel time k, and pairs of destinations that can be reached directly from each other with corresponding travel times in hours, return the number of destinations within k hours of the origin. Assume that having a stopover in a city adds an hour of travel time.

#include <bits/stdc++.h>
using namespace std;

// From the question, it clearly indicates that the graph is undirected i.e. we can travel both ways.

// Time Complexity: O((V + E) log V) where V is the number of cities (nodes), and E is the number of edges (routes), log V is coming because of set/priority queue here.
// Space Complexity: O(V + E)
int destiny(string origin, float k, vector<tuple<string, string, float>> input){
    // Creating adjacency list
    unordered_map<string, vector<pair<string, float>>> adj;

    for (auto& it : input){
        string city_one = get<0>(it);
        string city_two = get<1>(it);
        float time = get<2>(it);

        // Store original edge weights
        adj[city_one].push_back({city_two, time});
        adj[city_two].push_back({city_one, time});
    }

    // Dijkstra's algorithm using set
    set<pair<float, string>> st;
    unordered_map<string, float> dist;
    
    // Initialize all distances to infinity
    for (auto& entry : adj) {
        dist[entry.first] = FLT_MAX;
    }
    
    dist[origin] = 0;

    // added the origin as 0 distance first node
    st.insert({0,origin});

    while(!st.empty()){
        auto min_dis = *st.begin();
        st.erase(st.begin());
        
        float currDist = min_dis.first;
        string currCity = min_dis.second;
        
        for(auto& neighbor : adj[currCity]){
            string nextCity = neighbor.first;
            float edgeWeight = neighbor.second;
            
            // Adding stopover penalty (+1 hour) only if not at origin (meaning we are passing through a city)
            float stopoverPenalty = (currCity == origin) ? 0 : 1;
            float newDist = currDist + edgeWeight + stopoverPenalty;
            
            // If new distance is shorter and within k hours
            if(newDist < dist[nextCity] && newDist <= k){
                // Removing old distance from set if it exists
                if(dist[nextCity] != FLT_MAX){
                    st.erase({dist[nextCity], nextCity});
                }
                
                dist[nextCity] = newDist;
                st.insert({newDist, nextCity});
            }
        }
    }

    // Count destinations within k hours (excluding origin)
    int count = 0;
    // vector<string> destinations;
    
    for(auto& entry : dist){
        if(entry.first != origin && entry.second <= k){
            count++;
            // destinations.push_back(entry.first);
        }
    }
    
    // Printing destinations for verification
    // cout << "Destinations reachable: [";
    // for (int i = 0; i < destinations.size(); i++) {
    //     cout << "\"" << destinations[i] << "\"";
    //     if (i < destinations.size() - 1) cout << ", ";
    // }
    // cout << "]" << endl;
    
    return count;
}

int main(){
    // Test cases
    vector<tuple<string, string, float>> routes = {
        {"Boston", "New York", 4},
        {"New York", "Philadelphia", 2},
        {"Boston", "Newport", 1.5},
        {"Washington, D.C.", "Harper's Ferry", 1},
        {"Boston", "Portland", 2.5},
        {"Philadelphia", "Washington, D.C.", 2.5}
    };
    
     cout << "Test 1: Origin = New York, k = 5" << endl;
     int result1 = destiny("New York", 5, routes);
    cout << "Output: " << result1 << endl;
    
    cout << "Test 2: Origin = New York, k = 7" << endl;
      int result2 = destiny("New York", 7, routes);
     cout << "Output: " << result2 << endl;
    
    cout << "Test 3: Origin = New York, k = 8" << endl;
    int result3 = destiny("New York", 8, routes);
    cout << "Output: " << result3 << endl;
}