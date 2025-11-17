// Q2: Implementing Doubly Linked List
// Time Taken: 17 minutes

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

// O(1)
Node* insertAtFront(Node* head, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        return n;
    }
    n->next = head;
    head->prev = n;
    return n;
}

// O(1)
Node* insertAtBack(Node* head, Node* tail, int val) {
    Node* n = new Node(val);
    if (head == nullptr) {
        return n;
    }
    tail->next = n;
    n->prev = tail;
    return head;
}

// O(1)
Node* insertAfter(Node* head, int val, Node* loc) {
    if (loc == nullptr) {
        return head;
    }
    Node* n = new Node(val);
    n->next = loc->next;
    n->prev = loc;

    if (loc->next != nullptr) {
        loc->next->prev = n;
    }

    loc->next = n;
    return head;
}

// O(1)
Node* insertBefore(Node* head, int val, Node* loc) {
    if (loc == nullptr) {
        return head;
    }
    Node* n = new Node(val);

    n->prev = loc->prev;
    n->next = loc;

    if (loc->prev != nullptr) {
        loc->prev->next = n;
    } else {
        head = n;
    }

    loc->prev = n;
    return head;
}

// O(1)
Node* deleteFront(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
    return head;
}

// O(1)
Node* deleteBack(Node* head, Node* tail) {
    if (head == nullptr) {
        return nullptr;
    }
    if (tail->prev == nullptr) {
        delete tail;
        return nullptr;
    }

    Node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    return head;
}

// O(1)
Node* deleteNode(Node* head, Node* loc) {
    if (loc == nullptr) {
        return head;
    }
    if (loc->prev != nullptr) {
        loc->prev->next = loc->next;
    } else {
        head = loc->next;
    }
    if (loc->next != nullptr) {
        loc->next->prev = loc->prev;
    }

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
    Node* cur = head;
    Node* newHead = nullptr;

    while (cur != nullptr) {
        Node* nxt = cur->next;

        cur->next = cur->prev;
        cur->prev = nxt;

        newHead = cur;
        cur = nxt;
    }

    return newHead;
}

// O(n)
Node* reverseRecHelper(Node* cur, Node* prev) {
    if (cur == nullptr) {
        return prev;
    }

    Node* nxt = cur->next;

    cur->next = prev;
    cur->prev = nxt;

    return reverseRecHelper(nxt, cur);
}

Node* reverseRecursive(Node* head) {
    return reverseRecHelper(head, nullptr);
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "--- Inserting at Front ---" << endl;
    head = insertAtFront(head, 30);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 10);

    // updating tail (only if needed)
    tail = head;
    while (tail->next != nullptr) tail = tail->next;

    cout << "List (front to back): ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Inserting at Back" << endl;
    head = insertAtBack(head, tail, 40);
    tail = tail->next;  // tail moves forward
    head = insertAtBack(head, tail, 50);
    tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Insert After (after head->next)" << endl;
    head = insertAfter(head, 25, head->next);

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Insert Before (before head->next->next)" << endl;
    head = insertBefore(head, 22, head->next->next);

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Front" << endl;
    head = deleteFront(head);

    // update tail
    tail = head;
    while (tail->next != nullptr) tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Back" << endl;
    head = deleteBack(head, tail);

    // update tail
    tail = head;
    while (tail && tail->next != nullptr) tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Delete Specific Node (delete head->next)" << endl;
    head = deleteNode(head, head->next);

    // update tail
    tail = head;
    while (tail && tail->next != nullptr) tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Length of List" << endl;
    cout << "Length = " << length(head) << endl;

    cout << "Reverse Iterative" << endl;
    head = reverseIterative(head);

    // update tail
    tail = head;
    while (tail && tail->next != nullptr) tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    cout << "Reverse Recursive" << endl;
    head = reverseRecursive(head);

    // update tail
    tail = head;
    while (tail && tail->next != nullptr) tail = tail->next;

    cout << "List: ";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;

    return 0;
}
