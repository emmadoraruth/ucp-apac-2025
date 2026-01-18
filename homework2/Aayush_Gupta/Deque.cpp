// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
    Node(int v) : value(v), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    int front() {
        return head ? head->value : -1;
    }

    int back() {
        return tail ? tail->value : -1;
    }

    void pushFront(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int x) {
        Node* newNode = new Node(x);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int popFront() {
        if (!head) return -1;
        int result = head->value;
        Node* toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete toDelete;
        return result;
    }

    int popBack() {
        if (!tail) return -1;
        int result = tail->value;
        Node* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete toDelete;
        return result;
    }
};

int main() {
    Deque dq;

    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(30);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    cout << dq.popFront() << endl;
    cout << dq.popBack() << endl;

    cout << dq.isEmpty() << endl;

    return 0;
}
