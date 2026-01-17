/*
Technique Used: Linked list fixed-distance two-pointer
Time Complexity: O(n)
Space Complexity: O(1)

Time spent: 28 min
*/

class LLNode 
{
    int val;
    LLNode next;
    LLNode(int v) 
    { 
        this.val = v; 
    }
}

public class ques10 
{

    // Move the nth from last node to the front
    public static LLNode moveNthLastToFront(LLNode head, int k) 
    {
        if (head == null || k <= 0) return head;
        LLNode fast = head;
        LLNode slow = head;
        LLNode prev = null;
        // Move fast k steps ahead
        for (int i = 0; i < k; i++) 
        {
            if (fast == null) return head; 
            fast = fast.next;
        }
        // Move both until fast reaches end
        while (fast != null) 
        {
            fast = fast.next;
            prev = slow;
            slow = slow.next;
        }
        // If kth last is already the head,nothing to move
        if (slow == head) return head;
        //Remove slow from its current position
        prev.next = slow.next;
        //Move slow to the front
        slow.next = head;
        return slow;
    }
    // Print helper
    public static void printList(LLNode head)
     {
        LLNode t = head;
        while (t != null) 
        {
            System.out.print(t.val);
            if (t.next != null) System.out.print(" -> ");
            t = t.next;
        }
        System.out.println();
    }


    public static void main(String[] args) 
    {

        // eg 1: k = 2 
        LLNode a = new LLNode(15);
        a.next = new LLNode(2);
        a.next.next = new LLNode(8);
        a.next.next.next = new LLNode(7);
        a.next.next.next.next = new LLNode(20);
        a.next.next.next.next.next = new LLNode(9);
        a.next.next.next.next.next.next = new LLNode(11);
        a.next.next.next.next.next.next.next = new LLNode(6);
        a.next.next.next.next.next.next.next.next = new LLNode(19);

        System.out.println("Input (k=2):");
        printList(a);
        LLNode result1 = moveNthLastToFront(a, 2);
        System.out.println("Output:");
        printList(result1);

        // eg 2: k = 7 
        LLNode b = new LLNode(15);
        b.next = new LLNode(2);
        b.next.next = new LLNode(8);
        b.next.next.next = new LLNode(7);
        b.next.next.next.next = new LLNode(20);
        b.next.next.next.next.next = new LLNode(9);
        b.next.next.next.next.next.next = new LLNode(11);
        b.next.next.next.next.next.next.next = new LLNode(6);
        b.next.next.next.next.next.next.next.next = new LLNode(19);

        System.out.println("\nInput (k=7):");
        printList(b);
        LLNode result2 = moveNthLastToFront(b, 7);
        System.out.println("Output:");
        printList(result2);
    }
}
