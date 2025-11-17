// Stacks are also not a “first-class” data structure and should also have O(1) insertion and deletion. Because insertion and deletion occur at the same std::endl, this can be achieved with either an array or a linked list. Implement a queue class according to the following definition using a linked list as the underlying data structure; you may copy-paste and reuse any parts of your solution to Question 1 or 2. Again, for simplicity, you can make your stack store integers rather than generic data types. You will likely implement  your depth-first traversals of graphs and trees recursively; however, if you chose to do them iteratively, you would need to use a stack.

// class Stack {
//     int top() // returns the top item in the stack. O(1) time.
//     void push(int x) // adds x to the top of the stack. O(1) time.
//     int pop() // removes and returns the top item in the stack. O(1) time.
//     bool isEmpty() // returns a boolean indicating whether the stack is empty. O(1) time.
// }


//time taken:32minutes 


#include <bits/stdc++.h>

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

class Stack {
public:
    Node* head;

    Stack() {
        head = NULL;
    }

    int top() {
        if (head == NULL) {
            std::cout << "Stack is empty."<<std::endl;
            return -1;
        }
        return head->val;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (head == NULL) {
            std::cout << "Stack is empty. Nothing to pop."<<std::endl;
            return -1;
        }
        Node* temp = head;
        int popped = head->val;
        head = head->next;
        delete temp;
        return popped;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void print() {
        if (head == NULL) {
            std::cout << "Stack is empty."<<std::endl;
            return;
        }
        Node* temp = head;
        std::cout << "Stack (top to bottom): "<<std::endl;
        while (temp != NULL) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(50);

    s.print();

    std::cout << "Top: " << s.top() << std::endl;

    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;

    s.print();

    std::cout << "Top: " << s.top() << std::endl;

    while (!s.isEmpty()) {
        std::cout << "Pop: " << s.pop() << std::endl;
    }

    std::cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
