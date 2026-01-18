// Singly Linked List — operations, complexities and small notes
// Time Complexity (per operation):
//   insertAtFront: O(1)     insertAtBack: O(n)     insertAfter: O(1)
//   insertBefore: O(n)      deleteFront: O(1)      deleteBack: O(n)
//   deleteNode: O(n)        length: O(n)
//   reverseIterative: O(n)  reverseRecursive: O(n)
// Space Complexity: O(1) for all (ignoring recursion stack for reverseRecursive)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

// O(1)
Node* insertAtFront(Node* head, int value) {
    Node* n = new Node(value);
    n->next = head;
    return n;
}

// O(n)
Node* insertAtBack(Node* head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) return n;
    Node* cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = n;
    return head;
}

// O(1)
Node* insertAfter(Node* head, int value, Node* loc) {
    if (loc == nullptr) return head;
    Node* n = new Node(value);
    n->next = loc->next;
    loc->next = n;
    return head;
}

// O(n)
Node* insertBefore(Node* head, int value, Node* loc) {
    if (loc == nullptr) return head;
    if (head == loc) return insertAtFront(head, value);
    Node* cur = head;
    while (cur != nullptr && cur->next != loc) cur = cur->next;
    if (cur == nullptr) return head;
    Node* n = new Node(value);
    n->next = loc;
    cur->next = n;
    return head;
}

// O(1)
Node* deleteFront(Node* head) {
    if (head == nullptr) return nullptr;
    Node* t = head;
    head = head->next;
    delete t;
    return head;
}

// O(n)
Node* deleteBack(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* cur = head;
    while (cur->next->next != nullptr) cur = cur->next;
    delete cur->next;
    cur->next = nullptr;
    return head;
}

// O(n)
Node* deleteNode(Node* head, Node* loc) {
    if (head == nullptr || loc == nullptr) return head;
    if (head == loc) return deleteFront(head);
    Node* cur = head;
    while (cur != nullptr && cur->next != loc) cur = cur->next;
    if (cur == nullptr) return head;
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
    if (cur == nullptr) return prev;
    Node* nxt = cur->next;
    cur->next = prev;
    return reverseRecursiveHelper(nxt, cur);
}

Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printList(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;
}

int main() {
    Node* head = nullptr;

    cout << "Inserting at Front" << endl;
    head = insertAtFront(head, 30);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 10);

    cout << "List after insertAtFront: ";
    printList(head);
    // Expected: 10 20 30

    cout << "Inserting at Back" << endl;
    head = insertAtBack(head, 40);
    head = insertAtBack(head, 50);

    cout << "List after insertAtBack: ";
    printList(head);
    // Expected: 10 20 30 40 50

    cout << "Insert After (after head->next)" << endl;
    head = insertAfter(head, 25, head->next); // Insert after second node

    cout << "List after insertAfter: ";
    printList(head);
    // Expected: 10 20 25 30 40 50

    cout << "Insert Before (before head->next->next)" << endl;
    head = insertBefore(head, 22, head->next->next); // Insert before 25

    cout << "List after insertBefore: ";
    printList(head);
    // Expected: 10 20 22 25 30 40 50

    cout << "Delete Front" << endl;
    head = deleteFront(head);

    cout << "List after deleteFront: ";
    printList(head);
    // Expected: 20 22 25 30 40 50

    cout << "Delete Back" << endl;
    head = deleteBack(head);

    cout << "List after deleteBack: ";
    printList(head);
    // Expected: 20 22 25 30 40

    cout << "Delete Specific Node (delete head->next)" << endl;
    head = deleteNode(head, head->next);

    cout << "List after deleteNode: ";
    printList(head);
    // Expected: 20 25 30 40

    cout << "Length of List = " << length(head) << endl;
    // Expected: Length of List = 4

    cout << "Reverse Iterative" << endl;
    head = reverseIterative(head);

    cout << "List after reverseIterative: ";
    printList(head);
    // Expected: 40 30 25 20

    cout << "Reverse Recursive" << endl;
    head = reverseRecursive(head);

    cout << "List after reverseRecursive: ";
    printList(head);
    // Expected: 20 25 30 40

    return 0;
}
