// DS/Algo used - PriorityQueue

// Time Complexity = O(NlogK), where N is total number of elements and K is size of the given list
// Space Complexity = O(K), excluding output list space

package homework3.Satyam_Mishra;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class Q9_MergeKSortedArrays {
    private static List<Integer> mergeKSortedArrays(List<List<Integer>> lists) {
        List<Integer> sortedList = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        for(int i = 0; i < lists.size(); i++) {
            if(!lists.get(i).isEmpty()) {
                pq.add(new int[] {lists.get(i).get(0), i, 0});
            }
        }

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int val = top[0];
            int listIdx = top[1];
            int elementIdx = top[2];

            sortedList.add(val);

            if(elementIdx + 1 < lists.get(listIdx).size()) {
                pq.add(new int[] {lists.get(listIdx).get(elementIdx + 1), listIdx, elementIdx + 1});
            }
        }

        return sortedList;
    }
    public static void main(String[] args) {
        List<List<Integer>> list1 = new ArrayList<>();
        list1.add(new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5)));
        list1.add(new ArrayList<>(Arrays.asList(1, 3, 5, 7, 9)));
        System.out.println("Final list after sorting list1 is: " + mergeKSortedArrays(list1));

        List<List<Integer>> list2 = new ArrayList<>();
        list2.add(new ArrayList<>(Arrays.asList(1, 4, 7, 9)));
        list2.add(new ArrayList<>(Arrays.asList(2, 6, 7, 10, 11, 13, 15)));
        list2.add(new ArrayList<>(Arrays.asList(3, 8, 12, 13, 16)));
        System.out.println("Final list after sorting list2 is: " + mergeKSortedArrays(list2));
    }
}

// time taken 33m 40s