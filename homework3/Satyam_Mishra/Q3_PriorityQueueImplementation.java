package homework3.Satyam_Mishra;

class Pair {
    String x;
    int weight;
    public Pair(String x, int weight) {
        this.x = x;
        this.weight = weight;
    }
}

class PriorityQueue {
    private Pair[] arr;
    int size;
    public PriorityQueue(int capacity) {
        arr = new Pair[capacity];
        this.size = 0;
    }

    public String top() throws Exception {
        if(size == 0) {
            throw new Exception("Heap is empty!");
        }
        return arr[0].x;
    }

    public void insert(String x, int weight) throws Exception {
        if (size == arr.length) {
            throw new Exception("Heap is full!"); 
        }

        arr[size++] = new Pair(x, weight);

        upHeapify(size - 1);
    }

    private void upHeapify(int i) {
        if(i == 0) return;

        int parent = (i - 1) / 2;
        if(arr[parent].weight < arr[i].weight) {
            swap(i, parent, arr);
            upHeapify(parent);
        }
    }

    public void remove() throws Exception {
        if(size == 0) {
            throw new Exception("Heap is empty!");
        }
        swap(0, size - 1, arr);
        size--;

        downHeapify(0);
    }

    private void downHeapify(int i) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        int maxIdx = i;
        if(leftChild < size && arr[leftChild].weight > arr[maxIdx].weight) maxIdx = leftChild;
        if(rightChild < size && arr[rightChild].weight > arr[maxIdx].weight) maxIdx = rightChild;

        if(maxIdx == i) return;

        swap(i, maxIdx, arr);
        downHeapify(maxIdx);
    }

    private void swap(int i, int j, Pair[] arr) {
        Pair temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

public class Q3_PriorityQueueImplementation {
    public static void main(String[] args) {
        try {
            PriorityQueue pq = new PriorityQueue(10);

            pq.insert("Low Priority Task", 10);
            pq.insert("High Priority Task", 30);
            pq.insert("Medium Priority Task", 20);

            System.out.println("Highest Priority: " + pq.top());

            pq.remove();
            System.out.println("Next Highest: " + pq.top());

            pq.remove();
            System.out.println("Next Highest: " + pq.top());

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
