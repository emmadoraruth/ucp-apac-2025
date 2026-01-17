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

// Insert at the front (O(1))
Node* insertAtFront(Node* head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

// Insert at the back (O(n))
Node* insertAtBack(Node* head, int val) {
    Node* newNode = createNode(val);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Insert after a given node (O(1))
Node* insertAfter(Node* head, int val, Node* loc) {
    if (!loc) return head;
    
    Node* newNode = createNode(val);
    newNode->next = loc->next;
    loc->next = newNode;
    return head;
}

// Insert before a given node (O(n))
Node* insertBefore(Node* head, int val, Node* loc) {
    if (!loc) return head;
    
    if (head == loc) {
        return insertAtFront(head, val);
    }

    Node* temp = head;
    while (temp && temp->next != loc) {
        temp = temp->next;
    }
    if (temp) {
        Node* newNode = createNode(val);
        newNode->next = loc;
        temp->next = newNode;
    }
    return head;
}

// Delete front node (O(1))
Node* deleteFront(Node* head) {
    if (!head) return nullptr;
    
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete last node (O(n))
Node* deleteBack(Node* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Delete specific node (O(n))
Node* deleteNode(Node* head, Node* loc) {
    if (!head || !loc) return head;

    if (head == loc) {
        return deleteFront(head);
    }

    Node* temp = head;
    while (temp->next && temp->next != loc) {
        temp = temp->next;
    }

    if (temp->next) {
        temp->next = loc->next;
        delete loc;
    }
    return head;
}

// Get length of the list (O(n))
int length(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Reverse linked list iteratively (O(n))
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


Node* reverseRecursiveHelper(Node* head, Node* prev) {
    if (!head) return prev;
    
    Node* nextNode = head->next;
    head->next = prev;
    return reverseRecursiveHelper(nextNode, head);
}

// Reverse linked list recursively (O(n))
Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    
    printList(head);

    cout << length(head) << endl;
    
    head = reverseIterative(head);
    printList(head);
    
    head = reverseRecursive(head);
    printList(head);
    
    return 0;
}
