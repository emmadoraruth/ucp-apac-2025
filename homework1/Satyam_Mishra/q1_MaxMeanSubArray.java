// TC: O(n)
// SC: O(1)
// Category - TWO POINTERS
// 18m 14s

package Satyam_Mishra;

public class q1_MaxMeanSubArray {
    private static double maxMean(int[] arr, int k) {
        int n = arr.length;
        double ans = Long.MIN_VALUE;

        int i = 0, j = 0;
        double sum = 0;
        while(j < n) {
            sum += arr[j];

            if(j - i + 1 == k) {
                ans = Math.max(ans, sum / k);
                sum -= arr[i];
                i++;
            }

            j++;
        }

        return ans;
    }
    public static void main(String[] args) {
        // Test Case1
        int[] arr1 = {4, 5, -3, 2, 6, 1};
        int k1 = 2;
        System.out.println("Maximum mean for arr1 is: " + maxMean(arr1, k1));

        // Test Case2
        int[] arr2 = {4, 5, -3, 2, 6, 1};
        int k2 = 3;
        System.out.println("Maximum mean for arr2 is: " + maxMean(arr2, k2));
        
        // Test Case3
        int[] arr3 = {1, 1, 1, 1, -1, -1, 2, -1, -1};
        int k3 = 3;
        System.out.println("Maximum mean for arr3 is: " + maxMean(arr3, k3));

        // Test Case4
        int[] arr4 = {1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
        int k4 = 5;
        System.out.println("Maximum mean for arr4 is: " + maxMean(arr4, k4));
    }
}
