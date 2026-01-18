// Technique Used: Inorder depth first traversal
// Time Complexity: O(n)
// Space Complexity: O(h) where h is height of tree
// Time Spent: 22 minutes 47 seconds

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

bool validate(Node* root, long long low, long long high) {
    if (!root) return true;
    if (root->value <= low || root->value >= high) return false;
    return validate(root->left, low, root->value) &&
           validate(root->right, root->value, high);
}

bool isBST(Node* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->left->left = new Node(3);

    cout << isBST(root1) << endl;

    Node* root2 = new Node(10);
    root2->left = new Node(15); 

    cout << isBST(root2) << endl;

    return 0;
}
