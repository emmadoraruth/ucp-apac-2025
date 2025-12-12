#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

// firt try - incorrect approach 
// Only check the immediate children of each node, does not ensure that every node in left subtree is less than root and every node in right subtree is greater than root
/*
bool isBST(Node* root){
    if(root == NULL){
        return true;
    }

    bool condition1 = true;
    bool condition2 = true;
    if(root->left!= NULL){
        condition1 = root->data > root->left->data;
    }

    if(root->right!= NULL){
        condition2 = root->data < root->right->data;
    }

    bool current = condition1 && condition2;
    
    return isBST(root->left) && isBST(root->right) && current;
}
*/

bool isBSTUtil(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }

    return isBSTUtil(root->left, min, root->data) && isBSTUtil(root->right, root->data, max);
}

// write main function to test your implementation.
int main(){
    Node* root = new Node();
    root->data = 10;
    root->left = new Node();
    root->left->data = 5;
    root->right = new Node();
    root->right->data = 15;

    cout << boolalpha << isBSTUtil(root, INT_MIN, INT_MAX) << "\n"; // should return true

    root->right->left = new Node();
    root->right->left->data = 7; // violates BST property

    cout << boolalpha << isBSTUtil(root, INT_MIN, INT_MAX) << "\n"; // should return false

    return 0;
}
