#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class Deque{
private:
    Node* head;
    Node* tail;

    public:
    Deque(){
        head= NULL;
        tail= NULL;
    }

    // returns the first item in the deque. O(1) time.
    int front(){
        if(head== NULL){
            return -1;
        }
        return head->data;
    }

    // returns the last item in the deque. O(1) time.
    int back(){
        if(tail == NULL){
            return -1;
        }
        return tail->data;
    }

    // adds x to the back of the deque. O(1) time.
    void pushBack(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = tail;

        if(tail == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // adds x to the front of the deque. O(1) time.
    void pushFront(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        newNode->prev = NULL;

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            head->prev = newNode;
            head = newNode;
            }
    }

    // removes and returns the first item in the deque. O(1) time.
    int popFront(){
        if(head == NULL){
            return -1;
        }

        int val = head->data;
        Node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }

        delete temp;
        return val;
    }

    // removes and returns the last item in the deque. O(1) time.
    int popBack(){
        if(tail == NULL){
            return -1;
        }

        int val =tail->data;
        Node* temp = tail;
        tail = tail->prev;

        if(tail == NULL){
            head = NULL;
            }
        else{
            tail->next = NULL;
        }

        delete temp;
        return val;
    }

    // returns a boolean indicating whether the deque is empty. O(1) time.
    bool isEmpty(){
        return head == NULL;
        }
};
