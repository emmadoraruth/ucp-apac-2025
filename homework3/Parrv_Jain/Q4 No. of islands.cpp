#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
            return;

        grid[r][c] = 0;

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int numIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    count++;        
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};


int main() {
    vector<vector<int>> grid = {
        {1,0,1,1,1},
        {1,1,0,1,1},
        {0,1,0,0,0},
        {0,0,0,1,0},
        {0,0,0,0,0}
    };

    Solution s;
    cout << s.numIslands(grid); 
    return 0;
}
