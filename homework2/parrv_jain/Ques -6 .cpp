// Deque (doubly-linked list)
// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    // O(1)
    bool isEmpty() {
        return head == nullptr;
    }

    // O(1)
    int front() {
        return head ? head->val : -1;
    }

    // O(1)
    int back() {
        return tail ? tail->val : -1;
    }

    // O(1)
    void pushFront(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    // O(1)
    void pushBack(int x) {
        Node* n = new Node(x);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    // O(1)
    int popFront() {
        if (!head) return -1;
        int res = head->val;
        Node* t = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete t;
        return res;
    }

    // O(1)
    int popBack() {
        if (!tail) return -1;
        int res = tail->val;
        Node* t = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete t;
        return res;
    }
};

int main() {
    Deque dq;

    dq.pushFront(11);   // deque: 11
    dq.pushBack(22);    // deque: 11 22
    dq.pushFront(6);    // deque: 6 11 22
    dq.pushBack(33);    // deque: 6 11 22 33

    cout << dq.front() << endl;   // Expected: 6
    cout << dq.back() << endl;    // Expected: 33

    cout << dq.popFront() << endl; // Expected: 6
    cout << dq.popBack() << endl;  // Expected: 33

    cout << dq.isEmpty() << endl;  // Expected: 0

    return 0;
}