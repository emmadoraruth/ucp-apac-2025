import java.util.ArrayList;
import java.util.List;
class ques3
{
    // node stores (string, priority)
    static class Node
    {
        String value;
        int priority;
        Node(String value, int priority)
        {
            this.value = value;
            this.priority = priority;
        }
    }
    // underlying heap array
    private List<Node> arr;
    public ques3()
    {
        arr = new ArrayList<>();
    }

    // returns highest priority element
    public String top()
    {
        if (arr.isEmpty())
        {
            System.out.println("Priority Queue is empty");
            return null;
        }
        return arr.get(0).value;
    }

    // inserts string with priority
    public void insert(String x, int weight)
    {
        arr.add(new Node(x, weight));
        heapifyUp(arr.size() - 1);
    }

    // removes highest priority element
    public void remove()
    {
        if (arr.isEmpty())
        {
            System.out.println("Priority Queue is empty");
            return;
        }

        int lastIndex = arr.size() - 1;
        swap(0, lastIndex);
        arr.remove(lastIndex);
        heapifyDown(0);
    }
    // MAX heapify up
    private void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr.get(parent).priority >= arr.get(index).priority)
            {
                break;
            }
            swap(parent, index);
            index = parent;
        }
    }
    // MAX heapify down
    private void heapifyDown(int index)
    {
        int size = arr.size();
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < size &&
                arr.get(left).priority > arr.get(largest).priority)
            {
                largest = left;
            }

            if (right < size &&
                arr.get(right).priority > arr.get(largest).priority)
            {
                largest = right;
            }

            if (largest == index)
            {
                break;
            }

            swap(index, largest);
            index = largest;
        }
    }
    private void swap(int i, int j)
    {
        Node temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }
    public static void main(String[] args)
    {
        ques3 pq = new ques3();
        pq.insert("task1", 5);
        pq.insert("task2", 1);
        pq.insert("task3", 10);
        pq.insert("task4", 7);
        System.out.println("Top: " + pq.top()); // task3
        pq.remove();
        System.out.println("Top after removal: " + pq.top()); // task4
    }
}
