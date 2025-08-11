/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

import java.util.HashSet;
public class Q2 
{
    public static int UniqueSum(int[] arr) 
    {
        HashSet<Integer> uniquenum = new HashSet<>();
        for (int i = 0; i < arr.length; i++) // add all elements to the hashset
        {
            uniquenum.add(arr[i]);
        } 
        Integer[] uniqueArray = uniquenum.toArray(new Integer[0]); //hashset to array
        int sum = 0;
        for (int i = 0; i < uniqueArray.length; i++) 
        {
            sum += uniqueArray[i];
        }

        return sum;
    }

    public static void main(String[] args) 
    {
        int[] arr1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
        int[] arr2 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
        int[] arr3 = {5, 5, 5, 5};
        int[] arr4 = {};
        System.out.println("Test 1 Output: " + UniqueSum(arr1)); // Expected: 33
        System.out.println("Test 2 Output: " + UniqueSum(arr2)); // Expected: 35
        System.out.println("Test 3 Output: " + UniqueSum(arr3)); // Expected: 5
        System.out.println("Test 4 Output: " + UniqueSum(arr4)); // Expected: 0
    }

    
}
//9min 