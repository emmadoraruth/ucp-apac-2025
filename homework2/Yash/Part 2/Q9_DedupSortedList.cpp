// Q9: Dedup Sorted Array, Technique Used: Linked list fixed-distance two-pointer
// Time Complexity: O(n), Space Complexity: O(1), Time Taken: 22 minutes

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



Node* dedupSortedList(Node* head) {
    Node* curr = head;

    if (curr == nullptr) {
        return nullptr;
    }
    if (curr->next == nullptr) {
        return head;
    }

    while (curr->next != nullptr) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}


void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}


int main() {
    cout << "Testing DedupSortedList\n";

    Node* head = nullptr;

    // Build sorted list with duplicates using your insertAtBack function
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 10);
    head = insertAtBack(head, 10);

    cout << "Before: ";
    printList(head);

    head = dedupSortedList(head);

    cout << "After:  ";
    printList(head);

    return 0;
}
