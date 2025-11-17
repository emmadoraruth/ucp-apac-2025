// Stack
public class ques5 
{

    private static class Node 
    {
        int data;
        Node next;
        Node(int d) 
        { 
            data = d; next = null; 
        }
    }
    private Node top;   // top of stack
    // returns the top item in the stack. O(1) time
    public int top() 
    {
        if (top == null) throw new IllegalStateException("Stack is empty");
        return top.data;
    }

    // pushes x onto top. O(1) time
    public void push(int x) 
    {
        Node n = new Node(x);
        n.next = top;     // insert at front
        top = n;
    }

    // removes and returns top element. O(1) time
    public int pop() 
    {
        if (top == null) throw new IllegalStateException("Stack is empty");
        int val = top.data;
        top = top.next;
        return val;
    }

    // returns whether the stack is empty. O(1)
    public boolean isEmpty() 
    {
        return top == null;
    }
}
