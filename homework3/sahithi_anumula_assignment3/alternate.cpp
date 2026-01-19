#include <bits/stdc++.h>
using namespace std;

//I used graph and applied bfs algo, It took me around 30 minutes to finish
//Time complexity: O(V + E)  
//Space complexity: O(V + E)


int alternate(vector<tuple<string, string, string> >& e,string o,string d) 
{
    unordered_map<string, vector<pair<string, string> > > graph;

    for (int i = 0; i < (int)e.size(); i++) 
    {
        string u = get<0>(e[i]);
        string v = get<1>(e[i]);
        string color = get<2>(e[i]);
        graph[u].push_back(make_pair(v, color));
    }

    queue<pair<string, string> > q;
    unordered_set<string> vis;

    q.push(make_pair(o, ""));
    vis.insert(o + "|");

    int dis = 0;

    while (!q.empty()) 
    {
        int size = q.size();

        for (int i = 0; i < size; i++) 
        {
            pair<string, string> curr = q.front();
            q.pop();

            string node = curr.first;
            string last = curr.second;

            if (node == d) return dis;

            for (int j = 0; j < (int)graph[node].size(); j++) 
            {
                string next = graph[node][j].first;
                string color = graph[node][j].second;

                if (color != last) 
                {
                    string state = next + "|" + color;
                    if (vis.find(state) == vis.end()) 
                    {
                        vis.insert(state);
                        q.push(make_pair(next, color));
                    }
                }
            }
        }
        dis++;
    }

    return -1;
}

int main() {

    vector<tuple<string, string, string> > e;
    e.push_back(make_tuple("A", "B", "blue"));
    e.push_back(make_tuple("A", "C", "red"));
    e.push_back(make_tuple("B", "D", "blue"));
    e.push_back(make_tuple("B", "E", "blue"));
    e.push_back(make_tuple("C", "B", "red"));
    e.push_back(make_tuple("D", "C", "blue"));
    e.push_back(make_tuple("A", "D", "red"));
    e.push_back(make_tuple("D", "E", "red"));
    e.push_back(make_tuple("E", "C", "red"));

    cout << alternate(e, "A", "E") << endl;
    cout << alternate(e, "E", "D") << endl;

    return 0;
}
