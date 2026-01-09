// DS/Algo used - Topological sort

// Time Complexity O(V + E)

// Memory Complexity O(V + E)

// where V = number of courses and E = number of prerequisites relations

#include <bits/stdc++.h>
using namespace std;

vector<string> topologicalSort(unordered_map<string, vector<string>>& graph){
    int n = graph.size();

    unordered_map<string, int> indegree;

    for(auto [node, neighbours] : graph){
        indegree[node] = 0; 
    }

    for(auto [node, neighbours] : graph){
        for(string nbr : neighbours){
            indegree[nbr]++;
        }
    }

    queue<string> q;

    for(auto [node, neighbours] : graph){
        if(indegree[node] == 0) q.push(node); // pushing all the nodes with zero depedencies
    }

    vector<string> topoSort;

    while(!q.empty()){
        string node = q.front();
        topoSort.push_back(node);
        q.pop();

        for(string nbr : graph[node]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    return topoSort;
}

vector<string> PreReqCourses(vector<string> courses, unordered_map<string, vector<string>> prerequisites){
    int n = courses.size();
    unordered_map<string, vector<string>> adj(n);

    for (string course : courses) {
        adj[course] = {};
    }

    for(auto [course , prerequisite] : prerequisites){
        for(auto prereq : prerequisite){
            adj[prereq].push_back(course);
        }
    }

    return topologicalSort(adj);

}


int main(){
    vector<string> courses1 = {
    "Intro to Programming",
    "Data Structures",
    "Advanced Algorithms",
    "Operating Systems",
    "Databases"
    };

    unordered_map<string, vector<string>> prerequisites1 = {
    {"Data Structures", {"Intro to Programming"}},
    {"Advanced Algorithms", {"Data Structures"}},
    {"Operating Systems", {"Advanced Algorithms"}},
    {"Databases", {"Advanced Algorithms"}}
    };

    vector<string> courses2 = {
    "Intro to Writing",
    "Contemporary Literature",
    "Ancient Literature",
    "Comparative Literature",
    "Plays & Screenplays"
    };

    unordered_map<string, vector<string>> prerequisites2 = {
    {"Contemporary Literature", {"Intro to Writing"}},
    {"Ancient Literature", {"Intro to Writing"}},
    {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}},
    {"Plays & Screenplays", {"Intro to Writing"}}
    };


    vector<string> validOrder1 = PreReqCourses(courses1, prerequisites1); 

    for(string course : validOrder1){
        cout << course << ", "; 
    }
    cout << endl;

    vector<string> validOrder2 = PreReqCourses(courses2, prerequisites2);
    for(string course : validOrder2){
        cout << course << ", ";
    }

}

// Time Taken - 17 min