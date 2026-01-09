// I've used 3 DS/Algo - DFS, BFS, DSU

// Time Complexity 
// DFS - O(m*n)
// BFS - O(m*n)
// DSU - O(m*n*a(m*n)) = O(m*n) 
// where 'm' is the number of rows, 'n' is number of columns and 'a' is inverse Ackermann function which is nearly constant even for large inputs

// Memory Complexity

// DFS - O(m*n)
// BFS - O(m*n)
// DSU - O(m*n)


#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};


// DFS

void dfs (int x, int y, vector<vector<int>>& grid, set<pair<int,int>>& visitedDFS){
    int m = grid.size();
    int n = grid[0].size();

    visitedDFS.insert({x, y});

    for (auto [dx, dy] : directions){
        int newx = x + dx; 
        int newy = y + dy;

        if (newx < 0 || newx > m - 1 || newy < 0 || newy > n - 1 || grid[newx][newy] == 0 || visitedDFS.count({newx, newy}) == 1 ) continue; 
        dfs (newx , newy, grid, visitedDFS);
        
    }
}

// BFS

void bfs (int i, int j, vector<vector<int>>& grid, set<pair<int,int>>& visitedBFS){
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>> q;
    q.push({i, j});
    visitedBFS.insert({i, j});

    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        
        for (auto [dx, dy] : directions){
            int newx = x + dx; 
            int newy = y + dy;

            if (newx < 0 || newx > m - 1 || newy < 0 || newy > n - 1 || grid[newx][newy] == 0 || visitedBFS.count({newx, newy}) == 1) continue; 

            q.push({newx, newy});
            visitedBFS.insert({newx, newy});
        }
  
    }
}

// DSU
class DSU{
public:
    vector<int> parent, rank;

    DSU (int n){
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find (int node){
        if (parent[node] != node){
            parent[node] = find (parent[node]);
        }

        return node = parent[node];
    }

    void merge (int nodeX, int nodeY){
        int parentX = find (nodeX);
        int parentY = find (nodeY);

        if (parentX == parentY) return;

        if (rank[parentX] < rank[parentY]){
            swap(parentX, parentY);
        }

        parent[parentY] = parentX;

        if (rank[parentX] == rank[parentY]){
            rank[parentX]++;
        }
    }
};

int id (int x, int y, int n){
    return x*n + y;
}

void NumberOfIslands (vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int islandCountDFS = 0;
    int islandCountBFS = 0;

    set<pair<int,int>> visitedDFS;
    set<pair<int,int>> visitedBFS;

    DSU dsu(n*m);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            
            // DFS
            if (grid[i][j] == 1 && visitedDFS.count({i, j}) == 0){
                dfs (i, j, grid, visitedDFS);
                islandCountDFS++;
            }

            // BFS
            if (grid[i][j] == 1 && visitedBFS.count({i, j}) == 0){
                bfs (i, j, grid, visitedBFS);
                islandCountBFS++;
            }

            // DSU
            if (grid[i][j] == 1){
                vector<pair<int,int>> rightDownDirections = {{0,1}, {1,0}};

                for (auto [dx, dy] : rightDownDirections){
                    int newx = i + dx;
                    int newy = j + dy;

                    if (newx > m-1 || newy > n-1) continue;

                    if (grid[newx][newy] == 1){
                        dsu.merge(id(newx, newy, n), id(i, j, n));
                    }
                }
            }
        }
    }

    unordered_set<int> islandCountDSU;

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1) islandCountDSU.insert(dsu.find(id(i,j,n)));
        }
    }

    cout << islandCountDFS << endl;
    cout << islandCountBFS << endl;
    cout << islandCountDSU.size() << endl;
}



int main() {
    vector<vector<int>> grid = {
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    };

    NumberOfIslands(grid);
    return 0;
}

// Time Taken - 40 min