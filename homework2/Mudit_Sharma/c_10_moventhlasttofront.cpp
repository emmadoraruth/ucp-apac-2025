// Given a singly linked list, move the nth from the last element to the front of the list.

//time spent:20 min


//Time complexity: O(n)  [while calculating the length of the linked list]
//Space complexity:O(1)   [Done in constant space only next pointer is manupalated]

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

    void insert(int val) {
        Node* toadd = new Node(val);
        toadd->next=head;
        head=toadd;
   }
   int length(){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
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
   void move_nth_to_front(int n){
    int l=this->length();
    if(n>l){
        std::cout<<"Not Possible to move . "<<std::endl;
        return;
    }
    else{
        // 1 2 3 4 5 6 7   n=3 from last means 7-3+1 from start
        n=l-n;
        Node* temp=head;
        Node* prev=NULL;
        while(n>0){
            prev=temp;
            temp=temp->next;
            n--;
        }
        prev->next=temp->next;
        temp->next=head;
        head=temp;
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
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(5);
    ll.insert(8);
    ll.insert(9);
    ll.insert(7);
    ll.reverse();
    std::cout<<"The Original Linked List is : ";
    ll.print();
    ll.move_nth_to_front(4);
    std::cout<<"The Modified Linked List is : ";
    ll.print();

}