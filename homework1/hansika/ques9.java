// Technique: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

import java.util.*;
public class ques9
{

    public static void dedupArray(int[] arr) 
    {
        if (arr.length == 0) return;
        int writeIndex = 1;  // position to place the next unique element
        for (int readIndex = 1; readIndex < arr.length; readIndex++) 
        {
            if (arr[readIndex] != arr[readIndex - 1]) 
            {
                arr[writeIndex] = arr[readIndex];
                writeIndex++;
            }
        }

        // Fill remaining positions with -1 (static array requirement)
        for (int i = writeIndex; i < arr.length; i++) 
        {
            arr[i] = -1;
        }
    }

    public static void main(String[] args) 
    {
        int[] arr1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
        dedupArray(arr1);
        System.out.println(Arrays.toString(arr1));// Expected: [1, 2, 3, 4, -1, -1, -1, -1, -1, -1]
        int[] arr2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
        dedupArray(arr2);
        System.out.println(Arrays.toString(arr2));// Expected: [0, 1, 4, 5, 8, 9, 10, 11, 15, -1, -1, -1, -1, -1]
        int[] arr3 = {1, 3, 4, 8, 10, 12};
        dedupArray(arr3);
        System.out.println(Arrays.toString(arr3)); // Expected: [1, 3, 4, 8, 10, 12]
    }
}

// Time spent: ~10 minutes
