#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vacationDestinations(
        vector<tuple<string, string, double>>& routes,
        string origin,
        int k
    ) {
        // Adjacency list: city -> (neighbor, travel time)
        unordered_map<string, vector<pair<string, double>>> adj;

        // Build undirected graph
        for (int i = 0; i < routes.size(); i++) {
            string u = get<0>(routes[i]);
            string v = get<1>(routes[i]);
            double time = get<2>(routes[i]);

            adj[u].push_back(make_pair(v, time));
            adj[v].push_back(make_pair(u, time));
        }

        // Min heap: (time, city)
        priority_queue<
            pair<double, string>,
            vector<pair<double, string>>,
            greater<pair<double, string>>
        > pq;

        unordered_map<string, double> dist;

        // Initialize distances
        for (auto it = adj.begin(); it != adj.end(); ++it) {
            dist[it->first] = DBL_MAX;
        }

        dist[origin] = 0;
        pq.push(make_pair(0, origin));

        while (!pq.empty()) {
            double currTime = pq.top().first;
            string city = pq.top().second;
            pq.pop();

            if (currTime > dist[city])
                continue;

            for (int i = 0; i < adj[city].size(); i++) {
                string nextCity = adj[city][i].first;
                double travelTime = adj[city][i].second;

                // +1 hour for stopover
                double newTime = currTime + travelTime + 1;

                if (newTime < dist[nextCity]) {
                    dist[nextCity] = newTime;
                    pq.push(make_pair(newTime, nextCity));
                }
            }
        }

        // Count reachable destinations within k hours (excluding origin)
        int count = 0;
        for (auto it = dist.begin(); it != dist.end(); ++it) {
            if (it->first != origin && it->second <= k) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    vector<tuple<string, string, double>> routes = {
        make_tuple("Boston", "New York", 4),
        make_tuple("New York", "Philadelphia", 2),
        make_tuple("Boston", "Newport", 1.5),
        make_tuple("Washington, D.C.", "Harper's Ferry", 1),
        make_tuple("Boston", "Portland", 2.5),
        make_tuple("Philadelphia", "Washington, D.C.", 2.5)
    };

    Solution s;
    cout << s.vacationDestinations(routes, "New York", 5) << endl; 
    cout << s.vacationDestinations(routes, "New York", 7) << endl; 
    cout << s.vacationDestinations(routes, "New York", 8) << endl; 

    return 0;
}
