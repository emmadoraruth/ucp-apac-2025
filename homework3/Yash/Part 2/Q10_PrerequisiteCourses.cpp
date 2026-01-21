// Question 10 : Prerequisite Courses ; Technique Used : Topological Sort using Kahn's Algorithm
// Time Taken : 35 minutes

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> CourseOrder(
    vector<string> courses,
    unordered_map<string, vector<string>> prerequisites
){
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> indegree;

    
    for(string course : courses){
        indegree[course] = 0;
    }

    
    for(auto entry : prerequisites){
        string course = entry.first;
        for(string pre : entry.second){
            graph[pre].push_back(course);
            indegree[course]++;
        }
    }

    queue<string> q;

    
    for(auto entry : indegree){
        if(entry.second == 0){
            q.push(entry.first);
        }
    }

    vector<string> order;

    while(!q.empty()){
        string curr = q.front();
        q.pop();

        order.push_back(curr);

        for(string next : graph[curr]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }

    return order;
}

void Print(vector<string> arr){
    for(string s : arr){
        cout << s << " | ";
    }
    cout << endl;
}

int main(){

    // Testcase 1
    vector<string> courses1 = {
        "Intro to Programming",
        "Data Structures",
        "Advanced Algorithms",
        "Operating Systems",
        "Databases"
    };

    unordered_map<string, vector<string>> prereq1 = {
        {"Data Structures", {"Intro to Programming"}},
        {"Advanced Algorithms", {"Data Structures"}},
        {"Operating Systems", {"Advanced Algorithms"}},
        {"Databases", {"Advanced Algorithms"}}
    };

    // Testcase 2
    vector<string> courses2 = {
        "Intro to Writing",
        "Contemporary Literature",
        "Ancient Literature",
        "Comparative Literature",
        "Plays & Screenplays"
    };

    unordered_map<string, vector<string>> prereq2 = {
        {"Contemporary Literature", {"Intro to Writing"}},
        {"Ancient Literature", {"Intro to Writing"}},
        {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}},
        {"Plays & Screenplays", {"Intro to Writing"}}
    };

    Print(CourseOrder(courses1, prereq1));
    Print(CourseOrder(courses2, prereq2));

    return 0;
}
