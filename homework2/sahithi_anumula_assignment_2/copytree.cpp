#include <iostream>
using namespace std;

//It took me around 30 min to complete
// Technique: Depth-first traversal (pre-order)
// Time complexity: O(n), where n is the number of nodes in the tree
// Space complexity: O(n) for the new copied tree + O(h) recursion stack (h = tree height)


struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* copytree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* newRoot = createNode(root->data);
    newRoot->left = copytree(root->left);
    newRoot->right = copytree(root->right);

    return newRoot;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    inorderPrint(root);
    cout << endl;

    Node* copyRoot = copytree(root);

    inorderPrint(copyRoot);
    cout << endl;

    root->left->data = 20;
    root->right->data = 30;

    inorderPrint(root);
    cout << endl;

    inorderPrint(copyRoot);
    cout << endl;

    return 0;
}
