#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        this->data=0;
        this->next=NULL;
        this->prev=NULL;
        
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;

    }
};

    Node* insertAtFront(Node* head, int data) {
        Node* NewNode = new Node(data);
        if (head == nullptr) {
            return NewNode;
        }
        NewNode->next = head;
        head->prev = NewNode;
        return NewNode;
    } // TC: O(1)
    Node* insertAtEnd(Node* head, int data) {
        Node* NewNode = new Node(data);
        if (head == nullptr) {
            return NewNode;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = NewNode;
        NewNode->prev = temp;
        return head;
    } // TC: O(n)
    Node* insertAfter(Node* head, int val, Node* loc){
        if (loc == nullptr) return head;

        Node* NewNode = new Node(val);
        NewNode->next = loc->next;
        NewNode->prev = loc;
        if (loc->next != nullptr) {
            loc->next->prev = NewNode;
        }
        loc->next = NewNode;

        return head;
    } // TC: O(1)
    Node* deleteFront(Node* head){
        if (head == nullptr) return head;

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }; // TC: O(1)

    Node* deleteBack(Node* head){
        if (head == nullptr || head->next == nullptr) {
            if (head != nullptr) delete head;
            return nullptr; 
        }

        Node* temp = head; 

        while (temp->next != nullptr) {
            temp = temp->next; 
        }

        Node* del = temp;
        temp->prev->next = nullptr;
        delete del;

        return head;
}; // TC: O(1)

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
}; // TC: O(1)
int length(Node* head) {
    int count = 0;
    Node* temp = head;

    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}; // TC: O(n)
Node* reverseIterative(Node* head){
    Node* curr = head;
    Node* temp = nullptr;

    while(curr != nullptr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp != nullptr){
        head = temp->prev;
    }

    return head;
}; // TC: O(n)
Node* reverseRecursive(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;

    Node* newHead = reverseRecursive(head->next);

    head->next->prev = head;
    head->prev = head->next;
    head->next = nullptr;

    return newHead;
}; // TC: O(n)


int main() {
    return 0;
}
