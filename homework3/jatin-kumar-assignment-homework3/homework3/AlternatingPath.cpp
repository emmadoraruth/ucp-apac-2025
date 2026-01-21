#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>

// Find shortest alternating path in a colored directed graph using BFS
// tc: O(V+E)
// sc: O(V+E) for graph and O(V) for queue
// time taken: 34 min
int AlternatingPath(vector<vector<string>>paths,string start,string end){
    unordered_map<string,vector<pair<string,int>>> graph;

        for(auto& p:paths){
            string u=p[0];
            string v=p[1];
            string color=p[2];
            int colorint;
            if(color=="red")
                colorint=1;
            else
                colorint=0;
          ;

           graph[u].push_back({v,colorint});

        }
        queue<tuple<string,int,int>> q;
        q.push({start,0,-1});
         // node,length,color
         while(!q.empty()){
            auto [node,length,prevColor]=q.front();
            q.pop();

            if(node==end){
                return length;
            }

            for(auto& neighbor:graph[node]){
                string adjNode=neighbor.first;
                int edgeColor=neighbor.second;

                if(edgeColor!=prevColor){
                    q.push({adjNode,length+1,edgeColor});
                }
            }
         }

}

int main(){
    // Graph edges: [(A, B, "blue"), (A, C, "red"), (B, D, "blue"), (B, E, "blue"), 
    //               (C, B, "red"), (D, C, "blue"), (A, D, "red"), (D, E, "red"), (E, C, "red")]
    
    vector<vector<string>> paths = {
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

    // Test Case 1: Valid alternating path exists
    // Input: origin = A, destination = E
    // Expected Output: 4 (path: A→D (red), D→C (blue), C→B (red), B→E (blue))
    string start1 = "A";
    string end1 = "E";
    cout << "Test Case 1 (A to E): " << AlternatingPath(paths, start1, end1) << endl;

    // Test Case 2: No valid alternating path exists
    // Input: origin = E, destination = D
    // Expected Output: -1 (only path is: E→C (red), C→B (red), B→D (blue) - colors don't alternate)
    string start2 = "E";
    string end2 = "D";
    cout << "Test Case 2 (E to D): " << AlternatingPath(paths, start2, end2) << endl;

    return 0;
}