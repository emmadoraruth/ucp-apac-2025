// TC: O(nlogn)
// SC: O(n)
// Category - SORTING
// 34m

// assuming order doesn't matter for the answer

package Satyam_Mishra;

import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

public class q8_MergeIntervals {
    private static int[][] merge(int[][] arr) {
        int n = arr.length;
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);

        List<int[]> mergedList = new ArrayList<>();
        int i = 0, j = 1;
        int end = arr[0][1];
        while(j < n) {
            if(end >= arr[j][0]) {
                end = Math.max(arr[j][1], end);
            } else {
                mergedList.add(new int[]{arr[i][0], end});
                i = j;
                end = arr[i][1];
            }
            j++;
        }
        mergedList.add(new int[]{arr[i][0], end});

        int[][] ans = new int[mergedList.size()][2];
        for(i = 0; i < mergedList.size(); i++) {
            ans[i][0] = mergedList.get(i)[0];
            ans[i][1] = mergedList.get(i)[1];
        }

        return ans;
    }
    public static void main(String[] args) {
        // Test Case 1
        int[][] arr1 = {{2, 3}, {4, 8}, {1, 2}, {5, 7}, {9, 12}};
        int[][] ans1 = merge(arr1);
        System.out.println("arr1 after overlapping intervals are merged:");
        System.out.println(Arrays.deepToString(ans1));

        // Test Case 2
        int[][] arr2 = {{5, 8}, {6, 10}, {2, 4}, {3, 6}};
        int[][] ans2 = merge(arr2);
        System.out.println("arr2 after overlapping intervals are merged:");
        System.out.println(Arrays.deepToString(ans2));

        // Test Case 3
        int[][] arr3 = {{10, 12}, {5, 6}, {7, 9}, {1, 3}};
        int[][] ans3 = merge(arr3);
        System.out.println("arr3 after overlapping intervals are merged:");
        System.out.println(Arrays.deepToString(ans3));
    }
}
