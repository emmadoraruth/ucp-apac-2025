package homework2.Saytam_Mishra;
// Technique - Linked list fast-slow two-pointer
// Time Complexity - O(n)
// Space Complexity - O(1)

public class q12_disconnectCycle {
    static class Node {
        Node next;
        int val;

        public Node(int val) {
            this.next = null;
            this.val = val;
        }
    }

    private static Node startOfLoop(Node head, Node slow) {
        while(head != slow) {
            head = head.next;
            slow = slow.next;
        }

        return head;
    }
    public static void disconnectCycle(Node head) {
        // Detect cycle
        Node slow = head;
        Node fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) { // cycle is present
                break;
            }
        }
        if(fast == null || fast.next == null) { // cycle is not present
            return;
        }

        Node start = startOfLoop(head, slow);
        
        Node temp = start;
        while (temp.next != start) {
            temp = temp.next;
        }
        temp.next = null;
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
        Node head1 = new Node(10);
        Node temp1 = head1;
        temp1.next = new Node(18);
        temp1 = temp1.next;
        temp1.next = new Node(12);
        temp1 = temp1.next;
        Node cycleNode1 = temp1;
        temp1.next = new Node(9);
        temp1 = temp1.next;
        temp1.next = new Node(11);
        temp1 = temp1.next;
        temp1.next = new Node(4);
        temp1 = temp1.next;
        temp1.next = cycleNode1;

        disconnectCycle(head1);
        printLinkedList(head1);

        System.out.println("--------------------");

        // Test Case 2
        Node head2 = new Node(10);
        Node temp2 = head2;
        temp2.next = new Node(18);
        temp2 = temp2.next;
        temp2.next = new Node(12);
        temp2 = temp2.next;
        temp2.next = new Node(9);
        temp2 = temp2.next;
        temp2.next = new Node(11);
        temp2 = temp2.next;
        temp2.next = new Node(4);
        temp2 = temp2.next;
        Node cycleNode2 = temp2;
        temp2.next = cycleNode2;

        disconnectCycle(head2);
        printLinkedList(head2);
    }
}

// Time spent - 36m 53s