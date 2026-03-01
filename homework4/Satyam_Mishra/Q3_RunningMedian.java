// Technique - Priority Queue
// TIME COMPLEXITY - O(NlogN)
// SPACE COMPLEXITY - O(N)
// where N is the length of array

package homework4.Satyam_Mishra;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Q3_RunningMedian {
    private PriorityQueue<Integer> maxHeap;
    private PriorityQueue<Integer> minHeap;
    private List<Double> medianList;

    public Q3_RunningMedian() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        minHeap = new PriorityQueue<>();
        medianList = new ArrayList<>();
    }

    public void findMedian(int number) {
        if(maxHeap.isEmpty() || maxHeap.peek() >= number) {
            maxHeap.add(number);
        } else {
            minHeap.add(number);
        }

        if(maxHeap.size() - minHeap.size() > 1) {
            minHeap.add(maxHeap.poll());
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.add(minHeap.poll());
        }

        if(maxHeap.size() == minHeap.size()) {
            medianList.add((minHeap.peek() + maxHeap.peek()) / 2.0);
        } else {
            medianList.add(1D * maxHeap.peek());
        }
    }

    public static void main(String[] args) {
        Q3_RunningMedian tracker = new Q3_RunningMedian();

        int[] arr = {1, 11, 4, 15, 12};

        for(int ele : arr) {
            tracker.findMedian(ele);
        }

        System.out.println(tracker.medianList);
    }
}

// time taken - 20m