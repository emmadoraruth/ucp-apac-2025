/*
Technique Used: Doubly linked list forward-backward two-pointer
Time Complexity: O(n)
Space Complexity: O(1)

Time spent: 30 minutes
*/

class LLNode 
{
    int val;
    LLNode next;
    LLNode prev;
    LLNode(int v) 
    { 
        this.val = v; 
    }
}

public class ques11 
{

    // Check if palindrome
    public static boolean isPalindrome(LLNode head) 
    {
        if (head == null || head.next == null) return true;
        LLNode left = head;
        LLNode right = head;
        // Move right to the tail
        while (right.next != null) 
        {
            right = right.next;
        }
        while (left != right && right.next != left) 
        {
            if (left.val != right.val) return false;
            left = left.next;
            right = right.prev;
        }
        return true;
    }

    // Print helper 
    public static void printList(LLNode head) 
    {
        LLNode t = head;
        while (t != null) 
        {
            System.out.print(t.val);
            if (t.next != null) System.out.print(" <-> ");
            t = t.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {

        //Eg1 (true)
        LLNode a = new LLNode(9);
        a.next = new LLNode(2);     a.next.prev = a;
        a.next.next = new LLNode(4); a.next.next.prev = a.next;
        a.next.next.next = new LLNode(2); a.next.next.next.prev = a.next.next;
        a.next.next.next.next = new LLNode(9); a.next.next.next.next.prev = a.next.next.next;
        System.out.println("Input 1:");
        printList(a);
        System.out.println("Output: " + isPalindrome(a));
        // Eg 2 (False)
        LLNode b = new LLNode(9);
        b.next = new LLNode(12);     b.next.prev = b;
        b.next.next = new LLNode(4); b.next.next.prev = b.next;
        b.next.next.next = new LLNode(2); b.next.next.next.prev = b.next.next;
        b.next.next.next.next = new LLNode(9); b.next.next.next.next.prev = b.next.next.next;
        System.out.println("\nInput 2:");
        printList(b);
        System.out.println("Output: " + isPalindrome(b));
    }
}
