/* Time Complexity : O(n) where n is the number of nodes in the tree 
   Memory Complexity : O(h) where h is the height of the tree (or it will be O(n) in case of skewed tree)
   Technique Used : Pre order Traversal to copy the nodes
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

Node* createCopy(Node* original) {
    if (original == NULL) return NULL;
    Node* newNode = new Node(original->data); 
    newNode->left = createCopy(original->left);
    newNode->right = createCopy(original->right);

    return newNode;
}



void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    

    inorder(root);

    cout << endl;

    Node* copy = createCopy(root);

    inorder(copy);
}

// Time : 10 mins