// Technique: Sorting + One-directional running computation
// Time Complexity: O(n log n)
// Space Complexity: O(n)
import java.util.*;
public class ques8 
{
    public static int[][] mergeIntervals(int[][] intervals) 
    {
        if (intervals.length <= 1) return intervals;

        // Sort intervals by starting point
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> result = new ArrayList<>();
        int[] current = intervals[0];

        // Traverse and merge
        for (int i = 1; i < intervals.length; i++) 
        {
            if (intervals[i][0] <= current[1]) 
            {
                // Overlap- merge
                current[1] = Math.max(current[1], intervals[i][1]);
            } else {
                // No overlap-push current to result
                result.add(current);
                current = intervals[i];
            }
        }
        result.add(current); // add last interval

        return result.toArray(new int[result.size()][]);
    }

    public static void main(String[] args) 
    {
        int[][] input1 = {{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
        int[][] output1 = mergeIntervals(input1);
        print(output1); // [[1, 3], [4, 8], [9, 12]]

        int[][] input2 = {{5, 8}, {6, 10}, {2, 4}, {3, 6}};
        int[][] output2 = mergeIntervals(input2);
        print(output2); // [[2, 10]]

        int[][] input3 = {{10, 12}, {5, 6}, {7, 9}, {1, 3}};
        int[][] output3 = mergeIntervals(input3);
        print(output3); // [[1, 3], [5, 6], [7, 9], [10, 12]]
    }
    public static void print(int[][] arr) 
    {
        for (int[] a : arr) 
        {
            System.out.print(Arrays.toString(a) + " ");
        }
        System.out.println();
    }
}
//time 25min