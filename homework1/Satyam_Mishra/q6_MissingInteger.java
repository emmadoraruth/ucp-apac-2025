// TC: O(n)
// SC: O(1)
// Category - SEARCHING
// 8m 15s
package Satyam_Mishra;

public class q6_MissingInteger {
    private static int missingNumber(int[] arr) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == mid + 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + 1;
    }
    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {1, 2, 3, 4, 6, 7};
        int n1 = 7;
        System.out.println("Missing integer in arr1 is: " + missingNumber(arr1));

        // Test Case 2
        int[] arr2 = {1};
        int n2 = 2;
        System.out.println("Missing integer in arr2 is: " + missingNumber(arr2));

        // Test Case 3
        int[] arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
        int n3 = 12;
        System.out.println("Missing integer in arr3 is: " + missingNumber(arr3));
    }
}

