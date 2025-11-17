// Q6: Implementing Dequeue
// Time Taken: 19 minutes

#include <iostream>
using namespace std;

// DLL

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


// Deque implementation using DLL


class Deque {
    private:
        Node* head;  // front
        Node* tail;  // back

    public:
        Deque() {
            head = nullptr;
            tail = nullptr;
        }

        bool isEmpty() {
            if (head == nullptr) {
                return true;
            } else {
                return false;
            }
        }

        int front() {
            if (head == nullptr) {
                return -1;
            }
            return head->val;
        }

        int back() {
            if (tail == nullptr) {
                return -1;
            }
            return tail->val;
        }

        void pushFront(int x) {
            Node* n = new Node(x);
            if (head == nullptr) {
                head = n;
                tail = n;
            } else {
                n->next = head;
                head->prev = n;
                head = n;
            }
        }

        void pushBack(int x) {
            Node* n = new Node(x);
            if (tail == nullptr) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        }

        int popFront() {
            if (head == nullptr) {
                return -1;
            }
            int v = head->val;
            Node* t = head;

            head = head->next;

            if (head == nullptr) {
                tail = nullptr;
            } else {
                head->prev = nullptr;
            }

            delete t;
            return v;
        }

        int popBack() {
            if (tail == nullptr) {
                return -1;
            }
            int v = tail->val;
            Node* t = tail;

            tail = tail->prev;

            if (tail == nullptr) {
                head = nullptr;
            } else {
                tail->next = nullptr;
            }

            delete t;
            return v;
        }
};


int main() {
    cout << "Testing Deque\n";

    Deque d;

    d.pushFront(10);
    d.pushBack(20);
    d.pushFront(5);
    d.pushBack(30);

    cout << "Front: " << d.front() << "\n";
    cout << "Back:  " << d.back() << "\n";

    cout << "PopFront: " << d.popFront() << "\n";
    cout << "PopBack:  " << d.popBack() << "\n";

    cout << "Front: " << d.front() << "\n";
    cout << "Back:  " << d.back() << "\n";

    cout << "IsEmpty: " << d.isEmpty() << "\n";

    d.popFront();
    d.popFront();

    cout << "IsEmpty: " << d.isEmpty() << "\n";

    return 0;
}
