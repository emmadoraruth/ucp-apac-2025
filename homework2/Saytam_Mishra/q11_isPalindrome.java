package homework2.Saytam_Mishra;
// Technique - Doubly linked list forward-backward two-pointer
// Time Complexity - O(n)
// Space Complexity - O(1)

public class q11_isPalindrome {
    static class Node {
        Node next;
        Node prev;
        int val;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.prev = null;
        }
    }

    public static boolean checkPalindrome(Node head, Node tail) {
        if(head == null) return true;

        while(head != tail && head.prev != tail) {
            if(head.val != tail.val) {
                return false;
            }
            head = head.next;
            tail = tail.prev;
        }

        return true;
    }

    public static void printLinkedList(Node head) {
        if(head == null) {
            System.out.println("");
            return;
        }

        System.out.print(head.val);
        head = head.next;
        while(head != null) {
            System.out.print(" -> " + head.val);
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Test Case 1
        Node head1 = new Node(9);
        Node tail1 = head1;

        tail1.next = new Node(2);
        tail1.next.prev = tail1;
        tail1 = tail1.next;
        tail1.next = new Node(4);
        tail1.next.prev = tail1;
        tail1 = tail1.next;
        tail1.next = new Node(2);
        tail1.next.prev = tail1;
        tail1 = tail1.next;
        tail1.next = new Node(9);
        tail1.next.prev = tail1;
        tail1 = tail1.next;

        printLinkedList(head1);
        System.out.println("Linked List 1 is Palindrome: " + checkPalindrome(head1, tail1));

        // Test Case 2
        Node head2 = new Node(9);
        Node tail2 = head2;

        tail2.next = new Node(12);
        tail2.next.prev = tail2;
        tail2 = tail2.next;
        tail2.next = new Node(4);
        tail2.next.prev = tail2;
        tail2 = tail2.next;
        tail2.next = new Node(2);
        tail2.next.prev = tail2;
        tail2 = tail2.next;
        tail2.next = new Node(9);
        tail2.next.prev = tail2;
        tail2 = tail2.next;

        printLinkedList(head2);
        System.out.println("Linked List 2 is Palindrome: " + checkPalindrome(head2, tail2));
    }
}

// Time spent - 16m 36s