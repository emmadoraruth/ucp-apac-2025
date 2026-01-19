#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, vector<int>> adj;
    int size;
 
    //constructor of graph
    graph(vector<pair<int,int>> edges, int n) {
        size = n;
        // initialize all nodes
        for (int i = 0; i < n; i++) {
            adj[i] = {};
        }
        //Creating the adjacent map
        for (auto &e : edges) {
            int u = e.first;
            int v = e.second;
            adj[u].push_back(v);
        }
    }

    void printAdj()
    {
        for (int i = 0; i < size; i++){
            cout << i << "  ";
            for (auto j : adj[i]){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool dfsHelperFunction(int node, int val, vector<bool> &visited)
    {
        if (node == val)
            return true;

        visited[node] = true;

        for (auto &i : adj[node]){
            if (!visited[i]){
                if (dfsHelperFunction(i, val, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfssearch(int val){
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++){
            if (!visited[i]){
                if (dfsHelperFunction(i, val, visited))
                    return true;
            }
        }
        return false;
    }

    bool bfssearch(int val){
        vector<bool> visited(size, false);

        for (int start = 0; start < size; start++){
            if (visited[start])
                continue;
            queue<int> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty()){
                int node = q.front();
                q.pop();

                if (node == val)
                    return true;

                for (int nei : adj[node]){
                    if (!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        return false;
    }

   void topologicalSortDfsHelper(int node, stack<int>& s, vector<bool>& visited){
    if (visited[node])
        return;

    visited[node] = true;

    for (auto& neigh : adj[node]){
        if (!visited[neigh]){
            topologicalSortDfsHelper(neigh, s, visited);
        }
    }
    s.push(node);
}
    vector<int> topologicalSortdfs(){
        vector<int> topo;
        stack<int> s;
        vector<bool> visited(size, false);

        for (int i = 0; i < size; i++){
            if (!visited[i])
                topologicalSortDfsHelper(i, s, visited);
        }

        while (!s.empty()){
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }

    vector<int> KhansAlgo_topologicalSortbfs(){
        vector<int> indegree(size, 0);

        for (int i = 0; i < size; i++)
        {
            for (auto& j : adj[i])
            {
                indegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < size; i++){
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (auto& neigh : adj[front]){
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return ans;
    }
};

int main(){
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    graph g(edges, 4);

    g.printAdj();

    cout << "Enter the value to find : ";
    int valtofind;
    cin >> valtofind;

    cout << "Search Using DFS Algo : "
         << (g.dfssearch(valtofind) ? "Present" : "Absent") << endl;

    cout << "Search using BFS Algo : "
         << (g.bfssearch(valtofind) ? "Present" : "Absent") << endl;

    vector<pair<int, int>> edges2 = {{0,1}, {0,2}, {1,3}, {2,3}};
    graph g2(edges2, 4);

    vector<int> topoByDfs = g2.topologicalSortdfs();
    cout << "Topological Sort by DFS : ";
    for (auto& i : topoByDfs)
        cout << i << " , ";
    cout << endl;

    vector<int> topoByBfs = g2.KhansAlgo_topologicalSortbfs();
    cout << "Topological Sort by BFS : ";
    for (auto& i : topoByBfs)
        cout << i << " , ";
    cout << endl;
}
