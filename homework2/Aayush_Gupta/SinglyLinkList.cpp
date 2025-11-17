// Time Complexity: 
// insertAtFront: O(1)
// insertAtBack: O(n)
// insertAfter: O(1)
// insertBefore: O(n)
// deleteFront: O(1)
// deleteBack: O(n)
// deleteNode: O(n)
// length: O(n)
// reverseIterative: O(n)
// reverseRecursive: O(n)

// Space Complexity: O(1) for all (ignoring recursion stack for reverseRecursive)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* insertAtFront(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

Node* insertAtBack(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) return newNode;
    Node* current = head;
    while (current->next) current = current->next;
    current->next = newNode;
    return head;
}

Node* insertAfter(Node* head, int value, Node* location) {
    if (!location) return head;
    Node* newNode = new Node(value);
    newNode->next = location->next;
    location->next = newNode;
    return head;
}

Node* insertBefore(Node* head, int value, Node* location) {
    if (!location) return head;
    if (head == location) return insertAtFront(head, value);
    Node* current = head;
    while (current && current->next != location) current = current->next;
    if (!current) return head;
    Node* newNode = new Node(value);
    newNode->next = location;
    current->next = newNode;
    return head;
}

Node* deleteFront(Node* head) {
    if (!head) return nullptr;
    Node* nextNode = head->next;
    delete head;
    return nextNode;
}

Node* deleteBack(Node* head) {
    if (!head) return nullptr;
    if (!head->next) {
        delete head;
        return nullptr;
    }
    Node* current = head;
    while (current->next->next) current = current->next;
    delete current->next;
    current->next = nullptr;
    return head;
}

Node* deleteNode(Node* head, Node* location) {
    if (!head || !location) return head;
    if (head == location) return deleteFront(head);
    Node* current = head;
    while (current && current->next != location) current = current->next;
    if (!current) return head;
    current->next = location->next;
    delete location;
    return head;
}

int length(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

Node* reverseIterative(Node* head) {
    Node* previous = nullptr;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    return previous;
}

Node* reverseRecursiveHelper(Node* current, Node* previous) {
    if (!current) return previous;
    Node* nextNode = current->next;
    current->next = previous;
    return reverseRecursiveHelper(nextNode, current);
}

Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;

    head = insertAtFront(head, 3);
    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);

    printList(head);

    head = reverseIterative(head);
    printList(head);

    head = reverseRecursive(head);
    printList(head);

    cout << length(head) <<endl;

    return 0;
}
