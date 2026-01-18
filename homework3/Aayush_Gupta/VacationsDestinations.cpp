#include <bits/stdc++.h>
using namespace std;

int reachableDestinations(string startCity, double maxTime, vector<tuple<string,string,double>>& flights){
    map<string, vector<pair<string,double>>> connections;
    for(auto &flight : flights){
        string cityA, cityB;
        double time;
        tie(cityA, cityB, time) = flight;
        connections[cityA].push_back({cityB, time});
        connections[cityB].push_back({cityA, time});
    }

    map<string,double> travelTime;
    for(auto &p : connections) travelTime[p.first] = 1e9;
    travelTime[startCity] = 0;

    priority_queue<pair<double,string>, vector<pair<double,string>>, greater<>> pq;
    pq.push({0, startCity});

    while(!pq.empty()){
        auto [currentTime, city] = pq.top(); pq.pop();
        if(currentTime > travelTime[city]) continue;
        for(auto &[nextCity, flightTime] : connections[city]){
            double newTime = currentTime + flightTime + 1;
            if(newTime < travelTime[nextCity]){
                travelTime[nextCity] = newTime;
                pq.push({newTime, nextCity});
            }
        }
    }

    int reachableCount = 0;
    for(auto &[city, time] : travelTime){
        if(city != startCity && time <= maxTime) reachableCount++;
    }
    return reachableCount;
}

int main(){
    vector<tuple<string,string,double>> flights = {
        {"Boston","New York",4},
        {"New York","Philadelphia",2},
        {"Boston","Newport",1.5},
        {"Washington, D.C.","Harper's Ferry",1},
        {"Boston","Portland",2.5},
        {"Philadelphia","Washington, D.C.",2.5}
    };

    cout << reachableDestinations("New York",5,flights) << endl;
    cout << reachableDestinations("New York",7,flights) << endl;
    cout << reachableDestinations("New York",8,flights) << endl;
}
