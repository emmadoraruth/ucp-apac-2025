#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* dedup(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp;
    Node* tempHead = head;

    int lastval = head->data;
    Node* lastNode = head;
    head = head->next;

    while(head!=NULL){
        if(head->data == lastval){
            temp = head->next;
            delete head;
            head = temp;
            continue;
        }
        lastNode->next = head;
        lastNode = head;
        lastval = head->data;
        head = head->next;
    }
    lastNode->next = NULL;
    return tempHead;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// write a main function for testing your implementation.
int main(){
    Node* head = new Node();
    head->data = 1;
    head->next = new Node();
    head->next->data = 1;
    head->next->next = new Node();
    head->next->next->data = 2;
    head->next->next->next = new Node();
    head->next->next->next->data = 3;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 3;
    head->next->next->next->next->next = NULL;

    cout << "Original list: ";
    printList(head);

    head = dedup(head);

    cout << "Deduplicated list: ";
    printList(head);

    return 0;
}