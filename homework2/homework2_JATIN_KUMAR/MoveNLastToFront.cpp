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
Node* insertAfter(Node* head, int val, Node* loc){
	if(loc == nullptr) return head;

	Node* NewNode = new Node(val);
	NewNode->next = loc->next;
	loc->next = NewNode;

	return head;
} // TC: O(1)

Node* deleteFront(Node* head){
	if(head == nullptr) return head;

	Node* temp = head->next;
	delete head;
	return temp;
} // TC: O(1)
Node* deleteBack(Node* head){
	if(head == nullptr || head->next == nullptr){
		if(head != nullptr) delete head;
		return nullptr; 
	}

	Node* temp = head; 

	while(temp->next->next != nullptr){
		temp = temp->next; 
	}

	Node* del = temp->next;
	temp->next = nullptr;
	delete del;

	return head;
} // TC: O(n)

Node* deleteNode(Node* head, Node* loc){
	if(head == nullptr || loc == nullptr) return head;

	if(head == loc){
		Node* temp = head->next;
		delete head;
		return temp;
	}

	Node* temp = head; 

	while(temp != nullptr && temp->next != loc){
		temp = temp->next; 
	}

	if(temp == nullptr) return head;

	temp->next = loc->next;
	delete loc;

	return head;
} // TC: O(n)
Node* reverseIterative(Node* head){
	Node* prev = nullptr;
	Node* curr = head;
	Node* next = nullptr;

	while(curr != nullptr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
} // TC: O(n)

Node* reverseRecursive(Node* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
} // TC: O(n)

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
} // TC: O(n)

void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
} // TC: O(n)

Node* MoveNthLastToFront(Node* head, int n) {
    if (head == nullptr || n <= 0) {
        return head; 
    }

    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    for (int i = 0; i < n; ++i) {
        if (fast == nullptr) {
            return head; 
        }
        fast = fast->next;
    }

    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    if (prev != nullptr) {
        prev->next = slow->next; 
        slow->next = head; 
        head = slow; 
    }

    return head;
} // TC: O(L) where L is the length of the linked list



int main(){
    Node* head = nullptr;
    Node* tail = nullptr;

    // Build list: 15 → 2 → 8 → 7 → 20 → 9 → 11 → 6 → 19
    insertAtTail(head,tail,15);
    insertAtTail(head,tail, 2);
    insertAtTail(head,tail, 8);
    insertAtTail(head,tail, 7);
    insertAtTail(head,tail, 20);
    insertAtTail(head,tail, 9);
    insertAtTail(head,tail, 11);
    insertAtTail(head,tail, 6);
    insertAtTail(head,tail,19);

    int n=2;
    head = MoveNthLastToFront(head, n);
    print(head);
}