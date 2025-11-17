package homework2.Saytam_Mishra;

class Stack {
    class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    public int top() { // O(1) time
        if(head == null) {
            throw new IllegalStateException("Stack is empty");
        }
        return head.data;
    }

    public void push(int x) { // O(1) time
        Node newNode = new Node(x);

        newNode.next = head;
        head = newNode;
    }

    public int pop() { // O(1) time
        if(isEmpty()) {
            throw new IllegalStateException("Stack is empty");
        } else {
            int delete = head.data;
            head = head.next;
            
            return delete;
        }
    }

    public boolean isEmpty() { // O(1) time
        return head == null;
    }
}

public class q5_stack {
    public static void main(String[] args) {
        Stack myStack = new Stack();

        myStack.push(10);
        myStack.push(20);
        System.out.println("Top element is: " + myStack.top());

        int val = myStack.pop();
        System.out.println("Popped: " + val);
        System.out.println("New top element is: " + myStack.top());
    }
}

// Time taken - 4m 20s