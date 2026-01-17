// Given a doubly linked list, determine if it is a palindrome.

//time Spent:30min

//Used Doublelinked list and two pointers  [to do our task easily ]

//Time complexity:O(n) [basically O(n/2) but result in O(N) if palindrome  then all the keys traversed]
//Space complexity: O(1) [only we checked the palindrome without making any extra node]

#include <bits/stdc++.h>

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int value) {
        val = value;
        next = NULL;
        prev=NULL;
    }
};

class doublelinkedlist{
    public: 
    Node* front;
    Node* back;
    doublelinkedlist(){
        this->front=NULL;
        this->back=NULL;
    }
 
    void insert(int val) {
        Node* toadd = new Node(val);
        if (front == NULL) {
            front=toadd;
            back=toadd;
        }
        else{
            back->next=toadd;
            toadd->prev=back;
            back=back->next;
        }
    }
    bool ispalindrome(){
        Node* l=front;
        Node* r=back;
        if(l==NULL) return true;
        while(l!=r){
            if(l->val != r->val){
                return false;
            }
            else{
                l=l->next;
                r=r->prev;
            }
        }
    return true;
    }
    void print(){
        Node* temp=front;
        while(temp!=NULL){
            std::cout<<temp->val<<"  ";
            temp=temp->next;
        }
        std::cout<<std::endl;
    }
};

int main() {
   doublelinkedlist dll;

    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(30);
    dll.insert(20);
    dll.insert(10);
    
    dll.print();

    std::cout<<(dll.ispalindrome()?"The given double linked list is a palindrome . ":"The given linked list is not a palindrome . ")<<std::endl;
    

    return 0;
}