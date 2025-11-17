//Q12: Disconnect Cycle, Technique Used: Linked list fast-slow two-pointer (Floyd's cycle detection)
// Time Complexity: O(n), Space Complexity: O(1), Time Taken: 28 minutes

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



Node* disconnectCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    // Step 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        return head; // no cycle
    }

    // Step 2: Find start of cycle
    slow = head;
    Node* prev = nullptr;

    while (slow != fast) {
        prev = fast;      // track the node before fast
        slow = slow->next;
        fast = fast->next;
    }

    // slow == fast is the start of the cycle
    // prev is the node whose next must be cut

    prev->next = nullptr;

    return head;
}

// Print list 
void printList(Node* head) {
    Node* cur = head;
    int count = 0;
    while (cur != nullptr && count < 30) {
        cout << cur->val << " ";
        cur = cur->next;
        count++;
    }
    cout << "\n";
}


int main() {
    cout << "Testing DisconnectCycle\n";

    Node* head = nullptr;

    // Build list: 10 → 18 → 12 → 9 → 11 → 4
    head = insertAtBack(head, 10);
    head = insertAtBack(head, 18);
    head = insertAtBack(head, 12);
    head = insertAtBack(head, 9);
    head = insertAtBack(head, 11);
    head = insertAtBack(head, 4);

    // Create cycle: 4 -> 12
    Node* cur = head;
    Node* cycleNode = nullptr;
    Node* last = nullptr;

    while (cur != nullptr) {
        if (cur->val == 12) {
            cycleNode = cur;
        }
        if (cur->next == nullptr) {
            last = cur;
        }
        cur = cur->next;
    }
    last->next = cycleNode;  // create cycle

    // Disconnect cycle
    head = disconnectCycle(head);

    cout << "After disconnect: ";
    printList(head);

    // Second Example: cycle starting at 4
    head = nullptr;
    head = insertAtBack(head, 10);
    head = insertAtBack(head, 18);
    head = insertAtBack(head, 12);
    head = insertAtBack(head, 9);
    head = insertAtBack(head, 11);
    head = insertAtBack(head, 4);

    // Create cycle: 4 -> itself
    cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = cur;  // point 4->4

    head = disconnectCycle(head);

    cout << "After disconnect: ";
    printList(head);

    return 0;
}
