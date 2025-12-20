#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

// creates new Node with data val at front; returns head. O(1) time.
Node* insertAtFront(Node* head, int val){
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }

    return newNode;
}

// creates new Node with data val at end; returns head. O(1) time.
Node* insertAtBack(Node* head, Node* tail, int val) {
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = tail;

    if(tail != NULL){
        tail->next = newNode;
    }

    return head;
}

// creates new Node with data val after Node loc; returns head. O(1) time.
Node* insertAfter(Node* head, int val, Node* loc) {
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = loc->next;
    newNode->prev = loc;

    loc->next = newNode;
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }

    return head;
}

//  creates new Node with data val before Node loc; returns head. O(1) time.
Node* insertBefore(Node* head, int val, Node* loc) {
    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = loc;
    newNode->prev = loc->prev;

    loc->prev = newNode;
    if(newNode->prev != NULL){
        newNode->prev->next = newNode;
    } else {
        head = newNode;
    }

    return head;
}

// removes first Node; returns head. O(1) time.
Node* deleteFront(Node* head) {
    
    Node* newHead = head->next;
    newHead->prev = NULL;
    delete head;

    return newHead;
}

// removes last Node; returns head. O(1) time.
Node* deleteBack(Node* head, Node* tail) {

    if(tail == NULL || tail->prev == NULL){
        return NULL;
    }
    tail->prev->next = NULL;
    delete tail;

    return head;
}

// deletes Node loc; returns head. O(1) time.
Node* deleteNode(Node* head, Node* loc) {
    if(loc == NULL){
        return head;
    }
    if (loc->prev == NULL){
        return deleteFront(head);
    }

    if (loc->next == NULL){
        return deleteBack(head, loc);
    }

    loc->prev->next = loc->next;
    loc->next->prev = loc->prev;

    delete loc;

    return head;
}

// returns length of the list. O(n) time.
int length(Node* head) {

    int count = 0;

    while(head!= NULL){
        count++;
        head = head->next;
    }

    return count;
}

// reverses the linked list iteratively. O(n) time.
Node* reverseIterative(Node* head) {

    Node* first = NULL;
    Node* second = head;

    while(second != NULL){
        Node* temp = second->next;
        second->next = first;
        second->prev = temp;
        first = second;
        second = temp;
    }

    return first;
}

// reverses the linked list recursively (Hint: you will need a helper function.) O(n) time.
Node* reverseRecursive(Node* head) {
    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        head->prev = NULL;
        return head;
    }

    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->prev = head->next;
    head->next = NULL;

    return newHead;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    head = insertAtFront(head, 10);
    tail = head;
    cout << "After insertAtFront(10): ";
    printList(head);

    head = insertAtBack(head, tail, 20);
    tail = tail->next;
    cout << "After insertAtBack(20): ";
    printList(head);

    head = insertAtBack(head, tail, 30);
    tail = tail->next;
    cout << "After insertAtBack(30): ";
    printList(head);

    head = insertAfter(head, 25, head->next); // Insert 25 after 20
    cout << "After insertAfter(25, after 20): ";
    printList(head);

    head = insertBefore(head, 5, head); // Insert 5 before 10
    cout << "After insertBefore(5, before 10): ";
    printList(head);

    head = deleteNode(head, head->next); // Delete node with value 10
    cout << "After deleteNode(node with value 10): ";
    printList(head);

    int len = length(head); // Get length of the list
    cout << "Length of the list: " << len << endl;

    head = reverseIterative(head); // Reverse the list iteratively
    cout << "After reverseIterative: ";
    printList(head);

    head = reverseRecursive(head); // Reverse the list recursively
    cout << "After reverseRecursive: ";
    printList(head);

    return 0;
}