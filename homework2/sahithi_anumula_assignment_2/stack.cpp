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

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    // Push new value onto the stack
    void push(int x) {
        Node* newNode = createNode(x);
        newNode->next = head;
        head = newNode;
    }

    // Pop the top element and return it
    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty\n";
            return -1;
        }
        int val = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    // Peek the top element
    int top() {
        if (isEmpty()) {
            cerr << "Stack is empty\n";
            return -1;
        }
        return head->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  

    cout << s.pop() << endl; 
    cout <<  s.pop() << endl;  

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << s.pop() << endl;  
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
