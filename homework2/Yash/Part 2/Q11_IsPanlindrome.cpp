// Q11: Is Palindrome, Technique Used: Doubly linked list forward-backward two-pointer
// Time Complexity: O(n), Space Complexity: O(1), Time Taken : 18 minutes

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



bool isPalindrome(Node* head, Node* tail) {
    if (head == nullptr) {
        return true;
    }

    Node* left = head;
    Node* right = tail;

    while (left != nullptr && right != nullptr && left != right && left->prev != right) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}


void printDLL(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}


int main() {
    cout << "Testing IsPalindrome\n";

    // Build DLL: 9 <-> 2 <-> 4 <-> 2 <-> 9
    Node* head = new Node(9);
    Node* tail = head;

    head = insertAtBack(head, tail, 2);  tail = tail->next;
    head = insertAtBack(head, tail, 4);  tail = tail->next;
    head = insertAtBack(head, tail, 2);  tail = tail->next;
    head = insertAtBack(head, tail, 9);  tail = tail->next;

    cout << "List: ";
    printDLL(head);
    cout << "IsPalindrome: " << isPalindrome(head, tail) << "\n\n";

    // Second Example: 9 <-> 12 <-> 4 <-> 2 <-> 9
    head = new Node(9);
    tail = head;

    head = insertAtBack(head, tail, 12);  tail = tail->next;
    head = insertAtBack(head, tail, 4);   tail = tail->next;
    head = insertAtBack(head, tail, 2);   tail = tail->next;
    head = insertAtBack(head, tail, 9);   tail = tail->next;

    cout << "List: ";
    printDLL(head);
    cout << "IsPalindrome: " << isPalindrome(head, tail) << "\n";

    return 0;
}
