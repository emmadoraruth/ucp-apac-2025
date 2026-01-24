//Question 8: AlternatingPath
//Given an origin and a destination in a directed graph in which edges can be blue or red, determine the 
//length of the shortest path from the origin to the destination in which the edges traversed alternate in 
//color. Return -1 if no such path exists.

// Examples: 
// [(A, B, "blue"), (A, C, "red"), (B, D, "blue"), (B, E, "blue"), (C, B, "red"), (D, C, "blue"), (A, D, "red"), (D, E, "red"), (E, C, 
// "red")] 
// Input: origin = A, destination = E 
// Output: 4 (path: A→D (red), D→C (blue), C→B (red), B→E (blue)) 
// Input: origin = E, destination = D 
// Output: -1 (only path is: E→C (red), C→B (red), B→D (blue))

//Used the concept of Disjoint set

//time complexity  :O(n*m)
//space complexity :O(n) in queue

#include <bits/stdc++.h>

// color: 1 = blue, 2 = red
int shortestAlternatingPath(
    std::vector<std::pair<std::pair<char,char>, std::string>>& edges,
    char origin,
    char destination
) {
    // build adjacency list
    std::unordered_map<char, std::vector<std::pair<char,int>>> adj;

    for (size_t i = 0; i < edges.size(); i++) {
        char u = edges[i].first.first;
        char v = edges[i].first.second;
        std::string color = edges[i].second;

        int c = (color == "blue") ? 1 : 2;
        adj[u].push_back(std::make_pair(v, c));
    }

    // visited[node][color]
    std::unordered_map<char, std::vector<bool>> visited;
    for (auto it = adj.begin(); it != adj.end(); ++it) {
        visited[it->first] = std::vector<bool>(3, false);
    }

    // queue stores: (node, lastColor, distance)
    std::queue<std::tuple<char,int,int>> q;
    q.push(std::make_tuple(origin, 0, 0));

    while (!q.empty()) {
        std::tuple<char,int,int> curr = q.front();
        q.pop();

        char node = std::get<0>(curr);
        int lastColor = std::get<1>(curr);
        int dist = std::get<2>(curr);

        if (node == destination) {
            return dist;
        }

        for (size_t i = 0; i < adj[node].size(); i++) {
            char next = adj[node][i].first;
            int edgeColor = adj[node][i].second;

            if (edgeColor != lastColor && !visited[next][edgeColor]) {
                visited[next][edgeColor] = true;
                q.push(std::make_tuple(next, edgeColor, dist + 1));
            }
        }
    }

    return -1;
}

int main() {
    std::vector<std::pair<std::pair<char,char>, std::string>> edges = {
        {{'A','B'}, "blue"},
        {{'A','C'}, "red"},
        {{'B','D'}, "blue"},
        {{'B','E'}, "blue"},
        {{'C','B'}, "red"},
        {{'D','C'}, "blue"},
        {{'A','D'}, "red"},
        {{'D','E'}, "red"},
        {{'E','C'}, "red"}
    };

    std::cout << shortestAlternatingPath(edges, 'A', 'E') << std::endl; // 4
    std::cout << shortestAlternatingPath(edges, 'E', 'D') << std::endl; // -1

    return 0;
}
