// Time Complexity:
// peek: O(1)
// enqueue: O(1)
// dequeue: O(1)
// isEmpty: O(1)

// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* frontNode;
    Node* backNode;

public:
    Queue() : frontNode(nullptr), backNode(nullptr) {}

    int peek() {
        if (!frontNode) return -1;
        return frontNode->data;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (!backNode) {
            frontNode = newNode;
            backNode = newNode;
            return;
        }
        backNode->next = newNode;
        backNode = newNode;
    }

    int dequeue() {
        if (!frontNode) return -1;
        int value = frontNode->data;
        Node* nextNode = frontNode->next;
        delete frontNode;
        frontNode = nextNode;
        if (!frontNode) backNode = nullptr;
        return value;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.isEmpty() << endl;

    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
