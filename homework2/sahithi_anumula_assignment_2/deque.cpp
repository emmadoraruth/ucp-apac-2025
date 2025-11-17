#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

class Deque {
private:
    Node* frontNode; 
    Node* backNode;  

public:
    Deque() : frontNode(nullptr), backNode(nullptr) {}

    // Returns the first item
    int front() {
        if (isEmpty()) {
            cerr << "Deque is empty\n";
            return -1;
        }
        return frontNode->data;
    }

    // Returns the last item
    int back() {
        if (isEmpty()) {
            cerr << "Deque is empty\n";
            return -1;
        }
        return backNode->data;
    }

    // Adds x to the back
    void pushBack(int x) {
        Node* newNode = createNode(x);
        if (isEmpty()) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            newNode->prev = backNode;
            backNode = newNode;
        }
    }

    // Adds x to the front
    void pushFront(int x) {
        Node* newNode = createNode(x);
        if (isEmpty()) {
            frontNode = backNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }
    }

    // Removes and returns the first item
    int popFront() {
        if (isEmpty()) {
            cerr << "Deque is empty\n";
            return -1;
        }
        int val = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode) {
            frontNode->prev = nullptr;
        } else {
            backNode = nullptr; 
        }
        delete temp;
        return val;
    }

    // Removes and returns the last item
    int popBack() {
        if (isEmpty()) {
            cerr << "Deque is empty\n";
            return -1;
        }
        int val = backNode->data;
        Node* temp = backNode;
        backNode = backNode->prev;
        if (backNode) {
            backNode->next = nullptr;
        } else {
            frontNode = nullptr; 
        }
        delete temp;
        return val;
    }

    // Checks if the deque is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }
};

int main() {
    Deque dq;

    dq.pushFront(2);
    dq.pushBack(3);
    dq.pushFront(1);

    cout << dq.front() << endl;  
    cout << dq.back() << endl;    

    cout << dq.popFront() << endl; 
    cout << dq.popBack() << endl;  
    cout << dq.popFront() << endl; 

    cout << "Is deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
