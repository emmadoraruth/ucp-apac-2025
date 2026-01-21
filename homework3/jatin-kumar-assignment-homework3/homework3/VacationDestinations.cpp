#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>

// Approach: Dijkstra's algorithm with a priority queue
// tc: O((V+E) log V)
// sc: O(V+E) for graph and O(V) for time map and priority queue
// time taken: 45 min


int VacationDestinations(vector<vector<string>> &destinations, string origin, double k) {
  unordered_map<string, vector<pair<string, double>>> adj;
        // Build the adjacency list
        for(auto & e:destinations){
            string from = e[0]; 
            string to = e[1];
            double distance = stod(e[2]);
            adj[from].push_back({to, distance});
            adj[to].push_back({from, distance});
        }
      
      priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;
        unordered_map<string, double> time;
        pq.push({0.0, origin});
        time[origin] = 0.0;
        
        while(!pq.empty()){
            auto [currTime, city] = pq.top();
            pq.pop();
            
            // Skip if we've already processed this city with a better time
            if(currTime > time[city]) continue;
            
            for(auto &[neighbor, weight]: adj[city]){
                // Add stopover penalty (+1 hour) for intermediate cities (not from origin)
                double stopoverPenalty=0;
                if(city!=origin){
                    stopoverPenalty=1.0;
                }
                
                double newTime = currTime + weight + stopoverPenalty;

                if(time.find(neighbor) == time.end() || newTime < time[neighbor]){

                    time[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }
        
        int count = 0;
        for(auto &[city, totalTime]: time){
            if(city != origin && totalTime <= k){
                count++;
            }
        }
        
        return count;
}

int main() {

vector<vector<string>> destinations = {
    {"Boston", "New York", "4"},
    {"New York", "Philadelphia", "2"},
    {"Boston", "Newport", "1.5"},
    {"Washington, D.C.", "Harper's Ferry", "1"},
    {"Boston", "Portland", "2.5"},
    {"Philadelphia", "Washington, D.C.", "2.5"}
};

string origin = "New York";
double k1 = 5.0;
double k2 = 7.0;
double k3 = 8.0;

// Test Case 1: Origin = "New York", k = 5
// Expected Output: 2 (["Boston", "Philadelphia"])
cout << "Test Case 1 (k=5): " << VacationDestinations(destinations, origin, k1) << endl;

// Test Case 2: Origin = "New York", k = 7
// Expected Output: 4 (["Boston", "Philadelphia", "Washington, D.C", "Newport"])
cout << "Test Case 2 (k=7): " << VacationDestinations(destinations, origin, k2) << endl;

// Test Case 3: Origin = "New York", k = 8
// Expected Output: 6 (["Boston", "Philadelphia", "Washington, D.C", "Newport", "Harper's Ferry", "Portland"])
cout << "Test Case 3 (k=8): " << VacationDestinations(destinations, origin, k3) << endl;

}