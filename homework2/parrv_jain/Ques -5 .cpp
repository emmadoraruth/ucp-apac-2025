// Stack (linked-list implementation)
// Time Complexity: O(1) for push, pop, top, isEmpty
// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    // O(1)
    bool isEmpty() {
        return head == nullptr;
    }

    // O(1)
    void push(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }

    // O(1)
    int top() {
        return head ? head->val : -1;
    }

    // O(1)
    int pop() {
        if (!head) return -1;
        int res = head->val;
        Node* t = head;
        head = head->next;
        delete t;
        return res;
    }
};

int main() {
    Stack st;

    st.push(11);
    st.push(22);
    st.push(33);

    cout << st.top() << endl;   // Expected: 33
    cout << st.pop() << endl;   // Expected: 33
    cout << st.top() << endl;   // Expected: 22
    cout << st.isEmpty() << endl; // Expected: 0

    return 0;
}