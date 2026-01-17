// Copy-paste your singly linked list implementation and modify it. Your Node struct should have an additional prev reference as well as a next.

// struct Node {
//   int data
//   Node next
//   Node prev
// }

// Node insertAtFront(Node head, int val) // creates new Node with data val at front; returns head. O(1) time.
// Node insertAtBack(Node head, Node tail, int val) // creates new Node with data val at end; returns head. O(1) time.
// Node insertAfter(Node head, int val, Node loc) // creates new Node with data val after Node loc; returns head. O(1) time.
// Node insertBefore(Node head, int val, Node loc) // creates new Node with data val before Node loc; returns head. O(1) time.
// Node deleteFront(Node head) // removes first Node; returns head. O(1) time.
// Node deleteBack(Node head, Node tail) // removes last Node; returns head. O(1) time.
// Node deleteNode(Node head, Node loc) // deletes Node loc; returns head. O(1) time.
// int length(Node head) // returns length of the list. O(n) time.
// Node reverseIterative(Node head) // reverses the linked list iteratively. O(n) time.
// Node reverseRecursive(Node head) // reverses the linked list recursively (Hint: you will need a helper function.)  O(n) time.


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
// Node insertAtBack(Node head int val) // creates new Node with data val at end; returns head. O(n) time.
// Node insertAfter(Node head, int val, Node loc) // creates new Node with data val after Node loc; returns head. O(1) time.
// Node insertBefore(Node head, int val, Node loc) // creates new Node with data val before Node loc; returns head. O(n) time.
// Node deleteFront(Node head) // removes first Node; returns head. O(1) time.
// Node deleteBack(Node head) // removes last Node; returns head. O(n) time.
// Node deleteNode(Node head, Node loc) // deletes Node loc; returns head. O(n) time.
// int length(Node head) // returns length of the list. O(n) time.
// Node reverseIterative(Node head) // reverses the linked list iteratively. O(n) time.
// Node reverseRecursive(Node head) // reverses the linked list recursively (Hint: you will need a helper function.) O(n) time.


//Time taken:30 min

#include <bits/stdc++.h>

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int value) {
        val = value;
        next = NULL;
        prev=NULL;
    }
};

// --------------------------- INSERTS ---------------------------

// O(1)
Node* insertAtFront(Node* head, int val) {
    Node* toadd = new Node(val);
    toadd->next = head;
    if(head) head->prev=toadd;
    return toadd;
}

// O(n)
Node* insertAtBack(Node* head, int val) {
    Node* toadd = new Node(val);
    if (head == NULL) return toadd;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = toadd;
    toadd->prev=temp;
    return head;
}

// O(1)
Node* insertAfter(Node* head, int val, Node* loc) {
    if (loc == NULL) return head;

    Node* toadd = new Node(val);
    toadd->next = loc->next;
    loc->next = toadd;
    toadd->prev=loc;
    if(toadd->next){
        toadd->next->prev=toadd;
    }

    return head;
}

// O(n)
Node* insertBefore(Node* head, int val, Node* loc) {
    if (head == NULL || loc == NULL)
        return head;

    Node* toadd = new Node(val);

    if (head == loc) {
        toadd->next = head;
        head->prev=toadd;
        return toadd;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr != loc) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
        return head;  // loc not found

    prev->next = toadd;
    toadd->prev=prev;
    toadd->next = curr;
    curr->prev=toadd;

    return head;
}

// --------------------------- DELETES ---------------------------

// O(1)
Node* deleteFront(Node* head) {
    if (head == NULL) return head;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return head;
}


// O(n)
Node* deleteBack(Node* head) {
    if (head == NULL) return head;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    delete curr;

    return head;
}

// O(n)
Node* deleteNode(Node* head, Node* loc) {
    if (head == NULL || loc == NULL)
        return head;

    if (head == loc) {
        Node* newhead = head->next;
        newhead->prev=NULL;
        delete head;
        return newhead;
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr != loc) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) return head; // loc not found

    prev->next = curr->next;
    if(curr->next) curr->next->prev=prev;
    delete curr;

    return head;
}

// --------------------------- MISC ---------------------------

int length(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// O(n)
Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* nxt = curr->next;
        curr->next = prev;
        curr->prev=nxt;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

// helper for recursive reverse
void reverseRec(Node* curr, Node*& newHead) {
    if (curr == NULL) return;

    Node* nxt = curr->next;
    curr->next = newHead;
    if(newHead) newHead->prev=curr;
    newHead = curr;

    reverseRec(nxt, newHead);
}

Node* reverseRecursive(Node* head) {
    Node* newHead = NULL;
    reverseRec(head, newHead);
    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}


// --------------------------- MAIN (Your Example) ---------------------------

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    std::cout << "\n=== Insert At Front ===\n";
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);

    tail = head;
    while (tail->next) tail = tail->next; // set tail

    printList(head);

    std::cout << "\n=== Insert At Back ===\n";
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 1);

    tail = tail->next->next; // update tail two nodes later
    printList(head);

    std::cout << "\n=== Insert After (Insert 99 after head->next) ===\n";
    head = insertAfter(head, 99, head->next);
    printList(head);

    std::cout << "\n=== Insert Before (Insert 77 before 2 nodes ahead) ===\n";
    head = insertBefore(head, 77, head->next->next);
    printList(head);

    std::cout << "\n=== Delete Front ===\n";
    head = deleteFront(head);
    printList(head);

    std::cout << "\n=== Delete Back ===\n";
    head = deleteBack(head);
    printList(head);

    std::cout << "\n=== Delete Specific Node (Delete head->next) ===\n";
    head = deleteNode(head, head->next);
    printList(head);

    std::cout << "\n=== Length ===\n";
    std::cout << length(head) << "\n";

    std::cout << "\n=== Reverse (Iterative) ===\n";
    head = reverseIterative(head);
    printList(head);

    std::cout << "\n=== Reverse (Recursive) ===\n";
    head = reverseRecursive(head);
    printList(head);

    return 0;
}