#include <bits/stdc++.h>
using namespace std;

//I used graph and applied dfs algo, It took me around 35 minutes to finish
//Time complexity: O(V + E)  
//Space complexity: O(V + E)

int road(vector<string>& t, vector<pair<string, string> >& road) 
{
    unordered_map<string, vector<string> > graph;
    unordered_set<string> vis;

    for (int i = 0; i < (int)road.size(); i++) 
    {
        string a = road[i].first;
        string b = road[i].second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int net = 0;

    for (int i = 0; i < (int)t.size(); i++) {
        string town = t[i];

        if (vis.find(town) != vis.end()) continue;
        if (graph.find(town) == graph.end()) continue;

        net++;

        stack<string> st;
        st.push(town);
        vis.insert(town);

        while (!st.empty()) {
            string curr = st.top();
            st.pop();

            for (int j = 0; j < (int)graph[curr].size(); j++) {
                string next = graph[curr][j];
                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    st.push(next);
                }
            }
        }
    }

    return net;
}

int main() {
    

    vector<string> t1 = {
        "Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth",
        "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center",
        "Healy", "Anchorage"
    };

    vector<pair<string, string> > road1 = {
        {"Anchorage", "Homer"},
        {"Glacier Bay", "Gustavus"},
        {"Copper Center", "McCarthy"},
        {"Anchorage", "Copper Center"},
        {"Copper Center", "Fairbanks"},
        {"Healy", "Fairbanks"},
        {"Healy", "Anchorage"}
    };

    cout << road(t1, road1) << endl;

    vector<string> t2 = {
        "Kona", "Hilo", "Volcano", "Lahaina", "Hana",
        "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"
    };

    vector<pair<string, string> > road2 = {
        {"Kona", "Volcano"},
        {"Volcano", "Hilo"},
        {"Lahaina", "Hana"},
        {"Kahului", "Haiku"},
        {"Hana", "Haiku"},
        {"Kahului", "Lahaina"},
        {"Princeville", "Lihue"},
        {"Lihue", "Waimea"}
    };

    cout << road(t2, road2) << endl;

    return 0;
}
