// T.C - O(n) where n is the number of nodes in the linked list
// M.C - O(1) 
// Technique Used - Fast & slow pointers

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* moveNthLastToFront(Node* head,int n){
    if(head == nullptr) return head;
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++){
        if(fast == nullptr) return head;
        fast=fast->next;
    }
    if(fast == nullptr) return head;

    while(fast->next != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    Node* target = slow->next;
    slow->next = target->next;
    target->next = head;
    head = target;
    return head;
}

void printList(Node*head){
    while(head!=nullptr){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main(){
    Node*head= new Node(15);
    head->next= new Node(2);
    head->next->next= new Node(8);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(20);
    head->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next=new Node(11);
    head->next->next->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next->next->next=new Node(19);

    printList(head);

    int k=2;
    head=moveNthLastToFront(head,k);

    printList(head);
}
