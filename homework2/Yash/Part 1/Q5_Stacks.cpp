// Q5: Implementing Stacks
// Time Taken: 18 minutes

#include <iostream>
using namespace std;

// SLL

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

// Stack Implementation using SLL

class Stack {
    private:
        Node* head; // top of stack

    public:
        Stack() {
            head = nullptr;
        }

        bool isEmpty() {
            if (head == nullptr) {
                return true;
            } else {
                return false;
            }
        }

        int top() {
            if (head == nullptr) {
                return -1;
            }
            return head->val;
        }

        void push(int x) {
            Node* n = new Node(x);
            n->next = head;
            head = n;
        }

        int pop() {
            if (head == nullptr) {
                return -1;
            }
            int v = head->val;
            Node* t = head;
            head = head->next;
            delete t;
            return v;
        }
};


int main() {
    cout << "Testing Stack built on SLL\n";

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << "\n";

    cout << "Pop: " << s.pop() << "\n";
    cout << "Pop: " << s.pop() << "\n";

    cout << "IsEmpty: " << s.isEmpty() << "\n";

    cout << "Pop: " << s.pop() << "\n";
    cout << "IsEmpty: " << s.isEmpty() << "\n";

    return 0;
}
