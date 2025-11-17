// Technique: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
public class ques6 
{
    public static int findMissingInteger(int[] arr, int n) 
    {
        int left = 0, right = arr.length - 1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == mid + 1) 
            {
                left = mid + 1;// missing number is on right
            } else
            {
                right = mid - 1; // Missing number is on left (or at mid)
            }
        }
        return left + 1;
    }

    public static void main(String[] args) {
        // Test Cases
        int[] arr1 = {1, 2, 3, 4, 6, 7};
        System.out.println(findMissingInteger(arr1, 7)); // Expected: 5
        int[] arr2 = {1};
        System.out.println(findMissingInteger(arr2, 2)); // Expected: 2
        int[] arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
        System.out.println(findMissingInteger(arr3, 12)); // Expected: 9
    }
}

// Time spent: ~15 minutes

