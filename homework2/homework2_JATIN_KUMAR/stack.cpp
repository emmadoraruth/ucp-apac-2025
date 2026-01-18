#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;

    }

};

class stack {
    private:
        Node* top;

    public:
        stack(){
            top = NULL;
        }

        int peek(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }
        // TC: O(1)

        void push(int data){
            Node* NewNode = new Node(data);
            NewNode->next = top;
            top = NewNode;
        }
        // TC: O(1) 
        void pop(){
            if(top == NULL){
                cout << "Stack is empty" << endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        // TC: O(1)
        bool isEmpty(){
            return top == NULL;
        }
        // TC: O(1)
};