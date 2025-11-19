#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class dequeue
{
private:
    Node *front;
    Node *rear;

public:
    dequeue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    } // TC: O(1)

    int front()
    {
        if (front == NULL)
        {
            cout << "Dequeue is empty" << endl;
            return -1;
        }
        return front->data;
    } // TC: O(1)

    int back()
    {
        if (rear == NULL)
        {
            cout << "Dequeue is empty" << endl;
            return -1;
        }
        return rear->data;
    } // TC: O(1)

    void pushFront(int data)
    {
        Node *NewNode = new Node(data);
        if (front == NULL)
        {
            front = NewNode;
            rear = NewNode;
            return;
        }
        NewNode->next = front;
        front->prev = NewNode;
        front = NewNode;
    } // TC: O(1)

    void pushBack(int data)
    {
        Node *NewNode = new Node(data);
        if (rear == NULL)
        {
            front = NewNode;
            rear = NewNode;
            return;
        }
        rear->next = NewNode;
        NewNode->prev = rear;
        rear = NewNode;
    } // TC: O(1)

    int popFront() {
        if (front == NULL) {
            cout << "Dequeue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        int val = front->data;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL; 
        }
        delete temp;
        return val;
    }

    int popBack() {
        if (rear == NULL) {
            cout << "Dequeue is empty" << endl;
            return -1;
        }
        Node* temp = rear;
        int val = rear->data;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL; 
        }
        delete temp;
        return val;
    } // TC: O(1)

    
        
};

int main(){
    return 0;
}