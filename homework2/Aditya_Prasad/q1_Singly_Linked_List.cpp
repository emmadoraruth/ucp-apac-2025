// Time Taken : 35 Mins


#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;

	Node(int val){
		data = val;
		next = nullptr;
	}
};

Node* insertAtFront(Node* head, int val){
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
	return head;
}

Node* insertAtBack(Node* head, int val){
	Node* newNode = new Node(val);

	if(head == nullptr) return newNode;

	Node* temp = head;
	while(temp->next != nullptr){
		temp = temp->next; 
	}

	temp->next = newNode;
	return head;
}

Node* insertAfter(Node* head, int val, Node* loc){
	if(loc == nullptr) return head;

	Node* newNode = new Node(val);
	newNode->next = loc->next;
	loc->next = newNode;

	return head;
}

Node* deleteFront(Node* head){
	if(head == nullptr) return head;

	Node* temp = head->next;
	delete head;
	return temp;
}

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
}

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
}

int length(Node* head){
	Node* temp = head; 
	int count = 0;

	while(temp != nullptr){
		count++;
		temp = temp->next;  
	}

	return count;
}

Node* reverseIterative(Node* head){
	Node* prev = nullptr;
	Node* curr = head;
	Node* nextP = nullptr;

	while(curr != nullptr){
		nextP = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextP;
	}

	return prev;
}

Node* reverseRecursive(Node* head){
	if(head == nullptr || head->next == nullptr)
		return head;

	Node* newHead = reverseRecursive(head->next);

	head->next->next = head;
	head->next = nullptr;

	return newHead;
}

int main(){
	return 0;
}
