// TC: O(n^2)
// SC: O(1)
// Category - BRUTE FORCE
// 10m 5s

package Satyam_Mishra;

public class q3_ZeroSumSubArrays {
    private static int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int sumOfSubarray = 0;
            for(int j = i; j < n; j++) {
                sumOfSubarray += arr[j];
                
                if(sumOfSubarray == 0) ans++;
            }
        }

        return ans;
    }
    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {4, 5, 2, -1, -3, -3, 4, 6, -7};
        System.out.println("Number of subarrays that sum to zero in arr1 is: " + numOfSubarrays(arr1));

        // Test Case 2
        int[] arr2 = {1, 8, 7, 3, 11, 9};
        System.out.println("Number of subarrays that sum to zero in arr2 is: " + numOfSubarrays(arr2));

        // Test Case 3
        int[] arr3 = {8, -5, 0, -2, 3, -4};
        System.out.println("Number of subarrays that sum to zero in arr3 is: " + numOfSubarrays(arr3));
    }
}
