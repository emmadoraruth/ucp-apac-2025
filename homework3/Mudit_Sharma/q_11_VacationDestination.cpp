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

int findDestinations(
    std::vector<std::pair<std::string, std::pair<std::string,double>>>& mapping,
    std::string origin,
    double k
) {
    // Build undirected graph
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adj;

    for (size_t i = 0; i < mapping.size(); i++) {
        std::string u = mapping[i].first;
        std::string v = mapping[i].second.first;
        double wt = mapping[i].second.second;

        adj[u].push_back(std::make_pair(v, wt));
        adj[v].push_back(std::make_pair(u, wt));
    }

    // Distance map
    std::unordered_map<std::string, double> dist;
    for (auto it = adj.begin(); it != adj.end(); ++it) {
        dist[it->first] = DBL_MAX;
    }

    // Min-heap (time, city)
    std::priority_queue<
        std::pair<double, std::string>,
        std::vector<std::pair<double, std::string>>,
        std::greater<std::pair<double, std::string>>
    > pq;

    dist[origin] = 0.0;
    pq.push(std::make_pair(0.0, origin));

    while (!pq.empty()) {
        std::pair<double, std::string> top = pq.top();
        pq.pop();

        double currTime = top.first;
        std::string u = top.second;

        if (currTime > dist[u]) continue;

        for (size_t i = 0; i < adj[u].size(); i++) {
            std::string v = adj[u][i].first;
            double wt = adj[u][i].second;

            double newTime = currTime + wt;

            // stopover cost
            if (u != origin) newTime += 1.0;

            if (newTime < dist[v]) {
                dist[v] = newTime;
                pq.push(std::make_pair(newTime, v));
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
    std::vector<std::pair<std::string, std::pair<std::string, double>>> mapping = {
        {"Boston", {"New York", 4}},
        {"New York", {"Philadelphia", 2}},
        {"Boston", {"Newport", 1.5}},
        {"Washington, D.C.", {"Harper's Ferry", 1}},
        {"Boston", {"Portland", 2.5}},
        {"Philadelphia", {"Washington, D.C.", 2.5}}
    };

    std::string origin = "New York";

    std::cout << findDestinations(mapping, origin, 5) << std::endl; // 2
    std::cout << findDestinations(mapping, origin, 7) << std::endl; // 4
    std::cout << findDestinations(mapping, origin, 8) << std::endl; // 6

    return 0;
}
