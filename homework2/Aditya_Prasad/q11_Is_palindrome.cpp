/* Time Complexity : O(n) where n is the number of nodes in the linked list 
   Memory Complexity : O(1) as we're not storing else than input DLL;
   Technique Used : Doubly linked list forward-backward two-pointer 
   */ 

#include <bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* next;
	Node* prev;

	Node(int val){
		data = val;
		next = nullptr;
		prev = nullptr;
	}
};

bool isPalindrome(Node* root){
	if(root == nullptr) return true;

	Node* left = root;
	Node* right = root;

	while(right->next != nullptr){
		right = right->next;
	}

	while(left->prev != right && left != right){ // after covering all the nodes
		if(left->data != right->data) return false;
		left = left->next;
		right = right->prev;
	}

	return true;
}

int main(){
	Node* root = new Node(9);

	root->next = new Node(2);
	root->next->prev = root;

	root->next->next = new Node(4);
	root->next->next->prev = root->next;

	root->next->next->next = new Node(2);
	root->next->next->next->prev = root->next->next;

	root->next->next->next->next = new Node(9);
	root->next->next->next->next->prev = root->next->next->next;

	cout << isPalindrome(root) << endl;

	return 0;
}

// Time Taken - 15 mins