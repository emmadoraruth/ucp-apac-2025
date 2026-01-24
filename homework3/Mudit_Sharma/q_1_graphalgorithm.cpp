#include <bits/stdc++.h>

class graph
{
public:
    std::unordered_map<int, std::vector<int>> adj;
    int size;
 
    //constructor of graph
    graph(std::vector<std::pair<int,int>> edges, int n) {
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

    //time complexity  :O(n+m)
    //space complexity :O(1)
    void printAdj()
    {
        for (int i = 0; i < size; i++){
            std::cout << i << "  ";
            for (auto j : adj[i]){
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    bool dfsHelperFunction(int node, int val, std::vector<bool> &visited)
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

    //time complexity  :O(n+m)
    //space complexity :O(1)
    bool dfssearch(int val){
        std::vector<bool> visited(size, false);
        for (int i = 0; i < size; i++){ 
            if (!visited[i]){
                if (dfsHelperFunction(i, val, visited))
                    return true;
            }
        }
        return false;
    }

    //time complexity  :O(n+m)
    //space complexity :O(1)
    bool bfssearch(int val){
        std::vector<bool> visited(size, false);

        for (int start = 0; start < size; start++){
            if (visited[start])
                continue;
            std::queue<int> q;
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

   void topologicalSortDfsHelper(int node, std::stack<int>& s, std::vector<bool>& visited){
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

    //time complexity  :O(n+m)
    //space complexity :O(n)
    std::vector<int> topologicalSortdfs(){
        std::vector<int> topo;
        std::stack<int> s;
        std::vector<bool> visited(size, false);

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

    //time complexity  :O(n+m)
    //space complexity :O(n) in making the indegree
    std::vector<int> KhansAlgo_topologicalSortbfs(){
        std::vector<int> indegree(size, 0);

        for (int i = 0; i < size; i++)
        {
            for (auto& j : adj[i])
            {
                indegree[j]++;
            }
        }

        std::queue<int> q;
        for (int i = 0; i < size; i++){
            if (indegree[i] == 0)
                q.push(i);
        }

        std::vector<int> ans;
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
    std::vector<std::pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    graph g(edges, 4);

    g.printAdj();

    std::cout << "Enter the value to find : ";
    int valtofind;
    std::cin >> valtofind;

    std::cout << "Search Using DFS Algo : "
         << (g.dfssearch(valtofind) ? "Present" : "Absent") << std::endl;

    std::cout << "Search using BFS Algo : "
         << (g.bfssearch(valtofind) ? "Present" : "Absent") << std::endl;

    std::vector<std::pair<int, int>> edges2 = {{0,1}, {0,2}, {1,3}, {2,3}};
    graph g2(edges2, 4);

    std::vector<int> topoByDfs = g2.topologicalSortdfs();
    std::cout << "Topological Sort by DFS : ";
    for (auto& i : topoByDfs)
        std::cout << i << " , ";
    std::cout << std::endl;

    std::vector<int> topoByBfs = g2.KhansAlgo_topologicalSortbfs();
    std::cout << "Topological Sort by BFS : ";
    for (auto& i : topoByBfs)
        std::cout << i << " , ";
    std::cout << std::endl;
}
