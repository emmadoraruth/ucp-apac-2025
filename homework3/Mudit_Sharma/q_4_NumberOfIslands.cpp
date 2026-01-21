//Question 4: NumberOfIslands
//Given a binary matrix in which 1s represent land and 0s represent water, return the number of islands
// (contiguous 1s surrounded by 0s or the edge of the matrix).

//Examples: 
// Input: 
// 1 0 1 1 1 
// 1 1 0 1 1 
// 0 1 0 0 0 
// 0 0 0 1 0 
// 0 0 0 0 0 
// Output: 3 (shown in different colors above) 
 
// Input: 
// 1 0 0 
// 0 0 0 
// Output: 1 (shown in different colors above)

#include <bits/stdc++.h>
using namespace std;

//5:50-6:08
     //TIME TAKEN:20 min
    //time complexity :O(n)
    //space complexity :O(nXm)

bool issafe(int row,int col,vector<vector<bool>>& visited,vector<vector<int>>& islands){
    int rows=islands.size();
    int cols=islands[0].size();
    if(row>=rows || row<0 || col>=cols || col<0 || islands[row][col]==0 || visited[row][col]){
        return false;
    }
    return true;
}
void bfsTraverse(int row,int col,vector<vector<bool>>& visited,vector<vector<int>>& islands){
    int rows=islands.size();
    int cols=islands[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    visited[row][col]=true;
    while(!q.empty()){
        pair<int,int> front=q.front();
        int r=front.first;
        int c=front.second;
        q.pop();
        if(issafe(r+1,c,visited,islands)){ //vertically downward
                    q.push({r+1,c});
                    visited[r+1][c]=true;
        }
        if(issafe(r,c+1,visited,islands)){//horizontally rightward
                    q.push({r,c+1});
                    visited[r][c+1]=true;
        }
        if(issafe(r-1,c,visited,islands)){ //vertically up
                    q.push({r-1,c});
                    visited[r-1][c]=true;
        }
        if(issafe(r,c-1,visited,islands)){//horizontally left
                    q.push({r,c-1});
                    visited[r][c-1]=true;
        }

    }
}
int findIslands(vector<vector<int>> islands){//we do by bfs as it visits all the neighbouring land
    int numberOfIslands=0;
    int rows=islands.size();
    if(rows==0){
        return 0;
    }
    int cols=islands[0].size();
    vector<vector<bool>> visited(rows,vector<bool> (cols,false));
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            if(islands[row][col]==1 && !visited[row][col]){
               bfsTraverse(row,col,visited,islands);
               numberOfIslands++;    //increment the number of Islands by one
            }
        }
    }
    return numberOfIslands;
}

int main() {
    //1->means land
    //0->means water
    vector<vector<int>> islands1={{1,0,1,1,1},{1,1,0,1,1},{0,1,0,0,0},{0,0,0,1,0},{0,0,0,0,0}};
    cout<<"Number of Islands in the given set are : "<<findIslands(islands1)<<endl;
    vector<vector<int>> islands2={{1,0,0},{0,0,0}};
    cout<<"Number of Islands in the given set are : "<<findIslands(islands2)<<endl;
    
}
