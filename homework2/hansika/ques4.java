// Queue
public class ques4 
{
    // internal node for queue
    private static class QNode 
    {
        int data;
        QNode next;
        QNode(int d) 
        {
             data = d; next = null; 
        }
    }
    private QNode head;   // points to front
    private QNode tail;   // points to back
    public ques4() 
    { 
         head = tail = null; 
    }
    // peek: returns first item without removing. O(1) time
    public int peek() 
    {
        if (head == null) throw new IllegalStateException("Queue is empty");
        return head.data;
    }
    // enqueue: adds x to back. O(1) time
    public void enqueue(int x) 
    {
        QNode node = new QNode(x);
        if (tail == null) 
        {     
            head = tail = node;
        } 
        else 
        {
            tail.next = node;
            tail = node;
        }
    }

    // dequeue: removes and returns first item. O(1) time
    public int dequeue() 
    {
        if (head == null) throw new IllegalStateException("Queue is empty");
        int val = head.data;
        head = head.next;
        if (head == null) tail = null; // queue became empty
        return val;
    }
    // isEmpty: returns true if empty. O(1) time
    public boolean isEmpty() 
    {
        return head == null;
    }
}
