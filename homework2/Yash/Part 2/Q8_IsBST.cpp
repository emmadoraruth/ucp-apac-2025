// Q8: Is BST, Technique Used: Search binary search tree technique (min/max recursion)
// Time Complexity: O(n), Space Complexity: O(n) , Time Taken : 32 minutes 

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


bool isBSTHelper(Node* root, int minVal, int maxVal) {
    if (root == nullptr) {
        return true;
    }

    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }

    bool leftValid = isBSTHelper(root->left, minVal, root->val);
    bool rightValid = isBSTHelper(root->right, root->val, maxVal);

    return leftValid && rightValid;
}


bool isBST(Node* root) {
    return isBSTHelper(root, -2147483648, 2147483647);
}

// Simple preorder print 
void printPre(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}


int main() {
    cout << "Testing IsBST\n";

    // Example 1: Valid BST
    //        10
    //       /  \
    //      8    16
    //       \   / \
    //       9 13  17
    //              \
    //              20         
    Node* root1 = new Node(10);
    root1->left = new Node(8);
    root1->right = new Node(16);

    
    root1->left->right = new Node(9);

    root1->right->left = new Node(13);
    root1->right->right = new Node(17);

    root1->right->right->right = new Node(20);

    cout << "Tree 1 IsBST: " << isBST(root1) << "\n";

    // Example 2: Invalid BST
    //       5
    //      / \
    //     1   4
    //        / \
    //       3   6

    Node* root2 = new Node(5);
    root2->left = new Node(1);
    root2->right = new Node(4);
    root2->right->left = new Node(3);
    root2->right->right = new Node(6);

    cout << "Tree 2 IsBST: " << isBST(root2) << "\n";

    return 0;
}
