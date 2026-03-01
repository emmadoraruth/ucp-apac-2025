// Technique - TABULATION
// TIME COMPLEXITY - O(N * K)
// SPACE COMPLEXITY - O(K)

package homework4.Satyam_Mishra;

public class Q8_CoinChange {
    public static long numOfWays(int k, int[] coins) {
        int n = coins.length;
        long[] dp = new long[k + 1];

        // base case
        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = coins[i - 1]; j <= k; j++) {
                long take = dp[j - coins[i - 1]];
        
                long skip = dp[j];

                dp[j] = take + skip;
            }
        }

        return dp[k];
    }

    public static void main(String[] args) {
        int[] coins = {2, 5, 10};

        int k = 20;

        System.out.println(numOfWays(k, coins));
    }
}

// time taken - 38m