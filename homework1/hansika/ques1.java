// Technique: Fixed-size sliding window
// Time Complexity: O(n)
// Space Complexity: O(1)

public class ques1 
{

    public static double maxMeanSubArray(int[] arr, int k) 
    {
        if (arr.length < k) 
        {
            return 0; // or -1 to indicate invalid input
        }

        //Sum of first window of size k
        double windowSum = 0;
        for (int i = 0; i < k; i++) 
        {
            windowSum += arr[i];
        }
        double maxSum = windowSum;
        // Slide the window
        for (int i = k; i < arr.length; i++) 
        {
            windowSum += arr[i] - arr[i - k]; // remove outgoing, add new
            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }
        return maxSum / k;
    }

    public static void main(String[] args) {
        // Test Cases
        int[] arr1 = {4, 5, -3, 2, 6, 1};
        System.out.println(maxMeanSubArray(arr1, 2)); // Expected: 4.5
        System.out.println(maxMeanSubArray(arr1, 3)); // Expected: 3
        int[] arr2 = {1, 1, 1, 1, -1, -1, 2, -1, -1};
        System.out.println(maxMeanSubArray(arr2, 3)); // Expected: 1
        int[] arr3 = {1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
        System.out.println(maxMeanSubArray(arr3, 5)); // Expected: 1
    }
}

// Time spent: ~12 minutes
