// TC: O(n)
// SC: O(1)


#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(){
        this->data=0;
        this->next=NULL;
        
    }

    Node(int data){
        this->data=data;
        this->next=NULL;

    }
};

void InsertAtHead(Node* &head, Node* &tail, int data){
    // check for empty LL
    if(head==NULL){
        Node* NewNode=new Node(data);
        head = NewNode;
        tail = NewNode;
    }

   else{
    Node* NewNode=new Node(data);
    NewNode->next=head;
    head=NewNode;
   }
    
} // TC: O(1)
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* NewNode = new Node(data);
                head = NewNode;
                tail = NewNode;
                
        }
        else {
            Node* NewNode = new Node(data);
            tail->next = NewNode;
            tail = NewNode;
        }

} // TC: O(1)

void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
} // TC: O(n)

Node* disconnectCycle(Node* head) {
    if (head == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle using Floyd's  algorithm
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break; // Cycle detected
        }
    }

    // If no cycle is detected, return the original head
    if (fast == nullptr || fast->next == nullptr) {
        return head;
    }

    // Find the start of the cycle
    slow = head;
    Node* prev = nullptr; // To keep track of the node before the meeting point
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Disconnect the cycle
    if (prev != nullptr) {
        prev->next = nullptr;
    }

    return head;
} // TC: O(n)

int main(){
    Node *head=NULL;
    Node* tail=NULL;
    // list   10 → 18 → 12 → 9 → 11 → 4

    insertAtTail(head,tail,10);
    insertAtTail(head,tail,18); 
    insertAtTail(head,tail,12);
    insertAtTail(head,tail,9);
    insertAtTail(head,tail,11);
    insertAtTail(head,tail,4);

    // Creating a cycle for testing: connecting tail to the node with value 12
    tail->next = head->next->next; // 4 → 12
    head = disconnectCycle(head);
    print(head); // tc: O(n)
}