#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};  

Node* copyTree(Node* root){
    if(root == nullptr){
        return nullptr;
    }

    Node* newNode = new Node(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
} // TC: O(n)

void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
} // TC: O(n)

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Original Tree Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    Node* copiedRoot = copyTree(root);

    cout << "Copied Tree Inorder Traversal: ";
    inorderTraversal(copiedRoot);
    cout << endl;

    return 0;
}