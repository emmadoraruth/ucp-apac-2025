#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// typedef Node* Node;

Node* insertAtFront(Node* head, int val){
    // create memory space for new node
    Node* newNode = new Node();

    // put the value inside it
    newNode->data = val;

    // Inserting at the front
    newNode->next = head;

    return newNode;
}

Node* insertAtBack(Node* head, int val){
    // create memory space for new node
    Node* newNode = new Node();

    // put the value inside it
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        // Inserting at the back when list is empty
        return newNode;
    }

    Node* temp = head;

    // Inserting at the back
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// creates new Node* with data val after Node* loc; returns head. O(1) time.
Node* insertAfter(Node* head, int val, Node* loc){
    if(loc == NULL){
        return head;
    }

    // create memory space for new node
    Node* newNode = new Node();

    // put the value inside it
    newNode->data = val;

    // Inserting after loc
    newNode->next = loc->next;
    loc->next = newNode;

    return head;
}

// creates new Node* with data val before Node* loc; returns head. O(n) time
Node* insertBefore(Node* head, int val, Node* loc){
    if(head == NULL){
        return head;
    }

    Node* temp = head;

    while(head->next != loc){
        head = head->next;
    }

    Node* newNode = new Node();
    newNode->data = val;
    head->next = newNode;
    newNode->next = loc;

    return temp;
}

// removes first Node; returns head. O(1) time.
Node* deleteFront(Node* head) {
    Node* temp = head->next;
    delete head;

    return temp;
}

// removes last Node; returns head. O(n) time.
Node* deleteBack(Node* head) {
    Node* temp = head;
    if(head == NULL){
        return head;
    }

    Node* second = head->next;
    while(second->next !=NULL){
        head = head->next;
        second = second->next;
    }
    head->next = NULL;
    delete second;

    return temp;
}

// deletes Node* loc; returns head. O(n) time.
Node* deleteNode(Node* head, Node* loc) {
    if(head == NULL || loc == NULL){
        return head;
    }

    if(head == loc){
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* temp = head;

    while(head->next != loc){
        head = head->next;
    }
    head->next = loc->next;
    delete loc;

    return temp;
}

// returns length of the list. O(n) time.
int length(Node* head) {
    int count = 0;

    while(head!=NULL){
        count++;
        head= head->next;
    }

    return count;
}

// reverses the linked list iteratively. O(n) time.
Node* reverseIterative(Node* head) {

    if(head == NULL){
        return head;
    }
    Node* first = NULL;
    Node* second = head;

    while(second != NULL){
        Node* temp = second->next;
        second->next = first;
        first = second;
        second = temp;
    }

    return first;
}

// reverses the linked list recursively (Hint: you will need a helper function.) O(n) time.
Node* reverseRecursive(Node* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main(){
    Node* head = NULL;

    head = insertAtBack(head, 10);
    head = insertAtBack(head, 20);
    head = insertAtBack(head, 30);
    head = insertAtFront(head, 5);

    printList(head);
    head = reverseIterative(head);
    printList(head);

    head = reverseRecursive(head);
    printList(head);
}
