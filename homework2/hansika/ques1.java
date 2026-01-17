// singly linked list
class Node 
{
    int data;
    Node next;

    Node(int data) 
    {
        this.data = data;
        this.next = null;
    }
}

public class ques1 {

    // insertAtFront: O(1)
    public static Node insertAtFront(Node head, int val) 
    {
        Node newNode = new Node(val);      // create node
        newNode.next = head;               // point to old head
        return newNode;                    // new head
    }

    // insertAtBack: O(n)
    public static Node insertAtBack(Node head, int val) 
    {
        Node newNode = new Node(val);
        if (head == null) return newNode;
        Node curr = head;
        while (curr.next != null) 
        {        // reach last node
            curr = curr.next;
        }
        curr.next = newNode;               // attach new node
        return head;
    }

    // insertAfter: O(1)
    public static Node insertAfter(Node head, int val, Node loc) 
    {
        if (loc == null) return head;
        Node newNode = new Node(val);
        newNode.next = loc.next;
        loc.next = newNode;
        return head;
    }

    // insertBefore: O(n)
    public static Node insertBefore(Node head, int val, Node loc) 
    {
        if (head == null || loc == null) return head;
        if (head == loc) 
        {
            return insertAtFront(head, val);   // O(1)
        }
        Node curr = head;
        while (curr.next != null && curr.next != loc) 
        {
            curr = curr.next;
        }
        if (curr.next == loc) 
        {
            Node newNode = new Node(val);
            newNode.next = loc;
            curr.next = newNode;
        }
        return head;
    }

    // deleteFront: O(1)
    public static Node deleteFront(Node head) 
    {
        if (head == null) return null;
        return head.next;        // move head to next
    }

    // deleteBack: O(n)
    public static Node deleteBack(Node head) 
    {
        if (head == null) return null;
        if (head.next == null) return null;
        Node curr = head;
        while (curr.next.next != null)
        {                                   // stop at 2nd last
            curr = curr.next;
        }
        curr.next = null;                  // drop last
        return head;
    }

    // deleteNode: O(n)
    public static Node deleteNode(Node head, Node loc) 
    {
        if (head == null || loc == null) return head;
        // if deleting head
        if (head == loc) 
        {
            return head.next;
        }
        Node curr = head;
        while (curr.next != null && curr.next != loc) 
        {
            curr = curr.next;
        }

        if (curr.next == loc) 
        {
            curr.next = loc.next;  
        }
        return head;
    }

    // length: O(n)
    public static int length(Node head) 
    {
        int count = 0;
        Node curr = head;
        while (curr != null) 
        {
            count++;
            curr = curr.next;
        }
        return count;
    }

    // reverseIterative: O(n)
    public static Node reverseIterative(Node head) 
    {
        Node prev = null, curr = head, next = null;
        while (curr != null) 
        {
            next = curr.next;     // save next
            curr.next = prev;     // reverse link
            prev = curr;          // move prev
            curr = next;          // move curr
        }
        return prev;              // new head
    }

    // reverseRecursive: O(n)
    public static Node reverseRecursive(Node head) 
    {
        if (head == null || head.next == null) return head;
        Node newHead = reverseRecursive(head.next);
        head.next.next = head;    // reverse pointer
        head.next = null;         // mark end
        return newHead;
    }

}
