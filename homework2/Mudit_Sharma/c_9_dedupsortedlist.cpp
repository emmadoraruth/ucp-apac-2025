// Given a sorted singly linked list, remove any duplicates so that no value appears more than once.

//time spent :18 min


//Time complexity: O(n)  [we traversed one time]
//Space complexity:O(1)


#include <bits/stdc++.h>

class Node{
    public: 
    int val;
    Node* next;

    Node(int v){
        this->val=v;
        this->next=NULL;
    }
};
class linkedlist{
    public:
    Node* head;

    linkedlist(){
        head=NULL;
    }

    void reverse(){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head=prev;
    }
    void insert(int val) {
        Node* toadd = new Node(val);
        toadd->next=head;
        head=toadd;
   }
   void dedup(){
    Node* temp=head;
    while(temp!=NULL){
        int currval=temp->val;
        Node* currnode=temp;
        while(temp!=NULL && temp->val==currval){
             temp=temp->next;
        }
      currnode->next=temp;  
    }
   }
   void print(){
    Node* temp=head;
    while(temp!=NULL){
        std::cout<<temp->val<<"  ";
        temp=temp->next;
    }
    std::cout<<std::endl;
   }


};
int main(){
    linkedlist ll;
    ll.insert(1);
    ll.insert(1);
    ll.insert(2);
    ll.insert(2);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(4);
    ll.insert(4);
    ll.insert(5);
    ll.reverse();
    std::cout<<"The Original Linked List is : ";
    ll.print();
    ll.dedup();
    std::cout<<"The Deduped Linked List is : ";
    ll.print();

}