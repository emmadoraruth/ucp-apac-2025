import java.util.ArrayList;
import java.util.List;
class ques2
{
    private List<Integer> arr;   // underlying array
    public ques2()
    {
        arr = new ArrayList<>();
    }

    // returns min(top) element
    public int top()
    {
     if (arr.isEmpty())
     {
        System.out.println("Heap is empty");
        return -1;
     }
     return arr.get(0);
    }

    // inserts element into the heap
    public void insert(int x)
    {
        arr.add(x);
        heapifyUp(arr.size() - 1);
    }

    // removes mini(top) element
    public void remove()
    {
        if (arr.isEmpty())
        {
            System.out.println("Heap is empty");
            return;
        }

        int lastIndex = arr.size() - 1;
        swap(0, lastIndex);
        arr.remove(lastIndex);
        heapifyDown(0);
    }
    //helper
    private void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr.get(parent) <= arr.get(index))
            {
                break;
            }
            swap(parent, index);
            index = parent;
        }
    }

    private void heapifyDown(int index)
    {
        int size = arr.size();
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && arr.get(left) < arr.get(smallest))
            {
                smallest = left;
            }

            if (right < size && arr.get(right) < arr.get(smallest))
            {
                smallest = right;
            }

            if (smallest == index)
            {
                break;
            }
            swap(index, smallest);
            index = smallest;
        }
    }

    private void swap(int i, int j)
    {
        int temp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, temp);
    }
    public static void main(String[] args)
    {
        ques2 heap = new ques2();

        heap.insert(10);
        heap.insert(5);
        heap.insert(20);
        heap.insert(2);

        System.out.println("Top element: " + heap.top());

        heap.remove();
        System.out.println("Top after removal: " + heap.top());

        heap.remove();
        System.out.println("Top after second removal: " + heap.top());
    }
}
