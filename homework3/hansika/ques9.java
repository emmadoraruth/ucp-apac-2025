/*
Data structure: Priority Queue (Min-Heap)
algorithm: K-way merge using a heap
Time spent on this problem: 23 minutes
Time complexity: O(N log k)(N = total number of elements across all arrays)
Space complexity: O(k)
*/

import java.util.*;
public class ques9
{

    static class Node
    {
        int value;
        int arrayIndex;
        int elementIndex;

        Node(int value, int arrayIndex, int elementIndex)
        {
            this.value = value;
            this.arrayIndex = arrayIndex;
            this.elementIndex = elementIndex;
        }
    }
    public static List<Integer> mergeKSortedArrays(List<List<Integer>> arrays)
    {

        List<Integer> result = new ArrayList<>();
        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> a.value - b.value);
        // add first element of each array to heap
        for (int i = 0; i < arrays.size(); i++)
        {
            if (!arrays.get(i).isEmpty())
            {
                minHeap.add(new Node(arrays.get(i).get(0),i,0));
            }
        }
        while (!minHeap.isEmpty())
        {
            Node curr = minHeap.poll();
            result.add(curr.value);
            int nextIndex = curr.elementIndex + 1;
            if (nextIndex < arrays.get(curr.arrayIndex).size())
            {
                minHeap.add(new Node(arrays.get(curr.arrayIndex).get(nextIndex),curr.arrayIndex,nextIndex));
            }
        }
        return result;
    }
    public static void main(String[] args)
    {
        List<List<Integer>> input1 = Arrays.asList(Arrays.asList(1, 2, 3, 4, 5),Arrays.asList(1, 3, 5, 7, 9));
        List<List<Integer>> input2 = Arrays.asList(Arrays.asList(1, 4, 7, 9),Arrays.asList(2, 6, 7, 10, 11, 13, 15),Arrays.asList(3, 8, 12, 13, 16));
        System.out.println("Output: " + mergeKSortedArrays(input1));
        System.out.println("Output: " + mergeKSortedArrays(input2));
    }
}