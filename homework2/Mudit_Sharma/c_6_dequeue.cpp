// Finally, dequeues (short for double-ended queues) are another “non-first-class” data 
// structure that have the features of both stacks and queues: O(1) insertion and deletion 
// at both ends. Implement a deque class according to the following definition; you may copy-paste
//  and reuse any parts of your solution to Question 1 or 2. As usual, for simplicity, you can 
//  make your dequeue store integers rather than generic data types. 

// class Deque {
//     int frontnode() // returns the first item in the deque. O(1) time.
//     int backnode() // returns the last item in the deque. O(1) time.
//     void pushBack(int x) // adds x to the backnode of the deque. O(1) time.
//     void pushFront(int x) // adds x to the frontnode of the deque. O(1) time.
//     int popFront() // removes and returns the first item in the deque. O(1) time.
//     int popBack() // removes and returns the last item in the deque. O(1) time.
//     bool isEmpty() // returns a boolean indicating whether the deque is empty. O(1) time.
// }


//3:56-4:30
//time spent : 34minutes
#include<bits/stdc++.h>

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int v){
        this->val=v;
        next=NULL;
        prev=NULL;
    }
};
class Deque{
    public:
    Node* frontnode;
    Node* backnode;
   
    Deque(){
        frontnode=NULL;
        backnode=NULL;
    }   
    int front(){
       if(frontnode==NULL){
         std::cout<<"Deque is  empty : ";
         return -1;
       }
       else{
        std::cout<<"Front Node is : ";
        return frontnode->val;
       }
       return 0;
    }
    int back(){
        if(backnode==NULL){
            std::cout<<"Deque is empty : ";
            return -1;
        }
        else{
            std::cout<<"Back Node is : ";
            return backnode->val;
        }
        return 0;
    }
    void pushback(int x){
        Node* toadd=new Node(x);
        if(backnode==NULL){
           frontnode=toadd;
           backnode=toadd;
           return ;
        }
        else{ //backnode is not null
            backnode->next=toadd;
            toadd->prev=backnode;
            backnode=toadd;
            return;
        }
    }
    void pushfront(int x){
        Node* toadd=new Node(x);
        if(frontnode==NULL){
            frontnode=toadd;
            backnode=toadd;
            return;
        }
        else{
            toadd->next=frontnode;
            frontnode->prev=toadd;
            frontnode=toadd;
        }
    }
    int popfront(){
         if(frontnode==NULL){
            std::cout<<"Deque is empty . :  ";
            return -1;
         }
         else{
            int fval=frontnode->val;
            Node* temp=frontnode;
            frontnode = frontnode->next;
            if(frontnode == NULL) backnode = NULL;
            else frontnode->prev = NULL;
            delete temp;
            return fval;
         }
        return 0;
    }
    int popback(){
        if(backnode==NULL){
            std::cout<<"Deque is empty : ";
            return -1;
        }
        else{
            int bval=backnode->val;
            Node* temp=backnode;
           backnode = backnode->prev;
           if(backnode == NULL) frontnode = NULL;
           else backnode->next = NULL;
            delete temp;
            return bval;
         }
        return 0;
    }
    bool isempty(){
        if(frontnode == NULL){
            return true;
        }
        return false;
    }
    void print(){
        Node* curr=frontnode;
        std::cout<<" Printing the dequeue "<<std::endl;
        while(curr!= NULL){
            std::cout<<curr->val<<"   ";
            curr=curr->next;
        }
        std::cout<<std::endl;
    }
};
int main(){
    Deque dq;
    dq.print();
    dq.pushfront(5);
    dq.pushfront(6);
    dq.pushfront(7);
    dq.pushback(8);
    dq.pushback(9);
    dq.pushback(10);
    dq.pushback(11);

    dq.print();
    std::cout<<dq.front();
     std::cout<<std::endl;
    std::cout<<dq.back();
     std::cout<<std::endl;

    std::cout<<" popback: " << dq.popback();
     std::cout<<std::endl;
    std::cout<<" popback: " << dq.popback();
     std::cout<<std::endl;
    std::cout<<" popfront: " << dq.popfront();
     std::cout<<std::endl;
    std::cout<<" popfront: " << dq.popfront();
     std::cout<<std::endl;

    dq.print();
    std::cout<<dq.front();
     std::cout<<std::endl;
    std::cout<<dq.back();
     std::cout<<std::endl;
}


