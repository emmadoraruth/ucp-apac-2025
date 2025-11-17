/*
Technique Used: Linked list fast-slow two-pointer
Time Complexity: O(n)
Space Complexity: O(1)
Time spent: 45 minutes
*/

class TreeNode 
{
    int val;
    LLNode next;
    TreeNode(int v) { this.val = v; }
}

public class ques12 
{

    public static LLNode disconnectCycle(LLNode head) 
    {
        if (head == null || head.next == null) return head;
        LLNode slow = head;
        LLNode fast = head;
        // Detect cycle
        boolean cycle = false;
        while (fast != null && fast.next != null) 
        {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) // meeting point
            {  
                cycle = true;
                break;
            }
        }
        if (!cycle) return head;  // no cycle to break
        //Find the start of the cycle
        slow = head;
        LLNode prev = null;
        while (slow != fast) 
        {
            prev = fast;
            slow = slow.next;
            fast = fast.next;
        }
        // Break the cycle
        prev.next = null;
        return head;
    }


    // Helper print 
    public static void printList(LLNode head) {
        LLNode t = head;
        int count = 0;
        while (t != null && count < 50) //stops after 50 nodes to avoid infinite loop
        {
            System.out.print(t.val);
            if (t.next != null) System.out.print(" -> ");
            t = t.next;
            count++;
        }
        System.out.println();
    }


    public static void main(String[] args) 
    {

        // example1
        LLNode a = new LLNode(10);
        a.next = new LLNode(18);
        a.next.next = new LLNode(12);
        a.next.next.next = new LLNode(9);
        a.next.next.next.next = new LLNode(11);
        a.next.next.next.next.next = new LLNode(4);
        a.next.next.next.next.next.next = a.next.next;

        System.out.println("Input 1 (with cycle): printing limited:");
        printList(a);
        disconnectCycle(a);
        System.out.println("Output 1 (cycle removed):");
        printList(a);
        // eg2
        LLNode b = new LLNode(10);
        b.next = new LLNode(18);
        b.next.next = new LLNode(12);
        b.next.next.next = new LLNode(9);
        b.next.next.next.next = new LLNode(11);
        b.next.next.next.next.next = new LLNode(4);
        b.next.next.next.next.next.next = b.next.next.next.next.next;
        System.out.println("\nInput 2 (with cycle): printing limited:");
        printList(b);
        disconnectCycle(b);
        System.out.println("Output 2 (cycle removed):");
        printList(b);
    }
}
