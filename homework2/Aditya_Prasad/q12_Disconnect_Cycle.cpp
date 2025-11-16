/* Time Complexity : O(3n) = O(n) where n is the number of nodes in the linked list 
   Memory Complexity : O(1) 
   Technique Used : Linked list fast slow two pointer
   */ 




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

Node* disconnectCycle(Node* root){
	if(root == nullptr) return nullptr;

	Node* slow = root;
	Node* fast = root;
	bool isCycle = false;

	while(fast != nullptr && fast->next != nullptr){ // O(n)
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast){
			isCycle = true;
			break;
		}
	}

	if(isCycle == false) return root;

	slow = root;
	while(slow != fast){ // O(n)
		slow = slow->next;
		fast = fast->next;
	}

	Node* startingPoint = slow;
	Node* prev = startingPoint;

	while(prev->next != startingPoint){ // O(n)
		prev = prev->next;
	}

	prev->next = nullptr;

	return root;

}

void printList(Node* root){
	while(root != nullptr){
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl;

}

int main(){
	// 10 18 12 9 11 4
	Node* root = new Node(10);
	root->next = new Node(18);
	root->next->next = new Node(12);
	root->next->next->next = new Node(9);
	root->next->next->next->next = new Node(11);
	root->next->next->next->next->next = new Node(4);
	root->next->next->next->next->next->next = root->next->next;

	Node* ans = disconnectCycle(root);
	printList(ans);

	root->next->next->next->next->next->next = root->next->next->next->next->next;

	ans = disconnectCycle(root);
	printList(ans);

	return 0;
}

// Time Taken : 30 mins