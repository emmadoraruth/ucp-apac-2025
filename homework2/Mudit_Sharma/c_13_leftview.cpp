// Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.

// Examples:


//time spent:17 min


//Time complexity: O(n)  [as each node is iterated]
//Space complexity: O(n) [we used queue data structure to use level traversal]

#include<bits/stdc++.h>
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    // manual tree construction
    void makeTree() {
        // Creating a tree
        //
        //           10
        //         /    \
        //       5        20
        //      / \      /  \
        //     3   7    15  25
        //        /
        //       6
        //
        root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(20);

        root->left->left = new Node(3);
        root->left->right = new Node(7);
        root->left->right->left = new Node(6);

        root->right->left = new Node(15);
        root->right->right = new Node(25);
    }

    std::vector<int> leftView() {
        std::vector<int> ans;
        if (root == NULL) return ans;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {

                Node* curr = q.front();
                q.pop();

                // first element of each level = left view
                if (i == 0) ans.push_back(curr->val);

                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
            }
        }

        return ans;
    }
};

int main() {
    BinaryTree bt;
    bt.makeTree();

    std::vector<int> leftview = bt.leftView();

    std::cout << "Left View: ";
    for (int x : leftview) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}