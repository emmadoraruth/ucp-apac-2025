#include <bits/stdc++.h>
using namespace std;


// I used graph, applied Dijkstra algorithm, it took me 30 min to complete
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)

int vacation(vector<tuple<string, string, double> >& trip, string origin, double k) 
{
    unordered_map<string, vector<pair<string, double> > > graph;

    for (int i = 0; i < (int)trip.size(); i++) 
    {
        string u = get<0>(trip[i]);
        string v = get<1>(trip[i]);
        double time = get<2>(trip[i]);

        graph[u].push_back(make_pair(v, time));
        graph[v].push_back(make_pair(u, time));
    }

    priority_queue<pair<double, string>,vector<pair<double, string> >,greater<pair<double, string> >> pq;
    unordered_map<string, double> dist;

    pq.push(make_pair(0.0, origin));
    dist[origin] = 0.0;

    while (!pq.empty()) 
    {
        pair<double, string> topNode = pq.top();
        pq.pop();
        double currtime = topNode.first;
        string city = topNode.second;

        if (currtime > dist[city]) continue;

        for (int i = 0; i < (int)graph[city].size(); i++) 
        {
            string next = graph[city][i].first;
            double travel = graph[city][i].second;

            double newtime;
            if (currtime == 0.0)
            {
                newtime = currtime + travel;
            }
            else
            {
               newtime = currtime + travel + 1.0;
            }
            if (dist.find(next) == dist.end() || newtime < dist[next]) 
            {
                dist[next] = newtime;
                pq.push(make_pair(newtime, next));
            }
        }
    }


    int count = 0;
    for (unordered_map<string, double>::iterator it = dist.begin();
         it != dist.end(); it++) 
    {
        if (it->first != origin && it->second <= k)
        {
            count++;
        }
    }

    return count;
}

int main() {
    vector<tuple<string, string, double> > trip;
    trip.push_back(make_tuple("Boston", "New York", 4));
    trip.push_back(make_tuple("New York", "Philadelphia", 2));
    trip.push_back(make_tuple("Boston", "Newport", 1.5));
    trip.push_back(make_tuple("Washington, D.C.", "Harper's Ferry", 1));
    trip.push_back(make_tuple("Boston", "Portland", 2.5));
    trip.push_back(make_tuple("Philadelphia", "Washington, D.C.", 2.5));

    cout << vacation(trip, "New York", 5) << endl;
    cout << vacation(trip, "New York", 7) << endl;
    cout << vacation(trip, "New York", 8) << endl;

    return 0;
}
