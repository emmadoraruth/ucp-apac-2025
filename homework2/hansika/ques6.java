// Deque
public class ques6 
{

    private static class Node 
    {
        int data;
        Node next;
        Node prev;
        Node(int d) 
        {
             data = d; next = prev = null; 
        }
    }
    private Node head;   // front
    private Node tail;   // back
  // returns first item. O(1) time
    public int front() 
    {
        if (head == null) throw new IllegalStateException("Deque is empty");
        return head.data;
    }

    // returns last item. O(1) time
    public int back() 
    {
        if (tail == null) throw new IllegalStateException("Deque is empty");
        return tail.data;
    }

    // adds x to back. O(1)
    public void pushBack(int x) 
    {
        Node n = new Node(x);
        if (tail == null) 
        {        
            head = tail = n;
        } 
        else 
        {
            tail.next = n;
            n.prev = tail;
            tail = n;
        }
    }

    // adds x to front. O(1)
    public void pushFront(int x) 
    {
        Node n = new Node(x);
        if (head == null) 
        {        
            head = tail = n;
        } 
        else 
        {
            n.next = head;
            head.prev = n;
            head = n;
        }
    }

    // removes and returns first item. O(1)
    public int popFront() 
    {
        if (head == null) throw new IllegalStateException("Deque is empty");
        int val = head.data;
        head = head.next;
        if (head == null) tail = null;  // deque empty
        else head.prev = null;
        return val;
    }

    // removes and returns last item. O(1)
    public int popBack() 
    {
        if (tail == null) throw new IllegalStateException("Deque is empty");
        int val = tail.data;
        tail = tail.prev;
        if (tail == null) head = null; // became empty
        else tail.next = null;
        return val;
    }

    // returns true if empty. O(1)
    public boolean isEmpty() 
    {
        return head == null;
    }
}
