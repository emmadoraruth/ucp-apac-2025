/*
    Time complexity - O(n) (for traversing the array)
                      Overall O(n)

    Space complexity - O(n) (for adding elements in map) 
                       Overall O(n) in worst case
 */

import java.util.Map;
import java.util.HashMap;

public class Q1_ZeroSum {
    // FOllOW-UP
    private static int numberOfPairsFollowUp(int[] arr) {
        Map<Integer, Integer> frequency = new HashMap<>(); // to store frequency
        
        int countPairs = 0;
        for(int ele : arr) {
            countPairs += frequency.getOrDefault(-ele, 0); // increase count by number of "-ele" frequency present in map (each index can be used multiple times)
            frequency.put(ele, frequency.getOrDefault(ele, 0) + 1);
        }

        return countPairs;
    }

    private static int numberOfPairs(int[] arr) {
        Map<Integer, Integer> frequency = new HashMap<>(); // to store frequency

        int countPairs = 0;
        for(int ele : arr) {
            if(frequency.containsKey(-ele)) {
                countPairs++; // increase count by 1 after finding one valid pair
                frequency.put(-ele, frequency.getOrDefault(ele, 0) - 1); // remove one occurence after finding one valid pair(as we can usre element at each index onlky once)
                if(frequency.get(-ele) == 0) frequency.remove(-ele);
            } else {
                frequency.put(ele, frequency.getOrDefault(ele, 0) + 1); // increase the frequency of element by 1 if pair not found
            }
        }

        return countPairs;
    }
    
    public static void main(String[] args) {
        // TEST CASES 
        int[] arr1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
        int[] arr2 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
        int[] arr3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
        int[] arr4 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};

        System.out.println("Number of pair of integer in arr1 are: " + numberOfPairs(arr1));
        System.out.println("Number of pair of integer in arr2 are: " + numberOfPairs(arr2));
        System.out.println("Number of pair of integer in arr3 are: " + numberOfPairs(arr3));
        System.out.println("Number of pair of integer in arr4 are: " + numberOfPairs(arr4));

        System.out.println("-------------------------------------------------------");

        // TEST CASES FOR FOLLOW UP
        int[] arr5 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
        int[] arr6 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
        int[] arr7 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
        int[] arr8 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};

        System.out.println("Number of pair of integer in arr5 are: " + numberOfPairsFollowUp(arr5));
        System.out.println("Number of pair of integer in arr6 are: " + numberOfPairsFollowUp(arr6));
        System.out.println("Number of pair of integer in arr7 are: " + numberOfPairsFollowUp(arr7));
        System.out.println("Number of pair of integer in arr8 are: " + numberOfPairsFollowUp(arr8));
    }
}

// Time taken: 13m 50s