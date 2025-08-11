/*
Time Complexity: O(n^2)
Space Complexity: O(n) 
*/
public class Q1 
{ 
    public static int countPairs(int[] arr) 
    {
        boolean[] used = new boolean[arr.length]; 
        int count = 0;

        for (int i = 0; i < arr.length; i++) 
        {
            if (used[i]) continue; // skip if already paired
            for (int j = i + 1; j < arr.length; j++) 
            {
                if (!used[j] && arr[i] + arr[j] == 0) 
                {
                    count++;
                    used[i] = true;
                    used[j] = true;
                    break; 
                }
            }
        }
        return count;
    }

    public static void main(String[] args) 
    {
        // Test cases
        int[] arr1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
        int[] arr2 = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
        int[] arr3 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
        int[] arr4 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 0};
        System.out.println(countPairs(arr1)); // Output: 2
        System.out.println(countPairs(arr2)); // Output: 3
        System.out.println(countPairs(arr3)); // Output: 0
        System.out.println(countPairs(arr4)); // Output: 1
    }

}
// it took me around 23 minutes to get to this logic but i couldnt take make it to O(n) under 40 min
