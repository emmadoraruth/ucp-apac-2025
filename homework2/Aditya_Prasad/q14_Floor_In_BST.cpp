// Assumption - If no floor is found, code will return -1
// T.C - O(n) where n is the no of nodes in the BST
// M.C - O(logn) in recursive solution, O(1) in iterative solution
// Technique Used - Search binary search tree (BST)


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

int floorBSTRecursive(Node* root, int target){
	if(root == nullptr) return -1;

	if(root->data == target) return target;

	if(root->data > target){ 
		int left = floorBSTRecursive(root->left, target);
		return left;
	} 

	// root->data < target

	int right = floorBSTRecursive(root->right, target);

	if(right != -1){
		return right;
	}

	return root->data;
}

int floorBSTIterative(Node* root, int target){
	int ans = -1;
	Node* temp = root;

	while(temp != nullptr){
		if(temp->data == target) return target;

		if(temp->data > target){
			temp = temp->left;
		}else{
			ans = max(temp->data, ans);
			temp = temp->right;
		}
	}

	return ans;
}

int main(){
	Node* root = new Node(10);
	root->left = new Node(8);
	root->right = new Node(16);
	root->left->right = new Node(9);
	root->right->left = new Node(13);
	root->right->right = new Node(17);
	root->right->right->right = new Node(20);


	cout << floorBSTRecursive(root, 13) << endl;
	cout << floorBSTRecursive(root, 15) << endl;

	cout << floorBSTIterative(root, 13) << endl;
	cout << floorBSTIterative(root, 15) << endl;

	return 0;


}


// Time Taken - 20 mins
