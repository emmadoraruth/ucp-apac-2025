// Technique Used: Depth first traversal (pre-order)
// Time Complexity: O(n)
// Space Complexity: O(h) where h is height of tree (recursion stack)
// Time Spent: 18 minutes 37 seconds 

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* copyTree(Node* root) {
    if (!root) return nullptr;
    Node* newRoot = new Node(root->value);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->value << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);

    Node* copied = copyTree(root);

    printInorder(root); cout << endl;
    printInorder(copied); cout << endl;

    return 0;
}
