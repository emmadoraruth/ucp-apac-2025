#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
private:
    Node* head;
    Node* tail;

    public:
    Queue(){
        head = NULL;
        tail= NULL;
    }

    // returns the first item in the queue. O(1) time.
    int peek(){
        if(head== NULL){
            return -1;
        }
        return head->data;
    }

    // adds x to the back of the queue. O(1) time.
    void enqueue(int x){
        Node* newNode =new Node();
        newNode->data = x;
        newNode->next = NULL;

        if(tail== NULL){
            head= tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    // removes and returns the first item in the queue. O(1) time.
    int dequeue(){
        if(head == NULL){
            throw runtime_error("Queue is empty");
        }

        int val = head->data;
        Node* temp = head;
        head = head->next;

        if(head == NULL){
            tail = NULL;
            }

        delete temp;
        return val;
    }

    // returns a boolean indicating whether the queue is empty. O(1) time.
    bool isEmpty(){
        return head == NULL;
     }
};