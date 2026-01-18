/*
Technique Used: Linked list fixed-distance two-pointer
Time Complexity: O(n)    // single pass
Space Complexity: O(1)   // no extra data structures

Time spent: 15min
*/

class LLNode 
{
    int val;
    LLNode next;
    LLNode(int val) 
    { 
        this.val = val; 
    }
}

public class ques9 
{
    // Remove duplicates from sorted linked list
    public static LLNode dedup(LLNode head) 
    {
        if (head == null) return null;
        LLNode curr = head;
        while (curr != null && curr.next != null) 
        {
            if (curr.val == curr.next.val) 
            {
                curr.next = curr.next.next;  // skip duplicate
            } 
            else 
            {
                curr = curr.next;            
            }
        }
        return head;
    }
    // Helper to print
    public static void printList(LLNode head) 
    {
        LLNode temp = head;
        while (temp != null) 
        {
            System.out.print(temp.val);
            if (temp.next != null) System.out.print(" -> ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        // eg1
        LLNode a = new LLNode(1);
        a.next = new LLNode(2);
        a.next.next = new LLNode(2);
        a.next.next.next = new LLNode(4);
        a.next.next.next.next = new LLNode(5);
        a.next.next.next.next.next = new LLNode(5);
        a.next.next.next.next.next.next = new LLNode(5);
        a.next.next.next.next.next.next.next = new LLNode(10);
        a.next.next.next.next.next.next.next.next = new LLNode(10);

        System.out.print("Input 1:  ");
        printList(a);
        LLNode out1 = dedup(a);
        System.out.print("Output 1: ");
        printList(out1);
        // eg2
        LLNode b = new LLNode(8);
        b.next = new LLNode(8);
        b.next.next = new LLNode(8);
        b.next.next.next = new LLNode(8);

        System.out.print("\nInput 2:  ");
        printList(b);
        LLNode out2 = dedup(b);
        System.out.print("Output 2: ");
        printList(out2);
    }
}
