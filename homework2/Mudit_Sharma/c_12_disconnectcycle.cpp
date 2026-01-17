// Given a singly linked list, disconnect the cycle, if one exists.


//one way-by using a map which is named as a visited  sc=O(n)
//second way-by using solw and fast pointer           sc=O(1)


//Time spent : 42 min


//Time complexity:  O(n) [in both solutions]
//Space complexity: O(n) [in 1st approach as hash map is used]   
//                  O(1)[in 2nd approach as some mathematics manupalations are used]

#include<bits/stdc++.h>

class Node {
public:
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = NULL;
    }
};

class linkedlist {
public:
    Node* head;

    linkedlist() {
        head = NULL;
    }

    void insert(int v) {
        Node* toadd = new Node(v);

        if (head == NULL) {
            head = toadd;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = toadd;
    }
};

// make a cycle by connecting last node to value node
void makeconnect(int val, Node* head) {
    Node* end = NULL;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->val == val) {
            end = temp;
        }
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = end;
}

// remove cycle
void disconnect(Node* head) {
    std::unordered_map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->next && visited[temp->next] == true) {
            temp->next = NULL;
            return;
        }
        visited[temp] = true;
        temp = temp->next;
    }
}
bool cyclepresent(Node*& slow,Node*& fast){
     while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;              //move slow at one speed
        if(fast!=NULL){               //move fast at two speed
            fast=fast->next;
        }
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void disconnect2(Node* head){
     Node* slow=head;
    Node* fast=head;
    bool cycle=cyclepresent(slow,fast);
    if(!cycle){
        std::cout<<"No Cycle present .  ";
    }
    else{
        while(slow->next!=fast->next){         //now move slow and fast with one speed 
           slow=slow->next;                    //And Both will meet at common point
           fast=fast->next;
        }
    }
    fast->next=NULL;

}
// print with cycle detection
void print(Node* head) {
    std::unordered_map<Node*, bool> visited;
    Node* temp = head;

    while (temp != NULL) {
        if (visited[temp]) {
            std::cout << "(cycle back to " << temp->val << ")";
            break;
        }
        std::cout << temp->val << " -> ";
        visited[temp] = true;
        temp = temp->next;
        if(temp==NULL){
            std::cout<<" X ";
        }
    }
    std::cout << std::endl;
}

int main() {
    linkedlist ll;
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);

    // create cycle: connect last node to node with value 3
    makeconnect(3, ll.head);

    //Method 1
    std::cout << "List with cycle: ";
    print(ll.head);

    disconnect(ll.head);

    std::cout<<std::endl;
    std::cout << "After removing cycle: ";
    print(ll.head);
    

    //Method 2
    std::cout<<"----------------------------------------------------------";
     // create cycle: connect last node to node with value 3
    makeconnect(3, ll.head);
    disconnect2(ll.head);

     std::cout << "List with cycle: ";
    print(ll.head);

    std::cout << "After removing cycle by method 2: ";
    print(ll.head);

}