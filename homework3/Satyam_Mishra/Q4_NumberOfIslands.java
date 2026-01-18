// DS/Algo used - DFS

// Time Complexity = O(m * n)
// Space Complexity = O(m * n) in the worst case

package homework3.Satyam_Mishra;

public class Q4_NumberOfIslands {
    private static void dfs(int i, int j, int m, int n, int[][] matrix, int[][] dirs) {
        matrix[i][j] = 0;

        for(int[] dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] == 1) {
                dfs(ni, nj, m, n, matrix, dirs);
            }
        }
    }

    public static void main(String[] args) {
        int[][] dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int[][] matrix1 = {{1, 0, 1, 1, 1}, {1, 1, 0, 1, 1}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}};
        int m1 = matrix1.length;
        int n1 = matrix1[0].length;
        int numOfIslands1 = 0;

        for(int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                if(matrix1[i][j] == 1) {
                    numOfIslands1++;
                    dfs(i, j, m1, n1, matrix1, dirs);
                }
            }
        }
        System.out.println("Number of islands in matrix1 are: " + numOfIslands1);

        int[][] matrix2 = {{1, 0, 0}, {0, 0, 0}};
        int m2 = matrix2.length;
        int n2 = matrix2[0].length;
        int numOfIslands2 = 0;

        for(int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                if(matrix2[i][j] == 1) {
                    numOfIslands2++;
                    dfs(i, j, m2, n2, matrix2, dirs);
                }
            }
        }
        System.out.println("Number of islands in matrix2 are: " + numOfIslands2);
    }
}

// time taken 9m 50s