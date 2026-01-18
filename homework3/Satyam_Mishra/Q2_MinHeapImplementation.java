package homework3.Satyam_Mishra;

class MinHeap {
    private int[] arr;
    int size;
    public MinHeap(int capacity) {
        arr = new int[capacity];
        this.size = 0;
    }

    public int top() throws Exception {
        if(size == 0) {
            throw new Exception("Heap is empty!");
        }
        return arr[0];
    }

    public void insert(int x) throws Exception {
        if (size == arr.length) {
            throw new Exception("Heap is full!"); 
        }

        arr[size++] = x;

        upHeapify(size - 1);
    }

    private void upHeapify(int i) {
        if(i == 0) return;

        int parent = (i - 1) / 2;
        if(arr[parent] > arr[i]) {
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

        int minIdx = i;
        if(leftChild < size && arr[leftChild] < arr[minIdx]) minIdx = leftChild;
        if(rightChild < size && arr[rightChild] < arr[minIdx]) minIdx = rightChild;

        if(minIdx == i) return;

        swap(i, minIdx, arr);
        downHeapify(minIdx);
    }

    private void swap(int i, int j, int[] arr) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

public class Q2_MinHeapImplementation {
    public static void main(String[] args) {
        try {
            MinHeap minHeap = new MinHeap(10);
            minHeap.insert(10);
            minHeap.insert(5);
            minHeap.insert(30);
            minHeap.insert(2);

            System.out.println("Top element: " + minHeap.top());

            minHeap.remove();
            System.out.println("Top after remove: " + minHeap.top());
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
