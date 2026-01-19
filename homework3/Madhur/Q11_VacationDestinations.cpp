/*
Data Structure Used:
Graph (Adjacency List), Priority Queue (Min Heap), Hashmap

Algorithm:
Dijkstra’s Algorithm

Approach:
Use Dijkstra’s algorithm to compute the shortest travel time from the origin to all cities while adding stopover costs.

Time Complexity:
- O((V + E) log V)

Space Complexity:
- O(V + E)

Time Taken:
40 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vacationDestinations(
        vector<tuple<string, string, double>>& routes,
        string origin,
        double k
    ) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build undirected graph
        for (auto& r : routes) {
            string u, v;
            double time;
            tie(u, v, time) = r;
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Min heap: (currentTime, city)
        priority_queue<
            pair<double, string>,
            vector<pair<double, string>>,
            greater<pair<double, string>>
        > pq;

        unordered_map<string, double> dist;

        for (auto& p : graph) {
            dist[p.first] = DBL_MAX;
        }

        dist[origin] = 0;
        pq.push({0, origin});

        // Dijkstra’s Algorithm
        while (!pq.empty()) {
            auto [currTime, city] = pq.top();
            pq.pop();

            if (currTime > dist[city])
                continue;

            for (auto& [next, travelTime] : graph[city]) {
                double newTime = currTime + travelTime;

                // Add stopover cost (1 hour) for intermediate cities
                if (city != origin)
                    newTime += 1;

                if (newTime < dist[next]) {
                    dist[next] = newTime;
                    pq.push({newTime, next});
                }
            }
        }

        // Count destinations within k hours (excluding origin)
        int count = 0;
        for (auto& p : dist) {
            if (p.first != origin && p.second <= k)
                count++;
        }

        return count;
    }
};

int main() {
    Solution s;

    vector<tuple<string, string, double>> routes = {
        {"Boston", "New York", 4},
        {"New York", "Philadelphia", 2},
        {"Boston", "Newport", 1.5},
        {"Washington, D.C.", "Harper's Ferry", 1},
        {"Boston", "Portland", 2.5},
        {"Philadelphia", "Washington, D.C.", 2.5}
    };

    cout << s.vacationDestinations(routes, "New York", 5) << endl; // 2
    cout << s.vacationDestinations(routes, "New York", 7) << endl; // 4
    cout << s.vacationDestinations(routes, "New York", 8) << endl; // 6

    return 0;
}
