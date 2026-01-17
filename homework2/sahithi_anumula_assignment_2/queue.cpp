#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Returns the value at the front 
    int peek() {
        if (isEmpty()) {
            cerr << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Enqueue new value at the back
    void enqueue(int x) {
        Node* newNode = createNode(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue the front element and return it
    int dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty\n";
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;

        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;  

    cout <<  q.dequeue() << endl;  
    cout << q.dequeue() << endl;  

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << q.dequeue() << endl;  
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
