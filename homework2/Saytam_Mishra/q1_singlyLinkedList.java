package homework2.Saytam_Mishra;

public class q1_singlyLinkedList {
    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public static Node insertAtFront(Node head, int val) { // O(1) time
        Node newNode = new Node(val);
        newNode.next = head;

        return newNode;
    }

    public static Node insertAtBack(Node head, int val) { // O(n) time
        Node newNode = new Node(val);

        if(head == null) return newNode; // list is empty

        Node temp = head;
        while(temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        
        return head;
    }

    public static Node insertAfter(Node head, int val, Node loc) { // O(1) time
        Node newNode = new Node(val);

        if (loc == null) {
            return head;
        }

        newNode.next = loc.next;
        loc.next = newNode;

        return head;
    }

    public static Node insertBefore(Node head, int val, Node loc) { // O(n) time
        if (loc == null) {
            return head;
        }

        if(loc == head) { // if node to be inserted before head
            return insertAtFront(head, val);
        }

        Node newNode = new Node(val);
        Node temp = head;
        while(temp.next != null && temp.next != loc) {
            temp = temp.next;
        }

        if(temp.next == loc) { // only insert if loc is present in the list
            temp.next = newNode;
            newNode.next = loc;
        }

        return head;
    }

    public static Node deleteFront(Node head) { // O(1) time
        if(head == null) return head;

        return head.next;
    }

    public static Node deleteBack(Node head) { // O(n) time
        if(head == null || head.next == null) return null;
        
        Node temp = head;
        while(temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;

        return head;
    }

    public static Node deleteNode(Node head, Node loc) { // O(n) time
        if(head == null) return head;

        if(head == loc) { // if loc and head are same
            return head.next;
        }
        
        Node temp = head;

        while(temp.next != null && temp.next != loc) {
            temp = temp.next;
        }
        
        if(temp.next == loc) {
            temp.next = loc.next;
        }

        return head;
    }

    public static int length(Node head) { // O(n) time
        Node temp = head;

        int len = 0;
        while(temp != null) {
            len++;
            temp = temp.next;
        }

        return len;
    }

    public static Node reverseIterative(Node head) { // O(n) time
        Node prev = null;
        Node current = head;
        Node next = null;

        while(current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    public static Node reverseRecursiveHelper(Node curr, Node prev) {
        if(curr == null) return prev;

        Node nextTemp = curr.next;
        curr.next = prev;

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
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        Node head = null;

        System.out.println("--- Test Case 1: Insertions ---");
        head = insertAtFront(head, 10);
        head = insertAtBack(head, 20);
        printList(head); 

        head = deleteFront(head);
        printList(head);
    }
}

// Time taken - 38m 6s