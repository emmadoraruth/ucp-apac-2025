#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,int row,int col){
    int rowCount=grid.size();
    int colCount=grid[0].size();
    if(row<0 || row>=rowCount || col<0 || col>=colCount) return;
    if(grid[row][col]!='1') return;

    grid[row][col]='0';

    vector<int>rNBR={-1,0,0,1};
    vector<int>cNBR={0,-1,1,0};

    for(int i=0;i<4;i++){
        dfs(grid,row+rNBR[i],col+cNBR[i]);
    }
}

int numIslands(vector<vector<char>>& grid){
    int rowCount=grid.size();
    int colCount=grid[0].size();
    int islandCount=0;

    for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
            if(grid[i][j]=='1'){
                islandCount++;
                dfs(grid,i,j);
            }
        }
    }
    return islandCount;
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
