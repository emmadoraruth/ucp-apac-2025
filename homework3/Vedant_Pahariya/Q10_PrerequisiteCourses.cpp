// Given a list of courses that a student needs to take to complete their major and a map of courses to their prerequisites, return a valid order for them to take their courses assuming they only take one course for their major at once.

#include <bits/stdc++.h>
using namespace std;

// This problem can be interpreted as a graph problem where I can consider the courses in prerequisite data as nodes and a directed edge from preq to major course. So, after making this complete graph, I just have to traverse it completely from a course which doesn't have any dependency effectively 0 indegree. Then I realized that this is directly based on Kahn's algorithm.

// Time Complexity: O(V + E)
// Space Complexity: O(E)
vector<string> ordered(vector<string> courses, unordered_map<string, vector<string>> preq){
    vector<string> out;

    // Creating Adjacency Matrix
    unordered_map<string, unordered_set<string>> adj;

    for(auto& it : preq){
        for (auto& neigh : it.second){
            string first = neigh;
            string second = it.first ;

            adj[first].insert(second);
        }
    } // O(N + E)

    // Calculating Indegree of every node
    unordered_map<string, int> indeg;

    for(auto& it : courses){
            indeg[it] = 0;
    }

    for(auto& it : preq){
        indeg[it.first] += it.second.size();
    }

    // Queue for Kahn's algo
    queue<string> q;

    for(auto it : indeg){
        if(it.second == 0){
            q.push(it.first);
        }
    }

    while(!q.empty()){
        string top = q.front();
        out.push_back(top);

        q.pop();

        for(auto it : adj[top]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }

    return out;
}


int main(){
    vector<string> input1 = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};

    unordered_map<string, vector<string>> preq1 = {
        {"Data Structures", {"Intro to Programming"}},
        {"Advanced Algorithms", {"Data Structures"}},
        {"Operating Systems", {"Advanced Algorithms"}},
        {"Databases", {"Advanced Algorithms"}}
    };

    vector<string> out1 = ordered(input1, preq1);

    for(auto it: out1){
        cout << it << ", ";
    }
    cout << endl;

    vector<string> input2 = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};

    unordered_map<string, vector<string>> preq2 = {
        {"Contemporary Literature", {"Intro to Writing"}},
        {"Ancient Literature", {"Intro to Writing"}},
        {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}},
        {"Plays & Screenplays", {"Intro to Writing"}}
    };

    vector<string> out2 = ordered(input2, preq2);
    for(auto it: out2){
        cout << it << ", ";
    }
    cout << endl;
}