// Q14: Floor in BST, Technique Used: Binary search tree search
// Time Complexity: O(h) where h = tree height (O(log n) for balanced BST), Space Complexity: O(1) , Time Taken: 41 minutes

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



int floorInBST(Node* root, int target) {
    int ans = -1;   // assuming all values >= 0; change if needed

    Node* cur = root;

    while (cur != nullptr) {
        if (cur->val == target) {
            return cur->val;
        }
        else if (cur->val > target) {
            cur = cur->left;
        }
        else {
            ans = cur->val;
            cur = cur->right;
        }
    }

    return ans;
}


void printAns(int x) {
    cout << x << "\n";
}


int main() {
    cout << "Testing FloorInBST\n";

    // Build BST used in examples
    //
    //          10
    //        /    \
    //       8      16
    //        \    /  \
    //         9  13  17
    //                 \
    //                 20

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(16);

    
    root->left->right = new Node(9);

    root->right->left = new Node(13);
    root->right->right = new Node(17);

    root->right->right->right = new Node(20);

    // Example 1
    int target1 = 13;
    cout << "Floor of 13: ";
    printAns(floorInBST(root, target1));  // expected 13

    // Example 2
    int target2 = 15;
    cout << "Floor of 15: ";
    printAns(floorInBST(root, target2));  // expected 13

    return 0;
}
