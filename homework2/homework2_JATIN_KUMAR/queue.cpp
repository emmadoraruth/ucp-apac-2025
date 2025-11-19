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

class Queue{
    private:
        Node* front;
        Node* rear;

        public:
        Queue(){    
            front = NULL;
            rear = NULL;    
        }

        int peek(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }
        // TC: O(1)
        void enqueue(int data){
            Node* NewNode = new Node(data);
            if(rear == NULL){
                front = NewNode;
                rear = NewNode;
                return;
            }
            rear->next = NewNode;
            rear = NewNode;
        }
        // TC: O(1)
        void dequeue(){
            if(front == NULL){
                cout << "Queue is empty" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            delete temp;
        }
        // TC: O(1)
        bool isEmpty(){
            return front == NULL;
        }
        // TC: O(1)
};

int main(){
    return 0;
}