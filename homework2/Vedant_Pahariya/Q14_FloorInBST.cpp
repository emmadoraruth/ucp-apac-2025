// Given a target numeric value and a binary search tree, return the floor (greatest element less than or equal to the target) in the BST.

// Technique used: Search binary search tree recursively
// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(h) due to recursion stack
// h = log n

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int FloorinBST(Node* root, int target){
    if(root==NULL){
        return INT_MIN;
    }
    
    if(target > root->data){
        return max(root->data, FloorinBST(root->right, target));
    }
    if(target == root->data){
        return target;
    }
    if(target < root->data){
        return FloorinBST(root->left, target);
    }
}

int main(){
    Node* root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 5;
    root->right = new Node();
    root->right->data = 15;
    root->left->left = new Node();
    root->left->left->data = 3;
    root->left->right = new Node();
    root->left->right->data = 7;
    root->right->right = new Node();
    root->right->right->data = 20;

    cout << FloorinBST(root, 12) << "\n"; // should return 10
    cout << FloorinBST(root, 5) << "\n";  // should return 5
    cout << FloorinBST(root, 2) << "\n";  // should return INT_MIN

    return 0;
}

// If a function returns INT_MIN, it means that there is no floor value in the BST for the given target. That is, all the values in the tree are greater than the target.