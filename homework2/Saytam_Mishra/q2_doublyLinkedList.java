package homework2.Saytam_Mishra;

public class q2_doublyLinkedList {
    static class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    public static Node insertAtFront(Node head, int val) { // O(1) time
        Node newNode = new Node(val);
        newNode.next = head;
        if (head != null) {
            head.prev = newNode;
        }

        return newNode;
    }

    public static Node insertAtBack(Node head, Node tail, int val) { // O(1) time
        Node newNode = new Node(val);

        if (head == null) {
            head = tail = newNode;
            return newNode;
        }

        tail.next = newNode;
        newNode.prev = tail;

        return head;
    }

    public static Node insertAfter(Node head, int val, Node loc) { // O(1) time
        if (loc == null) {
            return head;
        }

        Node newNode = new Node(val);
        Node nextNode = loc.next;

        newNode.next = nextNode;
        newNode.prev = loc;

        loc.next = newNode;

        if (nextNode != null) {
            nextNode.prev = newNode;
        }

        return head;
    }

    public static Node insertBefore(Node head, int val, Node loc) { // O(1) time
        if (loc == null) {
            return head;
        }

        Node newNode = new Node(val);
        Node prevNode = loc.prev;

        newNode.prev = prevNode;
        newNode.next = loc;

        loc.prev = newNode;

        if (prevNode != null) {
            prevNode.next = newNode;
        } else {
            return newNode;
        }

        return head;
    }

    public static Node deleteFront(Node head) { // O(1) time
        if (head == null)
            return head;

        Node newHead = head.next;

        if (newHead != null) {
            newHead.prev = null;
        }

        return newHead;
    }

    public static Node deleteBack(Node head, Node tail) { // O(1) time
        if (head == null)
            return head;

        if (head == tail)
            return null;

        Node prevNode = tail.prev;
        prevNode.next = null;

        return head;
    }

    public static Node deleteNode(Node head, Node loc) { // O(1) time
        if (head == null || loc == null)
            return head;

        if (head == loc) {
            return deleteFront(head);
        }

        Node prevNode = loc.prev;
        Node nextNode = loc.next;

        prevNode.next = nextNode;

        if (nextNode != null) {
            nextNode.prev = prevNode;
        }

        return head;
    }

    public static int length(Node head) { // O(n) time
        Node temp = head;

        int len = 0;
        while (temp != null) {
            len++;
            temp = temp.next;
        }

        return len;
    }

    public static Node reverseIterative(Node head) { // O(n) time
        Node current = head;
        Node temp = null;
        Node newHead = null;

        while (current != null) {
            temp = current.next;

            current.next = current.prev;
            current.prev = temp;

            newHead = current;

            current = current.prev;
        }

        return newHead;
    }

    public static Node reverseRecursiveHelper(Node curr, Node prev) {
        if (curr == null)
            return prev;

        Node nextTemp = curr.next;
        curr.next = curr.prev;
        curr.prev = nextTemp;

        return reverseRecursiveHelper(nextTemp, curr);
    }

    public static Node reverseRecursive(Node head) { // O(n) time
        return reverseRecursiveHelper(head, null);
    }

    public static void printList(Node head) {
        if (head == null) {
            System.out.println("null");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node head = null;
        Node tail = null;

        System.out.println("--- Test Case 1: Insertions ---");
        head = insertAtFront(head, 10);
        tail = head;

        head = insertAtBack(head, tail, 20);
        tail = tail.next;

        printList(head);

        head = deleteFront(head);
        tail = head;

        printList(head);
    }
}

// Time taken - 18m 53s