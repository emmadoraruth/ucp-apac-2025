package homework2.Saytam_Mishra;

class Deque {
    class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    private Node head;
    private Node tail;

    public int front() { // O(1) time
        if(head == null) {
            throw new IllegalStateException("Deque is empty");
        }
        return head.data;
    }

    public int back() { // O(1) time
        if(head == null) {
            throw new IllegalStateException("Deque is empty");
        }
        return tail.data;
    }

    public void pushBack(int x) { // O(1) time
        Node newNode = new Node(x);

        if(head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void pushFront(int x) { // O(1) time
        Node newNode = new Node(x);

        if(head == null) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
    }

    public int popFront() { // O(1) time
        if(isEmpty()) {
            throw new IllegalStateException("Deque is empty");
        } else {
            int delete = head.data;
            head = head.next;
            if(head != null) head.prev = null;
            else if(head == null) {
                tail = null;
            }
            
            return delete;
        }
    }

    public int popBack() { // O(1) time
        if(isEmpty()) {
            throw new IllegalStateException("Dequeue is empty");
        } else {
            int delete = tail.data;
            tail = tail.prev;
            if(tail != null) tail.next = null;
            else if(tail == null) {
                head = null;
            }
            
            return delete;
        }
    }

    public boolean isEmpty() { // O(1) time
        return head == null;
    }
}

public class q6_deque {
    public static void main(String[] args) {
        Deque myDeque = new Deque();

        myDeque.pushFront(10);
        myDeque.pushBack(20);
        myDeque.pushFront(5);
        
        System.out.println("Front element: " + myDeque.front());
        System.out.println("Back element: " + myDeque.back());

        int val1 = myDeque.popBack();
        int val2 = myDeque.popFront();
        
        System.out.println("Popped back: " + val1);
        System.out.println("Popped front: " + val2);
        System.out.println("New front element: " + myDeque.front());
    }
}

// Time taken - 17m 25s