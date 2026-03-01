// Technique - BOTTOM UP
// TIME COMPLEXITY - O(N^2)
// SPACE COMPLEXITY - O(N)

package homework4.Satyam_Mishra;

import java.util.Arrays;

public class Q4_CatalanNumbers {
    public static void main(String[] args) {
        int n = 5;
        long[] catalanNumbers = new long[n + 1];
        catalanNumbers[0] = 1;
        catalanNumbers[1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
            catalanNumbers[i] += 1L * catalanNumbers[j] * catalanNumbers[i - j - 1];
            }
        }

        System.out.println(Arrays.toString(catalanNumbers));
    }
}

// time taken - 40m