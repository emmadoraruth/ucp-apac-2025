#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&grid,int r,int c){
    int rows=grid.size();
    int cols=grid[0].size();
    if(r<0||r>=rows||c<0||c>=cols||grid[r][c]==0) return;
    grid[r][c]=0;
    dfs(grid,r+1,c);
    dfs(grid,r-1,c);
    dfs(grid,r,c+1);
    dfs(grid,r,c-1);
}

int numIslands(vector<vector<int>>&grid){
    int rows=grid.size();
    if(rows==0) return 0;
    int cols=grid[0].size();
    int cnt=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j]==1){
                cnt++;
                dfs(grid,i,j);
            }
        }
    }
    return cnt;
}

int main(){
    ifstream in("Q4_input.txt");
    ofstream out("Q4_output.txt");
    
    int r,c;
    in>>r>>c;
    vector<vector<int>>grid(r,vector<int>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            in>>grid[i][j];
        }
    }
    
    int islands=numIslands(grid);
    out<<"Number of islands: "<<islands<<endl;
    
    in.close();
    out.close();
    return 0;
}
