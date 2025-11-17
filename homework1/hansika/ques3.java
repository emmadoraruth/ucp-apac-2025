// Technique: Hashing (One-directional running computation/total)
// Time Complexity: O(n)
// Space Complexity: O(n)

import java.util.HashMap;

public class ques3 
{

    public static int countZeroSumSubarrays(int[] arr) 
    {
        HashMap<Integer, Integer> map = new HashMap<>();
        int prefixSum = 0;
        int count = 0;

        for (int num : arr)
         {
            prefixSum += num;
            //prefix sum itself is zero-one subarray from start
            if (prefixSum == 0) 
            {
                count++;
            }
            //prefix sum seen before-subarray between has sum = 0
            if (map.containsKey(prefixSum)) 
            {
                count += map.get(prefixSum);
            }
            map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        // Test Cases
        int[] arr1 = {4, 5, 2, -1, -3, -3, 4, 6, -7};
        System.out.println(countZeroSumSubarrays(arr1)); // Expected: 2
        int[] arr2 = {1, 8, 7, 3, 11, 9};
        System.out.println(countZeroSumSubarrays(arr2)); // Expected: 0
        int[] arr3 = {8, -5, 0, -2, 3, -4};
        System.out.println(countZeroSumSubarrays(arr3)); // Expected: 2
    }
}

// Time spent: 14 minutes
