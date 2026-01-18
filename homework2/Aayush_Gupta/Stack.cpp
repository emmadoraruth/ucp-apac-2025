// Time Complexity: O(1) for push, pop, top, isEmpty
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    int top() {
        return head ? head->value : -1;
    }

    int pop() {
        if (!head) return -1;
        int result = head->value;
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return result;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;  
    cout << st.pop() << endl;  
    cout << st.top() << endl;  
    cout << st.isEmpty() << endl; 

    return 0;
}
