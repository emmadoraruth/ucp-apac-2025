// Given a doubly linked list, determine if it is a palindrome.

// Technique used: Two-pointer technique (iterative) and Recursion
// Time Complexity: O(n) where n is the number of nodes in the list, it is actually O(n/2) but we drop the constant factor
// Space Complexity: O(1) for iterative approach, O(n) for recursive approach due to recursion stack

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

bool ispalinrecur(Node* head, Node* tail){

    if(tail->next == head || tail == head){
        return true;
    }

    bool condition = false;
    if(head->data == tail->data){
        condition = true;
    }

    return ispalinrecur(head->next, tail->prev) && condition;
}

bool ispalin(Node* head, Node* tail){
    while(head != NULL && tail != NULL){
        if(head->data != tail->data){
            return false;
        }
        if(head == tail || head->next == tail){
            break;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    Node* head = new Node();
    head->data = 1;
    head->prev = NULL;  // Add this
    head->next = new Node();
    
    head->next->data = 2;
    head->next->prev = head;  // Add this
    head->next->next = new Node();
    
    head->next->next->data = 2;
    head->next->next->prev = head->next;  // Add this
    head->next->next->next = new Node();
    
    head->next->next->next->data = 1;
    head->next->next->next->prev = head->next->next;  // Add this
    head->next->next->next->next = NULL;

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    cout << ispalinrecur(head, tail) << "\n"; // should return true

    head->next->data = 3; // change second element to break palindrome

    cout << ispalin(head, tail) << "\n"; // should return false

    return 0;
}