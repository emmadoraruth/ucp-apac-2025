/*
Approach:
Traverse the grid and whenever an unvisited land cell (1) is found,
run DFS to mark the entire connected component as visited and count it as one island.

Time Complexity:
- O(rows × cols)

Space Complexity:
- O(rows × cols)

Time Taken:
24 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int rows, cols;
    vector<vector<int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
            return;

        grid[r][c] = 0;  // marked by me as visited

        for (auto &d : directions) {
            dfs(r + d[0], c + d[1], grid);
        }
    }

public:
    int numIslands(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid1 = {
        {1,0,1,1,1},
        {1,1,1,0,1},
        {1,0,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };

    vector<vector<int>> grid2 = {
        {1,0,0},
        {0,0,0}
    };

    cout << s.numIslands(grid1) << endl; // Output: 3
    cout << s.numIslands(grid2) << endl; // Output: 1

    return 0;
}
