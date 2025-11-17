// Time Complexity: 
// insertAtFront: O(1)
// insertAtBack: O(1)
// insertAfter: O(1)
// insertBefore: O(1)
// deleteFront: O(1)
// deleteBack: O(1)
// deleteNode: O(1)
// length: O(n)
// reverseIterative: O(n)
// reverseRecursive: O(n)

// Space Complexity: O(1) for all (ignoring recursion stack for reverseRecursive)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

Node* insertAtFront(Node* head, int value) {
    Node* newNode = new Node(value);
    if (!head) return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

Node* insertAtBack(Node* head, Node* tail, int value) {
    Node* newNode = new Node(value);
    if (!head) return newNode;
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

Node* insertAfter(Node* head, int value, Node* location) {
    if (!location) return head;
    Node* newNode = new Node(value);
    Node* nextNode = location->next;
    newNode->next = nextNode;
    newNode->prev = location;
    location->next = newNode;
    if (nextNode) nextNode->prev = newNode;
    return head;
}

Node* insertBefore(Node* head, int value, Node* location) {
    if (!location) return head;
    if (location->prev == nullptr) return insertAtFront(head, value);
    Node* previousNode = location->prev;
    Node* newNode = new Node(value);
    newNode->next = location;
    newNode->prev = previousNode;
    previousNode->next = newNode;
    location->prev = newNode;
    return head;
}

Node* deleteFront(Node* head) {
    if (!head) return nullptr;
    Node* nextNode = head->next;
    delete head;
    if (nextNode) nextNode->prev = nullptr;
    return nextNode;
}

Node* deleteBack(Node* head, Node* tail) {
    if (!head) return nullptr;
    if (!tail->prev) {
        delete tail;
        return nullptr;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    return head;
}

Node* deleteNode(Node* head, Node* location) {
    if (!head || !location) return head;
    if (!location->prev) return deleteFront(head);
    if (!location->next) return deleteBack(head, location);
    Node* previousNode = location->prev;
    Node* nextNode = location->next;
    previousNode->next = nextNode;
    nextNode->prev = previousNode;
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
    Node* current = head;
    Node* newHead = nullptr;
    while (current) {
        Node* nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        newHead = current;
        current = nextNode;
    }
    return newHead;
}

Node* reverseRecursiveHelper(Node* current, Node* previous) {
    if (!current) return previous;
    Node* nextNode = current->next;
    current->next = previous;
    current->prev = nextNode;
    return reverseRecursiveHelper(nextNode, current);
}

Node* reverseRecursive(Node* head) {
    return reverseRecursiveHelper(head, nullptr);
}

void printForward(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    head = insertAtFront(head, 2);
    head = insertAtFront(head, 1);

    tail = head;
    while (tail && tail->next) tail = tail->next;

    head = insertAtBack(head, tail, 3);
    tail = tail->next;

    head = insertAtBack(head, tail, 4);
    tail = tail->next;

    printForward(head);

    head = reverseIterative(head);
    printForward(head);

    head = reverseRecursive(head);
    printForward(head);

    cout << length(head) << "\n";

    return 0;
}
