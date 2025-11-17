// Question 1 : Implementing Singly Linked List 
// Time Taken: 37 minutes

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};

// O(1)
Node* insertAtFront(Node* head, int val) {
    Node* n = new Node(val);
    n->next = head;
    return n;
}

// O(n)
Node* insertAtBack(Node* head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        return n;
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = n;
    return head;
}

// O(1)
Node* insertAfter(Node* head, int val, Node* loc) {
    if (loc == nullptr) {
        return head;
    }
    Node* n = new Node(val);
    n->next = loc->next;
    loc->next = n;
    return head;
}

// O(n)
Node* insertBefore(Node* head, int val, Node* loc) {
    if (head == nullptr || loc == nullptr) {
        return head;
    }
    if (head == loc) {
        Node* n = new Node(val);
        n->next = head;
        return n;
    }
    Node* cur = head;
    while (cur->next != nullptr && cur->next != loc) {
        cur = cur->next;
    }
    if (cur->next == nullptr) {
        return head;
    }
    Node* n = new Node(val);
    n->next = loc;
    cur->next = n;
    return head;
}

// O(1)
Node* deleteFront(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* t = head;
    head = head->next;
    delete t;
    return head;
}

// O(n)
Node* deleteBack(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* cur = head;
    while (cur->next->next != nullptr) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = nullptr;
    return head;
}

// O(n)
Node* deleteNode(Node* head, Node* loc) {
    if (head == nullptr || loc == nullptr) {
        return head;
    }
    if (head == loc) {
        Node* t = head;
        head = head->next;
        delete t;
        return head;
    }
    Node* cur = head;
    while (cur->next != nullptr && cur->next != loc) {
        cur = cur->next;
    }
    if (cur->next == nullptr) {
        return head;
    }
    cur->next = loc->next;
    delete loc;
    return head;
}

// O(n)
int length(Node* head) {
    int c = 0;
    Node* cur = head;
    while (cur != nullptr) {
        c++;
        cur = cur->next;
    }
    return c;
}

// O(n)
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// O(n)
Node* reverseRecursiveHelper(Node* cur, Node* prev) {
    if (cur == nullptr) {
        return prev;
    }
    Node* nxt = cur->next;
    cur->next = prev;
    return reverseRecursiveHelper(nxt, cur);
}

Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

int main() {
    Node* head = nullptr;

    cout << "Inserting at Front" << endl;
    head = insertAtFront(head, 30);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 10);

    cout << "List after insertAtFront: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Inserting at Back" << endl;
    head = insertAtBack(head, 40);
    head = insertAtBack(head, 50);

    cout << "List after insertAtBack: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Insert After (after head->next)" << endl;
    head = insertAfter(head, 25, head->next); // Insert after second node

    cout << "List after insertAfter: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Insert Before (before head->next->next)" << endl;
    head = insertBefore(head, 22, head->next->next); // Insert before 25

    cout << "List after insertBefore: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Front" << endl;
    head = deleteFront(head);

    cout << "List after deleteFront: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Back" << endl;
    head = deleteBack(head);

    cout << "List after deleteBack: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Specific Node (delete head->next)" << endl;
    head = deleteNode(head, head->next);

    cout << "List after deleteNode: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Length of List" << endl;
    cout << "Length = " << length(head) << endl;

    cout << "Reverse Iterative" << endl;
    head = reverseIterative(head);

    cout << "List after reverseIterative: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Reverse Recursive" << endl;
    head = reverseRecursive(head);

    cout << "List after reverseRecursive: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    return 0;
}
