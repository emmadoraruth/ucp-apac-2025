// Doubly Linked List — operations, complexities and a few notes
// Time Complexity (per operation):
//   insertAtFront: O(1)    insertAtBack: O(1)    insertAfter: O(1)
//   insertBefore: O(1)     deleteFront: O(1)     deleteBack: O(1)
//   deleteNode: O(1)       length: O(n)
//   reverseIterative: O(n) reverseRecursive: O(n)
// Space Complexity: O(1) for all (ignoring recursion stack for reverseRecursive)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int value) : val(value), next(nullptr), prev(nullptr) {}
};

// O(1)
Node* insertAtFront(Node* head, int value) {
    Node* n = new Node(value);
    if (head == nullptr) return n;
    n->next = head;
    head->prev = n;
    return n;
}

// O(1)  -- tail is passed by reference and will be updated
Node* insertAtBack(Node* head, Node*& tail, int value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        // list was empty: new node becomes head and tail
        tail = n;
        return n;
    }
    // append after current tail and update tail ref
    tail->next = n;
    n->prev = tail;
    tail = n; // update caller's tail
    return head;
}

// O(1)
Node* insertAfter(Node* head, int value, Node* loc) {
    if (loc == nullptr) return head;
    Node* n = new Node(value);
    Node* nxt = loc->next;
    n->next = nxt;
    n->prev = loc;
    loc->next = n;
    if (nxt) nxt->prev = n;
    return head;
}

// O(1)
Node* insertBefore(Node* head, int value, Node* loc) {
    if (loc == nullptr) return head;
    if (loc->prev == nullptr) return insertAtFront(head, value);
    Node* prv = loc->prev;
    Node* n = new Node(value);
    n->next = loc;
    n->prev = prv;
    prv->next = n;
    loc->prev = n;
    return head;
}

// O(1)
Node* deleteFront(Node* head) {
    if (head == nullptr) return nullptr;
    Node* nxt = head->next;
    delete head;
    if (nxt) nxt->prev = nullptr;
    return nxt;
}

// O(1) -- tail is passed by reference and will be updated
Node* deleteBack(Node* head, Node*& tail) {
    if (head == nullptr) return nullptr;
    if (tail->prev == nullptr) { // single node in list
        delete tail;
        tail = nullptr;
        return nullptr;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    tail = newTail; // update caller's tail
    return head;
}

// O(1)
Node* deleteNode(Node* head, Node* loc) {
    if (head == nullptr || loc == nullptr) return head;
    if (loc->prev == nullptr) return deleteFront(head);
    if (loc->next == nullptr) {
        // need a tail to call deleteBack directly; caller can use deleteBack(head, tail)
        Node* prv = loc->prev;
        prv->next = nullptr;
        delete loc;
        return head;
    }
    Node* prv = loc->prev;
    Node* nxt = loc->next;
    prv->next = nxt;
    nxt->prev = prv;
    delete loc;
    return head;
}

// O(n)
int length(Node* head) {
    int cnt = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) ++cnt;
    return cnt;
}

// O(n)
Node* reverseIterative(Node* head) {
    Node* cur = head;
    Node* newHead = nullptr;
    while (cur != nullptr) {
        Node* nxt = cur->next;
        // swap next and prev
        cur->next = cur->prev;
        cur->prev = nxt;
        newHead = cur;
        cur = nxt;
    }
    return newHead;
}

// O(n)
Node* reverseRecursiveHelper(Node* cur, Node* prev) {
    if (cur == nullptr) return prev;
    Node* nxt = cur->next;
    cur->next = prev;
    cur->prev = nxt;
    return reverseRecursiveHelper(nxt, cur);
}

Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printForward(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // build list: 1 2 3 4 (using tail-ref insertAtBack)
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);
    // now list is: 1 2

    // find current tail
    tail = head;
    while (tail && tail->next) tail = tail->next; // tail -> node with val 2

    head = insertAtBack(head, tail, 3); // tail updated inside
    head = insertAtBack(head, tail, 4); // tail updated inside

    cout << "Forward after inserts: ";
    printForward(head);
    // Expected: 1 2 3 4

    cout << "Reverse iteratively: ";
    head = reverseIterative(head);
    printForward(head);
    // Expected: 4 3 2 1

    cout << "Reverse recursively (back to original): ";
    head = reverseRecursive(head);
    printForward(head);
    // Expected: 1 2 3 4

    cout << "Length = " << length(head) << "\n";
    // Expected: Length = 4

    // demonstrate deleteBack updating tail
    head = deleteBack(head, tail); // removes 4, tail -> 3
    cout << "After deleteBack: ";
    printForward(head);
    // Expected: 1 2 3

    return 0;
}
