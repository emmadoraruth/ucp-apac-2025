class Node 
{
    int data;
    Node next;
    Node prev;

    Node(int data) 
    {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class ques2 
{

    // insertAtFront: O(1)
    public static Node insertAtFront(Node head, int val) 
    {
        Node newNode = new Node(val);
        newNode.next = head;
        if (head != null) head.prev = newNode;
        return newNode;   // new head
    }

    // insertAtBack: O(1) with tail; O(n) without tail
    public static Node insertAtBack(Node head, Node tail, int val) 
    {
        Node newNode = new Node(val);
        if (head == null) 
        {
            return newNode;   // list was empty
        }
        // Using tail pointer makes this O(1)
        tail.next = newNode;
        newNode.prev = tail;
        return head;
    }

    // insertAfter: O(1)
    public static Node insertAfter(Node head, int val, Node loc) 
    {
        if (loc == null) return head;
        Node newNode = new Node(val);
        newNode.next = loc.next;
        newNode.prev = loc;
        if (loc.next != null)
            loc.next.prev = newNode;
        loc.next = newNode;
        return head;
    }

    // insertBefore: O(1)
    public static Node insertBefore(Node head, int val, Node loc) 
    {
        if (loc == null) return head;
        // inserting before head
        if (loc == head) 
        {
            return insertAtFront(head, val);
        }
        Node newNode = new Node(val);
        newNode.next = loc;
        newNode.prev = loc.prev;
        loc.prev.next = newNode;
        loc.prev = newNode;
        return head;
    }

    // deleteFront: O(1)
    public static Node deleteFront(Node head) 
    {
        if (head == null) return null;
        head = head.next;
        if (head != null) head.prev = null;
        return head;
    }

    // deleteBack: O(1) with tail; O(n) without tail
    public static Node deleteBack(Node head, Node tail) 
    {
        if (head == null) return null;
        if (head == tail) 
        {
            return null;
        }
        // O(1) because tail is given
        Node newTail = tail.prev;
        newTail.next = null;
        return head;
    }

    // deleteNode: O(1)
    public static Node deleteNode(Node head, Node loc) 
    {
        if (loc == null) return head;
        // deleting head
        if (loc == head) 
        {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }
        // update previous
        if (loc.prev != null) 
        {
            loc.prev.next = loc.next;
        }
        // update next
        if (loc.next != null) {
            loc.next.prev = loc.prev;
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
        Node curr = head;
        Node temp = null;
        while (curr != null) 
        {
            // swap next and prev
            temp = curr.prev;
            curr.prev = curr.next;
            curr.next = temp;
            curr = curr.prev;   // move to original next node
        }

        // temp will be last non-null node
        if (temp != null) 
        {
            head = temp.prev;
        }
        return head;
    }

    // reverseRecursive: O(n)
    public static Node reverseRecursive(Node head) 
    {
        if (head == null) return null;
        // swap pointers
        Node temp = head.next;
        head.next = head.prev;
        head.prev = temp;
        // base case: end of list
        if (head.prev == null) 
        {
            return head;   // new head
        }
        return reverseRecursive(head.prev);
    }
}
