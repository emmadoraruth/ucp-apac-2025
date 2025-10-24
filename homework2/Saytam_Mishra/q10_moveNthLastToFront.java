package homework2.Saytam_Mishra;
// Assumption - k is less than or equal to length of Linked List and greater than or equal to 0
// Technique - Linked list fixed-distance two-pointer
// Time Complexity - O(n)
// Space Complexity - O(1)

public class q10_moveNthLastToFront {
    static class Node {
        Node next;
        int val;

        public Node(int val) {
            this.next = null;
            this.val = val;
        }
    }

    public static Node moveKthElement(Node head, int k) {
        if(k == 0 || head == null) {
            return head;
        }

        Node slow = head;
        Node fast = head;

        int i = 1;
        while(i <= k) {
            fast = fast.next;
            i++;
        }
        if(fast == null) { // k == length of linkedList
            return head;
        }

        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        Node nodeToBeMoved = slow.next;
        slow.next = slow.next.next;
        nodeToBeMoved.next = head;
        head = nodeToBeMoved;
        System.out.println(head.val);

        return head;
    }

    public static void printLinkedList(Node root) {
        if(root == null) {
            System.out.println("");
            return;
        }

        System.out.print(root.val);
        root = root.next;

        while(root != null) {
            System.out.print(" -> " + root.val);
            root = root.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Test Case 1
        Node root1 = new Node(15);
        Node temp = root1;
        temp.next = new Node(2);
        temp = temp.next;
        temp.next = new Node(8);
        temp = temp.next;
        temp.next = new Node(7);
        temp = temp.next;
        temp.next = new Node(20);
        temp = temp.next;
        temp.next = new Node(9);
        temp = temp.next;
        temp.next = new Node(11);
        temp = temp.next;
        temp.next = new Node(6);
        temp = temp.next;
        temp.next = new Node(19);
        
        int k1 = 2;

        printLinkedList(root1);
        root1 =  moveKthElement(root1, k1);
        printLinkedList(root1);

        System.out.println("--------------------------");

        // Test Case 2
        Node root2 = new Node(15);
        temp = root2;
        temp.next = new Node(2);
        temp = temp.next;
        temp.next = new Node(8);
        temp = temp.next;
        temp.next = new Node(7);
        temp = temp.next;
        temp.next = new Node(20);
        temp = temp.next;
        temp.next = new Node(9);
        temp = temp.next;
        temp.next = new Node(11);
        temp = temp.next;
        temp.next = new Node(6);
        temp = temp.next;
        temp.next = new Node(19);
        
        int k2 = 7;

        printLinkedList(root2);
        root2 = moveKthElement(root2, k2);
        printLinkedList(root2);
    }
}

// Time spent - 25m 6s