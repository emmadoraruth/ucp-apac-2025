#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> prerequisiteCourses(
        vector<string>& courses,
        unordered_map<string, vector<string>>& prereq
    ) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;

        // Initialize
        for (int i = 0; i < courses.size(); i++) {
            indegree[courses[i]] = 0;
        }

        // Build graph
        for (auto it = prereq.begin(); it != prereq.end(); ++it) {
            string course = it->first;
            for (int i = 0; i < it->second.size(); i++) {
                string pre = it->second[i];
                adj[pre].push_back(course);
                indegree[course]++;
            }
        }

        // Queue for courses with no prerequisites
        queue<string> q;
        for (auto it = indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0)
                q.push(it->first);
        }

        vector<string> order;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int i = 0; i < adj[curr].size(); i++) {
                string next = adj[curr][i];
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return order;
    }
};

int main() {
    vector<string> courses = {
        "Intro to Programming",
        "Data Structures",
        "Advanced Algorithms",
        "Operating Systems",
        "Databases"
    };

    unordered_map<string, vector<string>> prereq;
    prereq["Data Structures"] = {"Intro to Programming"};
    prereq["Advanced Algorithms"] = {"Data Structures"};
    prereq["Operating Systems"] = {"Advanced Algorithms"};
    prereq["Databases"] = {"Advanced Algorithms"};

    Solution s;
    vector<string> result = s.prerequisiteCourses(courses, prereq);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}
