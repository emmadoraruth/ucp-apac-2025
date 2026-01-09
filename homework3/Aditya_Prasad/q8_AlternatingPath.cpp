// DS/Algo used - BFS

// Time Complexity O(V + E)

// Memory Complexity O(V + E)

// where V = number of cities and E = number of directed paths

#include <bits/stdc++.h>
using namespace std;

int AlternatingPath(vector<vector<string>> paths, string origin, string destination){
    unordered_map<string, vector<pair<string, int>> > adj;

    for(vector<string> path : paths){
        string src = path[0];
        string dest = path[1];
        string color = path[2];
        int col = 0;

        if (color == "blue") col = 1;
        
        adj[src].push_back({dest, col});
    }

    queue<tuple<string,int,int>> q;
    q.push({origin, 0, -1});
    unordered_map<string, unordered_set<int>> visited;

    // node, len, color

    while(!q.empty()){
        auto [node, len, currColor] = q.front();
        q.pop();

        if (node == destination) return len;

        if (adj.count(node) == 0) continue;

        for(auto [nbr, nextColor] : adj[node]){
            if(nextColor == currColor) continue;
            if(visited[nbr].count(nextColor) == 1&& currColor != -1) continue;

            q.push({nbr, len + 1, nextColor});
            visited[nbr].insert(nextColor);
        }
    }

    return -1;

}

int main(){
    vector<vector<string>> edges = {
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

    cout << AlternatingPath(edges, "A", "E"); // 4
    cout << endl;
    cout << AlternatingPath(edges, "E", "D"); // -1
}

// Time Taken - 30 min