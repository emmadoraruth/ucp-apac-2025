//Question 11: VacationDestinations
//Given an origin city, a maximum travel time k, and pairs of destinations that can be reached directly 
//from each other with corresponding travel times in hours, return the number of destinations within k hours 
//of the origin. Assume that having a stopover in a city adds an hour of travel time.

//Examples: 
// Input: [("Boston", "New York", 4), ("New York", "Philadelphia.", 2), ("Boston", "Newport", 1.5), ("Washington, D.C.", 
// "Harper's Ferry", 1), ("Boston", "Portland", 2.5), ("Philadelphia", "Washington, D.C.", 2.5)] 
 
// Origin = "New York", k=5 
// Output: 2 (["Boston", "Philadelphia"]) 
 
// Origin = "New York", k=7 
// Output: 2 (["Boston", "Philadelphia", "Washington, D.C", "Newport"]) 
 
// Origin = "New York", k=8 
// Output: 2 (["Boston", "Philadelphia", "Washington, D.C", "Newport", "Harper's Ferry", "Portland"]) 

#include <bits/stdc++.h>
using namespace std;

int findDestinations(
    vector<pair<string, pair<string,double>>>& mapping,
    string origin,
    double k
) {
    // Build undirected graph
    unordered_map<string, vector<pair<string, double>>> adj;

    for (size_t i = 0; i < mapping.size(); i++) {
        string u = mapping[i].first;
        string v = mapping[i].second.first;
        double wt = mapping[i].second.second;

        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    // Distance map
    unordered_map<string, double> dist;
    for (auto it = adj.begin(); it != adj.end(); ++it) {
        dist[it->first] = DBL_MAX;
    }

    // Min-heap (time, city)
    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    dist[origin] = 0.0;
    pq.push(make_pair(0.0, origin));

    while (!pq.empty()) {
        pair<double, string> top = pq.top();
        pq.pop();

        double currTime = top.first;
        string u = top.second;

        if (currTime > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); i++) {
            string v = adj[u][i].first;
            double wt = adj[u][i].second;

            double newTime = currTime + wt;

            // stopover cost
            if (u != origin) newTime += 1.0;

            if (newTime < dist[v]) {
                dist[v] = newTime;
                pq.push(make_pair(newTime, v));
            }
        }
    }

    // Count reachable destinations
    int count = 0;
    for (auto it = dist.begin(); it != dist.end(); ++it) {
        if (it->first != origin && it->second <= k) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<pair<string, pair<string, double>>> mapping = {
        {"Boston", {"New York", 4}},
        {"New York", {"Philadelphia", 2}},
        {"Boston", {"Newport", 1.5}},
        {"Washington, D.C.", {"Harper's Ferry", 1}},
        {"Boston", {"Portland", 2.5}},
        {"Philadelphia", {"Washington, D.C.", 2.5}}
    };

    string origin = "New York";

    cout << findDestinations(mapping, origin, 5) << endl; // 2
    cout << findDestinations(mapping, origin, 7) << endl; // 4
    cout << findDestinations(mapping, origin, 8) << endl; // 6

    return 0;
}
