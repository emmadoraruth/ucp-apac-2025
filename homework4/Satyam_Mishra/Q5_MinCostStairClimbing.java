// Technique - BOTTOM UP
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(1)

package homework4.Satyam_Mishra;

public class Q5_MinCostStairClimbing {
    public static void main(String[] args) {
        int[] toll = {4, 1, 6, 3, 5, 8};
        int n = toll.length;

        int prev1 = 0;
        int prev2 = 0;

        for(int i = 2; i <= n; i++) {
            int climbingOneStair = toll[i - 1] + prev1;
            int climbingTwoStairs = toll[i - 2] + prev2;
            
            int currCost = Math.min(climbingOneStair, climbingTwoStairs);

            prev2 = prev1;
            prev1 = currCost;
        }

        System.out.println(prev1);
    }
}

// time taken - 22m