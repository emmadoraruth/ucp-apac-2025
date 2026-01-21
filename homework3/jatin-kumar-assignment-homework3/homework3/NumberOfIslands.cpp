#include <iostream>
using namespace std;
#include <vector>
// DFS to count number of islands in a grid
// tc: O(n*m)
// sc: O(n*m) for visited array and O(n*m) for recursion stack in worst case
// time taken:21 min
void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1, 0, 1, 0}; // for checking 4 directions
        int dcol[] = {0, 1, 0, -1}; // for checking 4 directions

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }

    int main(){
        vector<vector<char>> grid={
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout<<numIslands(grid)<<endl;
    return 0;
    }


