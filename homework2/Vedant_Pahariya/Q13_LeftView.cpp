// Given a binary tree, create an array of the left view (leftmost elements in each level) of the tree.

// Technique used: Level Order Traversal (BFS) using queue
// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(w) where w is the maximum width of the tree (maximum number of nodes at any level)
// w can be at most n/2 for a complete binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> leftView(Node* root) {
    vector<int> result;
    
    if(root == NULL) {
        return result;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int levelSize = q.size();  // Number of nodes at current level
        
        // Process all nodes at this level
        for(int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            
            // Add the first node of this level to result
            if(i == 0) {
                result.push_back(current->data);
            }
            
            // Add children to queue for next level
            if(current->left != NULL) {
                q.push(current->left);
            }
            if(current->right != NULL) {
                q.push(current->right);
            }
        }
    }
    
    return result;
}