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

// Insert at the front (O(1))
Node* insertAtFront(Node* head, int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

// Insert at the back (O(n))
Node* insertAtBack(Node* head, int val) {
    Node* newNode = createNode(val);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert after a given node (O(1))
Node* insertAfter(Node* head, int val, Node* loc) {
    if (!loc) return head;
    Node* newNode = createNode(val);
    newNode->next = loc->next;
    newNode->prev = loc;
    if (loc->next) loc->next->prev = newNode;
    loc->next = newNode;
    return head;
}

// Insert before a given node (O(1))
Node* insertBefore(Node* head, int val, Node* loc) {
    if (!loc) return head;
    if (loc == head) return insertAtFront(head, val);
    
    Node* newNode = createNode(val);
    newNode->prev = loc->prev;
    newNode->next = loc;
    loc->prev->next = newNode;
    loc->prev = newNode;
    return head;
}

// Delete front node (O(1))
Node* deleteFront(Node* head) {
    if (!head) return nullptr;
    
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
    return head;
}

// Delete last node (O(n))
Node* deleteBack(Node* head) {
    if (!head) return nullptr;
    if (!head->next) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
    return head;
}

// Delete node (O(1))
Node* deleteNode(Node* head, Node* loc) {
    if (!head || !loc) return head;
    if (loc == head) return deleteFront(head);

    if (loc->next) loc->next->prev = loc->prev;
    if (loc->prev) loc->prev->next = loc->next;
    delete loc;
    return head;
}

// Length of the list (O(n))
int length(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Reverse iteratively (O(n))
Node* reverseIterative(Node* head) {
    Node* curr = head;
    Node* newHead = nullptr;
    
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = curr->prev;
        curr->prev = nextNode;
        newHead = curr;
        curr = nextNode;
    }
    
    return newHead;
}

Node* reverseRecursiveHelper(Node* head, Node* prev) {
    if (!head) return prev;
    
    Node* nextNode = head->next;
    head->next = prev;
    head->prev = nextNode;
    
    return reverseRecursiveHelper(nextNode, head);
}

// Reverse recursively (O(n))
Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
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
