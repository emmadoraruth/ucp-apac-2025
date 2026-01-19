#include <bits/stdc++.h>
using namespace std;

// in this code i used array instead of set

map<int, vector<int>> adjacencyList(vector<pair<int,int>> edge) 
{
    map<int, vector<int>> graph;
    for (int i = 0; i < edge.size(); i++) 
    {
        int u = edge[i].first;
        int v = edge[i].second;
        graph[u].push_back(v);

        if (graph.find(v) == graph.end()) 
        {
            graph[v] = vector<int>();
        }
    }
    return graph;
}

bool bfs(int target, map<int, vector<int>> &graph) 
{
    unordered_map<int, bool> vis;
    queue<int> q;
    for (pair<const int, vector<int>> p : graph) 
    {
        int start = p.first;

        if (vis[start]) continue;
        vis[start] = true;
        q.push(start);

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            if (node == target)
            {
                return true;
            }else
            {
                for (int i = 0; i < graph[node].size(); i++) 
                {
                   int x = graph[node][i];
                    if (!vis[x]) 
                    {
                        vis[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }
    return false;
}

bool dfssearch(int node, int target,map<int, vector<int>> &graph,unordered_map<int, bool> &vis) 
{
    if (node == target)
    {
        return true;
    }else
    {
        vis[node] = true;

        for (int i = 0; i < graph[node].size(); i++) 
        {
            int x = graph[node][i];
            if (!vis[x]) 
            {
                if (dfssearch(x, target, graph, vis))
                return true;
            }
        }
    }
    return false;
}

bool dfs(int target, map<int, vector<int>> &graph) 
{
    unordered_map<int, bool> vis;

    for (pair<const int, vector<int>> p : graph) 
    {
        int node = p.first;
        if (!vis[node]) 
        {
            if (dfssearch(node, target, graph, vis))
                return true;
        }
    }
    return false;
}

vector<int> topokahn(map<int, vector<int>> &graph) 
{
    unordered_map<int, int> in;
    for (pair<const int, vector<int>> p : graph)
        in[p.first] = 0;
    for (pair<const int, vector<int>> p : graph) 
    {
        for (int i = 0; i < p.second.size(); i++) 
        {
            in[p.second[i]]++;
        }
    }

    queue<int> q;
    for (pair<const int, int> p : in) 
    {
        if (p.second == 0)
        {
            q.push(p.first);
        }
    }

    vector<int> order;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int i = 0; i < graph[node].size(); i++) 
        {
            int x = graph[node][i];
            in[x]--;
            if (in[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return order;
}

void toposearch(int node,map<int, vector<int>> &graph,unordered_map<int, bool> &vis,stack<int> &st) 
{
    vis[node] = true;

    for (int i = 0; i < graph[node].size(); i++) 
    {
        int x = graph[node][i];
        if (!vis[x])
        {
            toposearch(x, graph, vis, st);
        }
    }
    st.push(node);
}

vector<int> topodfs(map<int, vector<int>> &graph) 
{
    unordered_map<int, bool> vis;
    stack<int> st;
    for (pair<const int, vector<int>> p : graph) 
    {
        if (!vis[p.first])
        {
            toposearch(p.first, graph, vis, st);
        }
    }
    vector<int> order;
    while (!st.empty()) 
    {
        order.push_back(st.top());
        st.pop();
    }
    return order;
}
