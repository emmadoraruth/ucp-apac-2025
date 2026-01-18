// Time Taken : 20 mins

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* insertAtFront(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head==nullptr) 
        return newNode;

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node* insertAtBack(Node* head, int val) {
    Node* newNode = new Node(val);

    if(head == nullptr)
        return newNode;

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* insertAfter(Node* head, int val, Node* loc) {
    if(head == nullptr || loc == nullptr)
        return head;

    Node* newNode = new Node(val);

    newNode->next = loc->next;
    newNode->prev = loc;

    if(loc->next != nullptr) loc->next->prev = newNode;

    loc->next = newNode;

    return head;
}

Node* deleteFront(Node* head) {
    if(head == nullptr)
        return nullptr;

    Node* nextNode = head->next;

    if(nextNode != nullptr) nextNode->prev = nullptr;

    delete head;
    return nextNode;
}

Node* deleteBack(Node* head) {
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
    return head;
}

Node* deleteNode(Node* head, Node* loc) {
    if(head == nullptr || loc == nullptr)
        return head;

    if(loc == head)
        return deleteFront(head);

    if(loc->next != nullptr)
        loc->next->prev = loc->prev;

    if(loc->prev != nullptr)
        loc->prev->next = loc->next;

    delete loc;
    return head;
}

int length(Node* head) {
    int count = 0;
    Node* temp = head;

    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

Node* reverseIterative(Node* head) {
    Node* curr = head;
    Node* prevNode = nullptr;

    while(curr != nullptr) {
        Node* nextNode = curr->next;

        curr->next = prevNode;
        curr->prev = nextNode;

        prevNode = curr;
        curr = nextNode;
    }
    return prevNode;
}

Node* reverseRecursive(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* newHead = reverseRecursive(head->next);

    head->next->prev = head;
    head->prev = head->next;
    head->next = nullptr;

    return newHead;
}


int main(){
	return 0;
}