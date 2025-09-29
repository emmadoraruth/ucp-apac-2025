// TC: O(n)
// SC: O(1)
// Category - TWO POINTERS
// 15m 45s

package Satyam_Mishra;

import java.util.Arrays;

public class q9_DedupArray {
    private static void modifyArray(int[] arr) {
        int n = arr.length;
        int i = 0, j = 0;
        int k = 0;
        while(j < n) {
            if(arr[i] != arr[j]) {
                arr[k++] = arr[i];
                i = j;
            }
            j++;
        }
        arr[k++] = arr[i];
        while(k < n) {
            arr[k++] = -1;
        }
    }

    public static void main(String[] args) {
        // Test Case 1
        int[] arr1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
        modifyArray(arr1);
        System.out.println("Modified arr1 is: " + Arrays.toString(arr1));

        // Test Case 2
        int[] arr2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
        modifyArray(arr2);
        System.out.println("Modified arr2 is: " + Arrays.toString(arr2));

        // Test Case 3
        int[] arr3 = {1, 3, 4, 8, 10, 12};
        modifyArray(arr3);
        System.out.println("Modified arr3 is: " + Arrays.toString(arr3));
    }
}
