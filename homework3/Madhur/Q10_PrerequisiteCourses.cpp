/*
Data Structure Used:
Graph (Adjacency List), Queue, Hashmap

Algorithm:
Topological Sort (Kahn’s Algorithm)

Approach:
Model courses as nodes and prerequisites as directed edges.
Using topological sorting to produce a valid order in which all prerequisites are completed before their dependent courses.

Time Complexity:
- O(V + E)
  where V = number of courses, E = number of prerequisite relations

Space Complexity:
- O(V + E)

Time Taken:
34 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findCourseOrder(
        vector<string>& courses,
        unordered_map<string, vector<string>>& prereqs
    ) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // Initialize graph and indegree
        for (auto& course : courses) {
            graph[course] = {};
            indegree[course] = 0;
        }

        // Build graph
        for (auto& p : prereqs) {
            string course = p.first;
            for (auto& pre : p.second) {
                graph[pre].push_back(course);
                indegree[course]++;
            }
        }

        // Push courses with no prerequisites
        queue<string> q;
        for (auto& c : indegree) {
            if (c.second == 0)
                q.push(c.first);
        }

        vector<string> order;

        // Kahn’s Algorithm
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            order.push_back(curr);

            for (auto& next : graph[curr]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If cycle exists, return empty order
        if (order.size() != courses.size())
            return {};

        return order;
    }
};

int main() {
    Solution s;

    vector<string> courses1 = {
        "Intro to Programming",
        "Data Structures",
        "Advanced Algorithms",
        "Operating Systems",
        "Databases"
    };

    unordered_map<string, vector<string>> prereqs1 = {
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

    unordered_map<string, vector<string>> prereqs2 = {
        {"Contemporary Literature", {"Intro to Writing"}},
        {"Ancient Literature", {"Intro to Writing"}},
        {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}},
        {"Plays & Screenplays", {"Intro to Writing"}}
    };

    auto order1 = s.findCourseOrder(courses1, prereqs1);
    auto order2 = s.findCourseOrder(courses2, prereqs2);

    for (auto& c : order1) cout << c << " | ";
    cout << endl;

    for (auto& c : order2) cout << c << " | ";
    cout << endl;

    return 0;
}
