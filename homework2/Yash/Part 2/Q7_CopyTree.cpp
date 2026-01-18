// Q7: Copy Tree, Technique Used: Linked list recursion (Tree DFS recursion)
// Time Complexity: O(n), Space Complexity: O(n), Time Taken : 30 minutes

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};


Node* copyTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* n = new Node(root->val);

    n->left = copyTree(root->left);
    n->right = copyTree(root->right);

    return n;
}

// Preorder to verify correctness
void printPre(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}


int main() {
    cout << "Testing CopyTree\n";

    // Constructing a simple tree
    //        5
    //       / \
    //      3   8
    //     /   / \
    //    1   7   10

    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->right->left = new Node(7);
    root->right->right = new Node(10);

    cout << "Original Tree (Preorder): ";
    printPre(root);
    cout << "\n";

    Node* newRoot = copyTree(root);

    cout << "Copied Tree (Preorder):   ";
    printPre(newRoot);
    cout << "\n";

    return 0;
}
