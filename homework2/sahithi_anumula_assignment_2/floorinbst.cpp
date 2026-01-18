#include <iostream>
#include <climits>
using namespace std;

// It took around 35 min to complete
// Technique: Search binary search tree (BST)
// Time complexity: O(h), where h is the height of the tree (O(log n) for balanced BST, O(n) worst case)
// Space complexity: O(1) extra space (iterative search)

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

Node* insertbst(Node* root, int val) {
    if (!root) return createNode(val);

    if (val < root->data) {
        root->left = insertbst(root->left, val);
    } else if (val > root->data) {
        root->right = insertbst(root->right, val);
    }
    return root;
}

bool floorinbst(Node* root, int target, int& floorVal) {
    bool found = false;
    Node* curr = root;

    while (curr) {
        if (curr->data == target) {
            floorVal = curr->data;
            return true; 
        } else if (curr->data > target) {
            curr = curr->left;
        } else {
            found = true;
            floorVal = curr->data;
            curr = curr->right;
        }
    }

    return found;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void testFloor(Node* root, int target) {
    int floorVal;
    bool ok = floorinbst(root, target, floorVal);
    cout  << target << " -> ";
    if (ok) {
        cout << floorVal << "\n";
    } else {
        cout << "no floor\n";
    }
}

int main() {
    Node* root = nullptr;
    root = insertbst(root, 8);
    root = insertbst(root, 4);
    root = insertbst(root, 12);
    root = insertbst(root, 2);
    root = insertbst(root, 6);
    root = insertbst(root, 10);
    root = insertbst(root, 14);

    inorderPrint(root);
    cout << "\n\n";
    testFloor(root, 1);  
    testFloor(root, 2);   
    testFloor(root, 5);   
    testFloor(root, 8);  
    testFloor(root, 9);   
    testFloor(root, 13);  
    testFloor(root, 20);  

    return 0;
}
