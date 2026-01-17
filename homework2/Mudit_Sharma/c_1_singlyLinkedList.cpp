// Implement the following methods. Rather than having a separate
// linked list class, we will pass a Node struct that represents
// the head of the list (this is common practice in interview questions). \
// The linked list article includes a Node struct definition in a
// number of common languages (C++, Python, Java, JavaScript);
// feel free to use it in your implementation. For simplicity,
// you can make your nodes store integers rather than generic
// data types. In each of the methods, you should use pointers
// in languages that support pointers (e.g., Node * in C++) or a
// reference in languages that support references (e.g., Python).

// struct Node {
//   int data
//   Node next
// }

// Node insertAtFront(Node head, int val) // creates new Node with data val at front; returns head. O(1) time.
// Node insertAtBack(Node head int val) // creates new Node with data val at end; returns head. O) time.
// Node insertAfter(Node head, int val, Node loc) // creates new Node with data val after Node loc; returns head. O(1) time.
// Node insertBefore(Node head, int val, Node loc) // creates new Node with data val before Node loc; returns head. O) time.
// Node deleteFront(Node head) // removes first Node; returns head. O(1) time.
// Node deleteBack(Node head) // removes last Node; returns head. O) time.
// Node deleteNode(Node head, Node loc) // deletes Node loc; returns head. O) time.
// int length(Node head) // returns length of the list. O) time.
// Node reverseIterative(Node head) // reverses the linked list iteratively. O) time.
// Node reverseRecursive(Node head) // reverses the linked list recursively (Hint: you will need a helper function.) O) time.

// Time taken : 45 minutes
//Spent alot time on displaying the result

#include <iostream>

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = NULL;
    }
};

// --------------------------- INSERTS ---------------------------

// O(1)
Node *insertAtFront(Node *head, int val)
{
    Node *toadd = new Node(val);
    toadd->next = head;
    return toadd;
}

// O)
Node *insertAtBack(Node *head, int val)
{
    Node *toadd = new Node(val);
    if (head == NULL)
        return toadd;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = toadd;
    return head;
}

// O(1)
Node *insertAfter(Node *head, int val, Node *loc)
{
    if (loc == NULL)
        return head;

    Node *toadd = new Node(val);
    toadd->next = loc->next;
    loc->next = toadd;

    return head;
}

// O)
Node *insertBefore(Node *head, int val, Node *loc)
{
    if (head == NULL || loc == NULL)
        return head;

    Node *toadd = new Node(val);

    if (head == loc)
    {
        toadd->next = head;
        return toadd;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && curr != loc)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return head; // loc not found

    prev->next = toadd;
    toadd->next = curr;

    return head;
}

// --------------------------- DELETES ---------------------------

// O(1)
Node *deleteFront(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

// O)
Node *deleteBack(Node *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    delete curr;

    return head;
}

// O)
Node *deleteNode(Node *head, Node *loc)
{
    if (head == NULL || loc == NULL)
        return head;

    if (head == loc)
    {
        Node *newhead = head->next;
        delete head;
        return newhead;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL && curr != loc)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return head; // loc not found

    prev->next = curr->next;
    delete curr;

    return head;
}

// --------------------------- MISC ---------------------------

int length(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

// O)
Node *reverseIterative(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

// helper for recursive reverse
void reverseRec(Node *curr, Node *&newHead)
{
    if (curr == NULL)
        return;

    Node *nxt = curr->next;
    curr->next = newHead;
    newHead = curr;

    reverseRec(nxt, newHead);
}

Node *reverseRecursive(Node *head)
{
    Node *newHead = NULL;
    reverseRec(head, newHead);
    return newHead;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL";
}

// --------------------------- MAIN (Your Example) ---------------------------

int main()
{
    Node *head = NULL;

    std::cout << "=== Insert At Front ===";
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);
    printList(head);

    std::cout << "=== Insert At Back ===";
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 1);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Insert After (Insert 99 after head->next) ===";
    std::cout << std::endl;
    head = insertAfter(head, 99, head->next);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Insert Before (Insert 77 before head->next->next) ===";
    std::cout << std::endl;
    head = insertBefore(head, 77, head->next->next);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Delete Front ===";
    std::cout << std::endl;
    head = deleteFront(head);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Delete Back ===";
    std::cout << std::endl;
    head = deleteBack(head);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Delete Specific Node (Delete head->next) ===";
    std::cout << std::endl;
    head = deleteNode(head, head->next);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Length of List ===";
    std::cout << std::endl;
    std::cout << length(head) << "";
    std::cout << std::endl;
    std::cout << "=== Reverse (Iterative) ===";
    std::cout << std::endl;
    head = reverseIterative(head);
    printList(head);
    std::cout << std::endl;
    std::cout << "=== Reverse (Recursive) ===";
    std::cout << std::endl;
    head = reverseRecursive(head);
    printList(head);

    return 0;
    std::cout << "=== Reverse (Recursive) ===";
    std::cout << std::endl;
    head = reverseRecursive(head);
    printList(head);

    return 0;
}