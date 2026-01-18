/* Time Complexity : O(n) where n is the number of nodes in the linked list 
   Memory Complexity : O(1) 
   Technique Used : linked list traversal 
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

Node* dedUpSortedList(Node* root){
	if(root == nullptr) return nullptr;

	Node* ans = root;

	while(root->next != nullptr){ 
		if(root->data == root->next->data){
			root->next = root->next->next;
		}else{
			root = root->next;
		}
	}

	return ans;
}

void printList(Node* root){
	while(root != nullptr){
		cout << root->data << " ";
		root = root->next;
	}

}

int main(){
	Node* root1 = new Node(1);
	root1->next = new Node(2);
	root1->next->next = new Node(2);
	root1->next->next->next = new Node(4);
	root1->next->next->next->next = new Node(5);
	root1->next->next->next->next->next = new Node(5);
	root1->next->next->next->next->next->next = new Node(5);
	root1->next->next->next->next->next->next->next = new Node(10);
	root1->next->next->next->next->next->next->next->next = new Node(10);

	Node* ans = dedUpSortedList(root1);
	printList(ans);
	cout << endl;
	
	return 0;
}

// Time Taken : 10 mins