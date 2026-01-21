#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>
#include<queue>

// Find a valid order of courses given prerequisites using Topological Sort (Kahn's Algorithm)
// tc: O(V+E)
// sc: O(V+E) for graph and O(V) for indegree and queue
// time taken: 36 min


vector<string>PrerequisiteCourses(vector<string> courses, map<string,vector<string>> prereq){
    // Build graph and indegree map

    map<string, vector<string>> graph;
    map<string, int> indegree;
    
    for(auto course : courses) {
        graph[course]; // Ensure all courses are in the graph
        indegree[course] = 0; // Initialize indegree
    }
    
    for(auto& it : prereq) {
        string course = it.first;
        for(string pre : it.second) {
            graph[pre].push_back(course);
            indegree[course]++;
        }
    }
    
    // Kahn's Algorithm for Topological Sort
    queue<string> q;
    for(auto& it : indegree) {
        if(it.second == 0) {
            q.push(it.first);
        }
    }
    
    vector<string> result;
    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        result.push_back(curr);
        
        for(string neighbor : graph[curr]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result;

}

int main(){
    // Test Case 1: Computer Science Courses
    // Input: ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"]
    // Prerequisites: { "Data Structures": ["Intro to Programming"], "Advanced Algorithms": ["Data Structures"], 
    //                  "Operating Systems": ["Advanced Algorithms"], "Databases": ["Advanced Algorithms"] }
    // Expected Output: ["Intro to Programming", "Data Structures", "Advanced Algorithms", "Databases", "Operating Systems"]
    // (Note: "Databases" and "Operating Systems" can be in any order since they both depend only on "Advanced Algorithms")
    
    vector<string> courses1 = {
        "Intro to Programming", 
        "Data Structures", 
        "Advanced Algorithms", 
        "Operating Systems", 
        "Databases"
    };

    map<string,vector<string>> prereq1 = {
        {"Data Structures",{"Intro to Programming"}},
        {"Advanced Algorithms",{"Data Structures"}},
        {"Operating Systems",{"Advanced Algorithms"}},
        {"Databases",{"Advanced Algorithms"}}
    };

    cout << "Test Case 1 (Computer Science Courses):" << endl;
    vector<string> order1 = PrerequisiteCourses(courses1, prereq1);
    for(auto course : order1){
        cout << course << endl;
    }
    cout << endl;

    // Test Case 2: Literature Courses
    // Input: ["Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"]
    // Prerequisites: { "Contemporary Literature": ["Intro to Writing"], "Ancient Literature": ["Intro to Writing"], 
    //                  "Comparative Literature": ["Ancient Literature", "Contemporary Literature"], "Plays & Screenplays": ["Intro to Writing"] }
    // Expected Output: ["Intro to Writing", "Plays & Screenplays", "Contemporary Literature", "Ancient Literature", "Comparative Literature"]
    // (Note: Order may vary for courses at the same level)
    
    vector<string> courses2 = {
        "Intro to Writing", 
        "Contemporary Literature", 
        "Ancient Literature", 
        "Comparative Literature", 
        "Plays & Screenplays"
    };

    map<string,vector<string>> prereq2 = {
        {"Contemporary Literature",{"Intro to Writing"}},
        {"Ancient Literature",{"Intro to Writing"}},
        {"Comparative Literature",{"Ancient Literature","Contemporary Literature"}},
        {"Plays & Screenplays",{"Intro to Writing"}}
    };

    cout << "Test Case 2 (Literature Courses):" << endl;
    vector<string> order2 = PrerequisiteCourses(courses2, prereq2);
    for(auto course : order2){
        cout << course << endl;
    }   
}
