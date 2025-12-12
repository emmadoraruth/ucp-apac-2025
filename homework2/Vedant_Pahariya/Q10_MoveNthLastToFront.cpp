#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* move(Node* head, int pos){
    Node* first = head;
    Node* temphead = head;

    while(pos != 0){
        head = head->next;
        if(head == NULL){
            return NULL;
            // this means linkedlist is not of sufficient length
        }
        pos--;
    }

    Node* second = head;

    while(second->next != NULL){
        first = first->next;
        second = second->next;
    }

    // deleting the nth last
    Node* temp = first->next->next;
    int val = first->next->data;
    delete first->next;
    first->next = temp;

    // inserting in the front
    Node* newhead = new Node();
    newhead->next = temphead;
    newhead->data = val;

    return newhead;
}

// My starting idea was to find the total length of the linkedlist by a for loop iterating the whole linkedlist but that is not good idea because linkedlist can be very long and iterative the whole linkedlist twice is not good. 
// Then, the idea of two pointers stike by which we can have a gap of pos between these two pointers and check if the last is reaching the end (NULL). This way we can get the work done by iterating only once.

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// write main function to test the implementation
int main(){
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = new Node();
    head->next->next->data = 30;
    head->next->next->next = new Node();
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    cout << "Original list: ";
    printList(head);

    int pos = 2; // Move the 2nd last node to front
    head = move(head, pos);

    cout << "Modified list: ";
    printList(head);

    return 0;
}