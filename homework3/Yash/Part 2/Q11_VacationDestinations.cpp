// Question 11 : VacationDestinations ; Technique used: Dijkstra’s Algorithm
// Time Taken : 40 minutes

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

vector<string> VacationDestinations(
    vector<vector<string>> roads,
    string origin,
    double k
){
    unordered_map<string, vector<pair<string, double>>> graph;

    
    for(auto r : roads){
        string a = r[0];
        string b = r[1];
        double time = stod(r[2]);

        graph[a].push_back({b, time});
        graph[b].push_back({a, time});
    }

    unordered_map<string, double> dist;
    for(auto entry : graph){
        dist[entry.first] = INT_MAX;
    }

    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    dist[origin] = 0;
    pq.push({0, origin});

    while(!pq.empty()){
        double currTime = pq.top().first;
        string city = pq.top().second;
        pq.pop();

        if(currTime > dist[city]) continue;

        for(auto next : graph[city]){
            string nextCity = next.first;
            double travelTime = next.second;

            double newTime = currTime + travelTime + 1; 

            if(newTime < dist[nextCity]){
                dist[nextCity] = newTime;
                pq.push({newTime, nextCity});
            }
        }
    }

    vector<string> reachableCities;

    for(auto entry : dist){
        if(entry.first != origin && entry.second <= k){
            reachableCities.push_back(entry.first);
        }
    }

    return reachableCities;
}

void PrintResult(string origin, double k, vector<string> cities){
    
    cout <<"Answer: "<< cities.size() << endl;
    cout << "Cities: ";
    for(string city : cities){
        cout << city << " | ";
    }
    cout << endl << endl;
}

int main(){

    vector<vector<string>> roads = {
        {"Boston", "New York", "4"},
        {"New York", "Philadelphia", "2"},
        {"Boston", "Newport", "1.5"},
        {"Washington, D.C.", "Harper's Ferry", "1"},
        {"Boston", "Portland", "2.5"},
        {"Philadelphia", "Washington, D.C.", "2.5"}
    };

    
    PrintResult("New York", 5, VacationDestinations(roads, "New York", 5)); // Testcase 1
    PrintResult("New York", 7, VacationDestinations(roads, "New York", 7)); // Testcase 2
    PrintResult("New York", 8, VacationDestinations(roads, "New York", 8)); // Testcase 3

    PrintResult("Boston", 0, VacationDestinations(roads, "Boston", 0)); // Testcase 4
    PrintResult("Boston", 2, VacationDestinations(roads, "Boston", 2)); // Testcase 5
    PrintResult("Boston", 5, VacationDestinations(roads, "Boston", 5)); // Testcase 6
    PrintResult("Boston", 20, VacationDestinations(roads, "Boston", 20)); // Testcase 7
    PrintResult("Harper's Ferry", 3, VacationDestinations(roads, "Harper's Ferry", 3)); // Testcase 8
    PrintResult("Philadelphia", 6, VacationDestinations(roads, "Philadelphia", 6)); // Testcase 9

    return 0;
}
