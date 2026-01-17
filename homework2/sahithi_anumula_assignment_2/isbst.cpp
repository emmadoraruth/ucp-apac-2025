#include <iostream>
using namespace std;

//It took me 25 minutes to complete
// Technique: In-order depth-first traversal
// Time complexity: O(n), where n is the number of nodes
// Space complexity: O(h) for recursion stack, where h is the height of the tree

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

bool isvalidbst(Node* root, Node*& prev) {
    if (root == nullptr) return true;
    if (!isvalidbst(root->left, prev)) return false;
    if (prev != nullptr && root->data <= prev->data) return false;
    prev = root;
    return isvalidbst(root->right, prev);
}

bool isbst(Node* root) {
    Node* prev = nullptr;
    return isvalidbst(root, prev);
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    
    Node* root1 = createNode(8);
    root1->left = createNode(3);
    root1->right = createNode(10);
    root1->left->left = createNode(1);
    root1->left->right = createNode(6);
    root1->right->right = createNode(14);

    inorderPrint(root1);
    cout << "\nIs bst? " << (isbst(root1) ? "Yes" : "No") << "\n\n";

    Node* root2 = createNode(5);
    root2->left = createNode(1);
    root2->right = createNode(4);
    root2->right->left = createNode(3);
    root2->right->right = createNode(6);

    inorderPrint(root2);
    cout << "\nIs bst? " << (isbst(root2) ? "Yes" : "No") << "\n\n";

    Node* root3 = createNode(42);
    inorderPrint(root3);
    cout << "\nIs bst? " << (isbst(root3) ? "Yes" : "No") << "\n\n";

    return 0;
}
