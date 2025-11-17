// Q10: Move Nth Last to Front, Technique Used: Linked list fixed-distance two-pointer
// Time Complexity: O(n), Space Complexity: O(1), Time Taken : 27 minutes

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

// Helper to print list (for testing)
void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}



Node* moveNthLastToFront(Node* head, int k) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            return head; // k too large
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches end
    while (fast != nullptr) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    // Now: slow = kth last node
    // prev = node before slow

    if (prev != nullptr) {
        prev->next = slow->next;
    }

    // move slow to front
    slow->next = head;
    head = slow;

    return head;
}



int main() {
    cout << "Testing MoveNthLastToFront\n";

    Node* head = nullptr;

    // Build list: 15 → 2 → 8 → 7 → 20 → 9 → 11 → 6 → 19
    head = insertAtBack(head, 15);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 8);
    head = insertAtBack(head, 7);
    head = insertAtBack(head, 20);
    head = insertAtBack(head, 9);
    head = insertAtBack(head, 11);
    head = insertAtBack(head, 6);
    head = insertAtBack(head, 19);

    cout << "Original: ";
    printList(head);

    int k = 2;  
    head = moveNthLastToFront(head, k);

    cout << "After moving 2nd-last to front: ";
    printList(head);

    // Second example: k = 7
    head = nullptr;
    head = insertAtBack(head, 15);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 8);
    head = insertAtBack(head, 7);
    head = insertAtBack(head, 20);
    head = insertAtBack(head, 9);
    head = insertAtBack(head, 11);
    head = insertAtBack(head, 6);
    head = insertAtBack(head, 19);

    cout << "\nOriginal: ";
    printList(head);

    k = 7;
    head = moveNthLastToFront(head, k);

    cout << "After moving 7th-last to front: ";
    printList(head);

    return 0;
}
