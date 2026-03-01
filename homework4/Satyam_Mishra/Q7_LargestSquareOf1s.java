// Technique - TABULATION
// TIME COMPLEXITY - O(N^2)
// SPACE COMPLEXITY - O(N)

package homework4.Satyam_Mishra;

public class Q7_LargestSquareOf1s {
    public static int findMaxDimension(int[][] matrix) {
        int n = matrix.length;
        
        int[] maxLen = new int[n + 1];

        int maxDimesion = 0;
        for(int i = 1; i <= n; i++) {
            int diag = 0;
            for(int j = 1; j <= n; j++) {
                int curr = maxLen[j];
                
                if(matrix[i - 1][j - 1] == 0) {
                    maxLen[j] = 0;
                } else {
                    maxLen[j] = Math.min(diag, Math.min(maxLen[j], maxLen[j - 1])) + 1;
                    maxDimesion = Math.max(maxDimesion, maxLen[j]);
                }
                
                diag = curr;
            }
        }

        return maxDimesion;
    }

    public static void main(String[] args) {
        int[][] matrix = {{0, 1, 0, 1, 1},
                            {0, 0, 1, 1, 1},
                            {1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1},
                            {0, 1, 1, 0, 0}};

        System.out.println(findMaxDimension(matrix));
    }
}

// time taken - 40m