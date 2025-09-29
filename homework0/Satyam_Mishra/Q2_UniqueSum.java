/*
    Time complexity - O(n) (for traversing the array)

    Space complexity - O(n) (for adding elements in set in worst case)
                       Overall O(n) in worst case
 */

import java.util.HashSet;
import java.util.Set;

public class Q2_UniqueSum {
    private static int sumOfUniqueElements(int[] arr) {
        Set<Integer> unique = new HashSet<>(); // set to store unique elements

        int totalSum = 0;
        for(int ele : arr) {
            if(!unique.contains(ele)) {
                totalSum += ele; // add the unique elements to the totalSum
            }
            unique.add(ele);
        }

        return totalSum;
    }
    
    public static void main(String[] args) {
        // TEST CASES
        int[] arr1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
        int[] arr2 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};

        System.out.println("Unique sum of elements in arr1 are: " + sumOfUniqueElements(arr1));
        System.out.println("Unique sum of elements in arr2 are: " + sumOfUniqueElements(arr2));
    }
}

// Time taken: 3m 31s