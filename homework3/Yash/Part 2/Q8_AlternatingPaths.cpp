// Question 8: Alternating Path ; Technique Used : BFS
// Time Taken : 38 minutes

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int ShortestAlternatingPath(
    vector<tuple<string, string, string>> edges,
    string origin,
    string destination
){
    unordered_map<string, vector<pair<string, string>>> graph;

    
    for(auto e : edges){
        graph[get<0>(e)].push_back({get<1>(e), get<2>(e)});
    }

    
    unordered_map<string, bool> visitedRed;
    unordered_map<string, bool> visitedBlue;

    queue<pair<string, string>> q;   
    queue<int> dist;                 

    q.push({origin, "none"});
    dist.push(0);

    while(!q.empty()){
        string node = q.front().first;
        string lastColor = q.front().second;
        int d = dist.front();

        q.pop();
        dist.pop();

        if(node == destination){
            return d;
        }

        for(auto edge : graph[node]){
            string next = edge.first;
            string color = edge.second;

            if(color == lastColor) continue;

            if(color == "red" && !visitedRed[next]){
                visitedRed[next] = true;
                q.push({next, "red"});
                dist.push(d + 1);
            }

            if(color == "blue" && !visitedBlue[next]){
                visitedBlue[next] = true;
                q.push({next, "blue"});
                dist.push(d + 1);
            }
        }
    }

    return -1;
}

int main(){

    vector<tuple<string, string, string>> edges = {
        {"A", "B", "blue"},
        {"A", "C", "red"},
        {"B", "D", "blue"},
        {"B", "E", "blue"},
        {"C", "B", "red"},
        {"D", "C", "blue"},
        {"A", "D", "red"},
        {"D", "E", "red"},
        {"E", "C", "red"}
    };

    cout << ShortestAlternatingPath(edges, "A", "E") << endl; 
    cout << ShortestAlternatingPath(edges, "E", "D") << endl; 

    return 0;
}
