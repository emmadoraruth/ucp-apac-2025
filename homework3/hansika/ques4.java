/*
data structure used Graph (2D grid treated as a graph)
algorithm: DFS
Time spent on this problem:20 minutes
Time Complexity: O(m * n)
Space Complexity: O(m * n)  // recursion stack + visited cells

*/

public class ques4
{

    public static int numberOfIslands(int[][] grid)
    {
        if (grid == null || grid.length == 0)
        {
            return 0;
        }

        int rows = grid.length;
        int cols = grid[0].length;
        int count = 0;

        // Traverse the entire grid
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // If land is found, run DFS and count one island
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    // DFS to mark all connected land as visited
    private static void dfs(int[][] grid, int row, int col)
    {
        // check boundaries and water
        if (row < 0 || col < 0 || row >= grid.length || col >= grid[0].length ||grid[row][col] == 0)
        {
            return;
        }
        grid[row][col] = 0; // mark current cell as visited
        dfs(grid, row + 1, col); // explore all 4 directions here down
        dfs(grid, row - 1, col); // up
        dfs(grid, row, col + 1); // right
        dfs(grid, row, col - 1); // left
    }
    public static void main(String[] args)
    {

        int[][] grid1 ={{1, 0, 1, 1, 1},{1, 1, 0, 1, 1}, {0, 1, 0, 0, 0},{0, 0, 0, 1, 0},{0, 0, 0, 0, 0}};
        int[][] grid2 ={{1, 0, 0},{0, 0, 0}};
        System.out.println("Output: " + numberOfIslands(grid1)); // Expected: 3
        System.out.println("Output: " + numberOfIslands(grid2)); // Expected: 1
    }
}

