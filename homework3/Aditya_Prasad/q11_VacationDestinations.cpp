// DS/Algo used - BFS with priority queue (Dijisktra)

// Time Complexity O(ElogV)

// Memory Complexity O(V + E)

// where V = number of cities and E = number of flights

#include <bits/stdc++.h>
using namespace std;

int VacationDestinations(vector<tuple<string, string, double>> paths, string origin, int k){
    unordered_map<string, vector<pair<string,double>> > adj;

    for(auto [src, dest, time] : paths){
        adj[src].push_back({dest, time + 1});
        adj[dest].push_back({src, time + 1});
    }

    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> q;
    q.push({-1, origin});

    unordered_map<string, double> totalTime;
    

    for(auto [city, _ ] : adj){
        totalTime[city] = 1e9;
    }
    totalTime[origin] = -1;

    while(!q.empty()){
        auto [nextTime, city] = q.top();
        q.pop();

        if (nextTime > totalTime[city]) continue;

        for (auto [nbr, t] : adj[city]){
            if(totalTime[nbr] > totalTime[city] + t){
                totalTime[nbr] = totalTime[city] + t;
                q.push({totalTime[nbr], nbr}); 
            }
        }

    }

    int reachableDestinations = 0;

    for(auto [city , currtime] : totalTime){
        if (city != origin && currtime <= k){
            reachableDestinations++;
        }
    }

    return reachableDestinations;

}

int main() {
    vector<tuple<string, string, double>> edges = {
        {"Boston", "New York", 4},
        {"New York", "Philadelphia", 2},
        {"Boston", "Newport", 1.5},
        {"Washington, D.C.", "Harper's Ferry", 1},
        {"Boston", "Portland", 2.5},
        {"Philadelphia", "Washington, D.C.", 2.5}
    };

    string origin1 = "New York";
    double k1 = 5;

    string origin2 = "New York";
    double k2 = 7;

    string origin3 = "New York";
    double k3 = 8;

    cout << VacationDestinations(edges, origin1, k1) << endl;
    cout << VacationDestinations(edges, origin2, k2) << endl;
    cout << VacationDestinations(edges, origin3, k3) << endl;

    return 0;
    
}

// Time Taken - 21 min