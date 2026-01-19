#include <bits/stdc++.h>
using namespace std;

// I used graph and applied topological Kahn algorithm, it took me around 20 minutes to finish
// Time complexity: O(V + E)
// Space complexity: O(V + E)

vector<string> topokahn(
    unordered_map<string, vector<string> >& graph
) {
    unordered_map<string, int> in;

    for (unordered_map<string, vector<string> >::iterator it = graph.begin();it != graph.end(); it++) 
    {
        in[it->first] = 0;
    }

    for (unordered_map<string, vector<string> >::iterator it = graph.begin();it != graph.end(); it++) 
    {
        for (int i = 0; i < (int)it->second.size(); i++) 
        {
            in[it->second[i]]++;
        }
    }

    queue<string> q;
    for (unordered_map<string, int>::iterator it = in.begin();it != in.end(); it++) 
    {
        if (it->second == 0) 
        {
            q.push(it->first);
        }
    }

    vector<string> order;

    while (!q.empty()) 
    {
        string node = q.front();
        q.pop();
        order.push_back(node);

        for (int i = 0; i < (int)graph[node].size(); i++) 
        {
            string x = graph[node][i];
            in[x]--;
            if (in[x] == 0) 
            {
                q.push(x);
            }
        }
    }

    return order;
}

int main() {
    unordered_map<string, vector<string> > graph;

    graph["Intro to Programming"] = {"Data Structures"};
    graph["Data Structures"] = {"Advanced Algorithms"};
    graph["Advanced Algorithms"] = {"Operating Systems", "Databases"};

    vector<string> order = topokahn(graph);

    for (int i = 0; i < (int)order.size(); i++) {
        cout << order[i] << " | ";
    }

    cout << endl;
    return 0;
}
