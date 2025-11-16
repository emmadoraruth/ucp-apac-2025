// Time taken : 10 mins

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

class Stack {
private:
    Node* front;

public:
    Stack(){
        front = nullptr;
    }
    int top(){
        return front->data;
    } // returns the top item in the stack. O(1) time.
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = front;
        front = newNode;
    } // adds x to the top of the stack. O(1) time.
    int pop(){
        Node* temp = front;
        int topVal = front->data;
        front = front->next;
        delete temp;
        return topVal;
    }// removes and returns the top item in the stack. O(1) time.
    bool isEmpty(){
        if(front == nullptr) return true;
        else return false;
    }// returns a boolean indicating whether the stack is empty. O(1) time.
}; 


int main(){
    return 0;
}