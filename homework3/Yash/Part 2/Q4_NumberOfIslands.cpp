// Question 4 : Number of Islands ; Technique Used : DFS
// Time Taken : 40 minutes

#include <iostream>
#include <vector>
using namespace std;

void DFS(int i, int j, vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
        return;
    }

    grid[i][j] = 0;

    DFS(i + 1, j, grid);
    DFS(i - 1, j, grid);
    DFS(i, j + 1, grid);
    DFS(i, j - 1, grid);
}

int NumberOfIslands(vector<vector<int>> grid){
    if(grid.size() == 0){
        return 0;
    }

    int count = 0;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                count++;
                DFS(i, j, grid);
            }
        }
    }

    return count;
}

int main(){

    
    vector<vector<int>> testcase1 = {
        {1,0,1,1,1},
        {1,1,0,1,1},
        {0,1,0,0,0},
        {0,0,0,1,0},
        {0,0,0,0,0}
    };

    
    vector<vector<int>> testcase2 = {
        {1,0,0},
        {0,0,0}
    };

    
    vector<vector<int>> testcase3 = {
        {0,0,0},
        {0,0,0}
    };

    vector<vector<int>> testcase4 = {
        {1}
    };

    cout << NumberOfIslands(testcase1) << endl; 
    cout << NumberOfIslands(testcase2) << endl; 
    cout << NumberOfIslands(testcase3) << endl; 
    cout << NumberOfIslands(testcase4) << endl; 

    return 0;
}