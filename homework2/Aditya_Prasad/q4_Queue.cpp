// Time taken : 14 mins

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    int peek(){
        return front->data;

    } // returns the first item in the queue. O(1) time.

    void enqueue(int x){
        Node* newNode = new Node(x);

        if(rear == nullptr){
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }// adds x to the back of the queue. O(1) time.


    int dequeue(){
        Node* newNode = front;
        int ans = newNode->data;

        front = front->next;

        if(front == nullptr){
            rear = nullptr;
        
        }
        
        delete newNode;
        return ans;
    }// removes and returns the first item in the queue. O(1) time.

    bool isEmpty(){
        if(front == nullptr) return true;
        else return false;
    } // returns a boolean indicating whether the queue is empty. O(1) time.
};

int main(){
    return 0;
}