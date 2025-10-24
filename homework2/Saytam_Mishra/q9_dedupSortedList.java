package homework2.Saytam_Mishra;
// Technique - Linked list reset/catch-up two-pointer
// Time Complexity - O(n)
// Space Complexity - O(1)

public class q9_dedupSortedList {
    static class Node {
        Node next;
        int val;

        public Node(int val) {
            this.next = null;
            this.val = val;
        }
    }

    public static Node removeDuplicates(Node root) {
        if(root == null) return null;

        Node left = root;
        Node right = root;

        while(right != null) {
            if(left.val != right.val) {
                left.next = right;
                left = right;
            }
            right = right.next;
        }
        left.next = null;

        return root;
    }

    public static void printLinkedList(Node root) {
        if (root == null) {
            System.out.print("");
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
        Node root1 = new Node(1);
        Node temp = root1;
        temp.next = new Node(2);
        temp = temp.next;
        temp.next = new Node(2);
        temp = temp.next;
        temp.next = new Node(4);
        temp = temp.next;
        temp.next = new Node(5);
        temp = temp.next;
        temp.next = new Node(5);
        temp = temp.next;
        temp.next = new Node(5);
        temp = temp.next;
        temp.next = new Node(10);
        temp = temp.next;
        temp.next = new Node(10);

        printLinkedList(root1);
        removeDuplicates(root1);
        printLinkedList(root1);

        System.out.println("----------------------");

        // Test Case 2
        Node root2 = new Node(8);
        temp = root2;
        temp.next = new Node(8);
        temp = temp.next;
        temp.next = new Node(8);
        temp = temp.next;
        temp.next = new Node(8);

        printLinkedList(root2);
        removeDuplicates(root2);
        printLinkedList(root2);
    }
}

// Time spent - 18m 3s