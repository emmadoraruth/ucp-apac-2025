#include <bits/stdc++.h>
using namespace std;

vector<string> findCourseOrder(vector<string>& courses, map<string, vector<string>>& prereq){
    map<string, vector<string>> adj;
    map<string,int> indeg;
    for(auto &c : courses){
        adj[c] = {};
        indeg[c] = 0;
    }
    for(auto &p : prereq){
        for(auto &pre : p.second){
            adj[pre].push_back(p.first);
            indeg[p.first]++;
        }
    }

    queue<string> q;
    for(auto &c : courses){
        if(indeg[c]==0) q.push(c);
    }

    vector<string> order;
    while(!q.empty()){
        string node = q.front();
        q.pop();
        order.push_back(node);
        for(auto &neighbor : adj[node]){
            indeg[neighbor]--;
            if(indeg[neighbor]==0) q.push(neighbor);
        }
    }

    if(order.size() == courses.size()) return order;
    return {};
}

int main(){
    vector<string> courses = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};
    map<string, vector<string>> prereq = {
        {"Data Structures", {"Intro to Programming"}},
        {"Advanced Algorithms", {"Data Structures"}},
        {"Operating Systems", {"Advanced Algorithms"}},
        {"Databases", {"Advanced Algorithms"}}
    };

    vector<string> res = findCourseOrder(courses, prereq);
    for(auto &c : res) cout << c << " | " << endl;
}
