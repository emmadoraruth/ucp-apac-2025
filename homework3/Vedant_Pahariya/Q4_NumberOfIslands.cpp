#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Given a binary matrix in which 1s represent land and 0s represent water, return the number of islands (contiguous 1s surrounded by 0s or the edge of the matrix).

// Forward declarations
int num_island(vector<vector<int>> &grid);
int num(vector<vector<int>> &grid);
void dfs2(vector<vector<int>> &grid, vector<vector<int>> &visit, int i, int j);

//Method-1 
int num_island(vector<vector<int>> &grid){
    int rows = grid.size();
    if(rows == 0) return 0;
    int cols = grid[0].size();
    int count = 0;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    vector<int> dirX = {-1, 0, 1, 0};
    vector<int> dirY = {0, 1, 0, -1};
    function<void(int, int)> dfs = [&](int x, int y){
        visited[x][y] = true;
        for(int d = 0; d < 4; d++){
            int newX = x + dirX[d];
            int newY = y + dirY[d];
            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
               grid[newX][newY] == 1 && !visited[newX][newY]){
                dfs(newX, newY);
            }
        }
    };

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                count++;
            }
        }
    }
    return count;
}

//Method-2 
int num(vector<vector<int>> &grid){
    int row = grid.size();
    if(row == 0) return 0;
    int col = grid[0].size();

    vector<vector<int>> visit(row, vector<int>(col,0));

    int count = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == 1 && visit[i][j] == 0){
                dfs2(grid, visit, i, j);
                count++;
            }
        }
    }
    return count;
}

void dfs2(vector<vector<int>> &grid, vector<vector<int>> &visit, int i, int j){
    visit[i][j] = 1;
    int row = grid.size();
    int col = grid[0].size();
    
    // up
    if(i-1 >= 0 && grid[i-1][j] == 1 && visit[i-1][j] == 0){
        dfs2(grid, visit, i-1, j);
    }
    // down
    if(i+1 < row && grid[i+1][j] == 1 && visit[i+1][j] == 0){
        dfs2(grid, visit, i+1, j);
    }
    // left
    if(j-1 >= 0 && grid[i][j-1] == 1 && visit[i][j-1] == 0){
        dfs2(grid, visit, i, j-1);
    }
    // right
    if(j+1 < col && grid[i][j+1] == 1 && visit[i][j+1] == 0){
        dfs2(grid, visit, i, j+1);
    }
}

// Test function for both methods
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    vector<vector<int>> grid2 = grid; // Copy for method-2

    cout << "Test Grid:" << endl;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of islands (Method-1): " << num_island(grid) << endl;
    cout << "Number of islands (Method-2): " << num(grid2) << endl;
    
    return 0;
}