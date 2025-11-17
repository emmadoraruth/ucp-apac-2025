/* Time Complexity : O(n) where n is the number of nodes in the tree 
   Memory Complexity : O(h) where h is the height of the tree (or it will be O(n) in case of skewed tree)
   Technique Used : Inorder order Traversal 
   */

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

bool isBST(Node* root, Node*& prev){
	if(root == nullptr) return true;

	int currVal = root->data;

	if(isBST(root->left, prev) == false) return false;

	if(prev != nullptr && root->data <= prev->data) return false;
	prev = root;

	if(isBST(root->right, prev) == false) return false;

	return true;
}

int main(){
	Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(16);
    root->left->right = new Node(9);
    root->right->left = new Node(13);
    root->right->right = new Node(17);
    root->right->right->right = new Node(20);

    Node* root2 = new Node(10);
    root2->left = new Node(8);
    root2->right = new Node(16);
    root2->left->right = new Node(9);
    root2->right->left = new Node(13);
    root2->right->right = new Node(17);
    root2->right->right->right = new Node(15);

    Node* prev = nullptr;

    cout << isBST(root, prev) << endl;

    Node* prev2 = nullptr;

    cout << isBST(root2, prev2) << endl;
    
}

// Time : 15 mins