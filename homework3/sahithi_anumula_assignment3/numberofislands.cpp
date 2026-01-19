#include <bits/stdc++.h>
using namespace std;

// I used graph and applied dfs algo and it took me almost 40 to 45 minutes to complete
// Time complexity: O(row x col)
// Space complexity: O(row x col)

#include <bits/stdc++.h>
using namespace std;

int numisland(vector<vector<char>>& grid) {
    int row = grid.size();
    if (row == 0) return 0;
    int col = grid[0].size();

    int island = 0;

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            if (grid[i][j] == '1') 
            {
                island++;
                stack<pair<int, int> > st;
                st.push(make_pair(i, j));
                grid[i][j] = '0';
                while (!st.empty()) 
                {
                    pair<int, int> cell = st.top();
                    st.pop();
                    int r = cell.first;
                    int c = cell.second;
                    if (r - 1 >= 0 && grid[r - 1][c] == '1') 
                    {
                        st.push(make_pair(r - 1, c));
                        grid[r - 1][c] = '0';
                    }

                    if (r + 1 < row && grid[r + 1][c] == '1') 
                    {
                        st.push(make_pair(r + 1, c));
                        grid[r + 1][c] = '0';
                    }

                    if (c - 1 >= 0 && grid[r][c - 1] == '1') 
                    {
                        st.push(make_pair(r, c - 1));
                        grid[r][c - 1] = '0';
                    }

                    if (c + 1 < col && grid[r][c + 1] == '1') 
                    {
                        st.push(make_pair(r, c + 1));
                        grid[r][c + 1] = '0';
                    }
                }
            }
        }
    }

    return island;
}

int main() {
    vector<vector<char> > grid1 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    vector<vector<char> > grid2 = {
        {'1','0','0'},
        {'0','0','0'}
    };


    cout << numisland(grid1) << endl;
    cout << numisland(grid2) << endl;

    return 0;
}
