// Technique : Dynamic programming (Memoization)
// T.C : O(n*m)
// M.C : O(n*m)


#include <bits/stdc++.h>
using namespace std;


int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int m = grid.size();
    int n = grid[0].size();

    if (i >= m || j >= n) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int left = 0, up = 0, diag = 0;
    if (grid[i][j] == 1) {
        left = f(i, j + 1, grid, dp);
        up = f(i + 1, j, grid, dp);
        diag = f(i + 1, j + 1, grid, dp);
    } else {
        return 0;
    }
    
    return dp[i][j] = min({left, up, diag}) + 1;
}

int largestSquare(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int largestArea = 0;
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int area = f(i, j, grid, dp);
                largestArea = max(area, largestArea);
            }
        }
    }

    return largestArea;
}

int main() {
    vector<vector<int>> grid1 = {{0, 1, 0, 1},
                            {0, 0, 1, 1},
                            {0, 1, 1, 1},
                            {0, 0, 1, 1}};

    vector<vector<int>> grid2 = {{0, 1, 0, 1, 1},
                            {0, 0, 1, 1, 1},
                            {1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1},
                            {0, 1, 1, 0, 0}};

    cout << largestSquare(grid1) << endl;
    cout << largestSquare(grid2);

    return 0;
}

// Time Taken - 35 mins