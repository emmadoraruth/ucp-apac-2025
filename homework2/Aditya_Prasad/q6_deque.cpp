// Time taken : 11 mins

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque{
private:
    Node* head;
    Node* tail;

public:
    Deque(){
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty(){
        return head==nullptr;
    }

    int front(){
        return head->data;
    }

    int back(){
        return tail->data;
    }

    void pushFront(int x){
        Node* newNode=new Node(x);
        if(isEmpty() == true){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head =newNode;
    }

    void pushBack(int x){
        Node* newNode= new Node(x);
        if(isEmpty()){
            head = tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next=newNode;
        tail = newNode;
    }

    int popFront(){
        Node*temp=head;
        int val=temp->data;
        head=head->next;
        if(head==nullptr) tail=nullptr;
        else head->prev=nullptr;
        delete temp;
        return val;
    }

    int popBack(){
        
        Node*temp = tail;
        int val=temp->data;
        tail = tail->prev;
        if(tail == nullptr) head = nullptr;
        else tail->next=nullptr;
        delete temp;
        return val;
    }
};

int main(){
    return 0;
}
