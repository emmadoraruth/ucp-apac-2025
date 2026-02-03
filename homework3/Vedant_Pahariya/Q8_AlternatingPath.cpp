// Given an origin and a destination in a directed graph in which edges can be blue or red, determine the length of the shortest path from the origin to the destination in which the edges traversed alternate in color. Return -1 if no such path exists.

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<tuple<char, char, string>> input, char origin, char destiny){
    unordered_map<char, vector<pair<char,string>>> adj;

    // constructing the adjacency matrix
    for (auto it : input){
        char start = get<0>(it);
        char end = get<1>(it);
        string color = get<2>(it);

        adj[start].push_back({end, color});
    }

    unordered_set<string> visit;
    // unordered because O(1) on an average time complexity for finding (ordered is O(logn))
    // set because no repetition and finding operation on vector is costly 

    // Preparing the queue for BFS
    queue<pair<char, string>> q;
    q.push({origin, ""});
    visit.insert(string(1, origin) + "_");

    // Counter for the length
    int count = 0;


    while(!q.empty()){
        int size = q.size();

        for(int i =0 ; i< size ; i++){
            pair<char,string> temp = q.front();
            q.pop();            

            if(temp.first == destiny){
                return count;
            }

            for(auto neighbour : adj[temp.first]){
                // here, checking for both if visited previously and alternate colors
                    string key = string(1, neighbour.first) + "_" + neighbour.second;
                if(visit.count(key) == 0 && neighbour.second != temp.second){
                    visit.insert(key);
                    q.push(neighbour);
                }
            }
        }
        count++;
    }
    return -1;
}


int main(){
    // Test case 1: origin = A, destination = E
    // Expected output: 4 (path: A→D (red), D→C (blue), C→B (red), B→E (blue))
    vector<tuple<char, char, string>> edges = {
        {'A', 'B', "blue"},
        {'A', 'C', "red"},
        {'B', 'D', "blue"},
        {'B', 'E', "blue"},
        {'C', 'B', "red"},
        {'D', 'C', "blue"},
        {'A', 'D', "red"},
        {'D', 'E', "red"},
        {'E', 'C', "red"}
    };
    
    cout << "Test Case 1:" << endl;
    cout << "Input: origin = A, destination = E" << endl;
    int result1 = shortest(edges, 'A', 'E');
    cout << "Output: " << result1 << endl;
    cout << "Expected: 4 " << endl;
    cout << endl;
    
    // Test case 2: origin = E, destination = D
    // Expected output: -1 (only path is: E→C (red), C→B (red), B→D (blue))
    cout << "Test Case 2:" << endl;
    cout << "Input: origin = E, destination = D" << "\n";
    int result2 = shortest(edges, 'E', 'D');
    cout << "Output: " << result2 << endl;
    cout << "Expected: -1 " << "\n";

    return 0;
}

// Thinking Idea:
// As we have to find the shortest path from origin to the destination, there can be two ways, one: run dfs on the entire tree and maintain a variable count which we will update regular on reaching the destination node. Other do the bfs and once we reach the destination, it is the shortest path because we are travering in the level order so the once reaching it first is shortest