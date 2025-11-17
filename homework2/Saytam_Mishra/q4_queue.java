package homework2.Saytam_Mishra;

class Queue {
    class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;
    private Node tail;

    public int peek() { // O(1) time
        if(head == null) {
            throw new IllegalStateException("Queue is empty");
        }
        return head.data;
    }

    public void enqueue(int x) { // O(1) time
        Node newNode = new Node(x);

        if(isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
    }

    public int dequeue() { // O(1) time
        if(isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        } else {
            int delete = head.data;
            head = head.next;
            if(head == null) tail = null;
            return delete;
        }
    }

    public boolean isEmpty() { // O(1) time
        return head == null;
    }
}

public class q4_queue {
    public static void main(String[] args) {
        Queue myQueue = new Queue();

        myQueue.enqueue(10);
        myQueue.enqueue(20);
        System.out.println("Front element is: " + myQueue.peek());

        int val = myQueue.dequeue();
        System.out.println("Dequeued: " + val);
        System.out.println("New front element is: " + myQueue.peek());
    }
}

// Time taken - 7m 30s