// Queue (linked-list implementation)
// Time Complexity:
//   peek: O(1)   enqueue: O(1)   dequeue: O(1)   isEmpty: O(1)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    // O(1)
    int peek() {
        if (front == nullptr) return -1;
        return front->val;
    }

    // O(1)
    void enqueue(int value) {
        Node* n = new Node(value);
        if (back == nullptr) {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    // O(1)
    int dequeue() {
        if (front == nullptr) return -1;
        int value = front->val;
        Node* nxt = front->next;
        delete front;
        front = nxt;
        if (front == nullptr) back = nullptr;
        return value;
    }

    // O(1)
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(42);
    q.enqueue(7);
    q.enqueue(99);

    cout << "Peek: " << q.peek() << endl;            // Expected: 42

    cout << "Dequeued: " << q.dequeue() << endl;    // Expected: 42
    cout << "Dequeued: " << q.dequeue() << endl;    // Expected: 7

    cout << "Empty? " << q.isEmpty() << endl;       // Expected: 0

    cout << "Dequeued: " << q.dequeue() << endl;    // Expected: 99
    cout << "Empty now? " << q.isEmpty() << endl;   // Expected: 1

    return 0;
}