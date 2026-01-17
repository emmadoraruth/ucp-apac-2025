// Given a binary tree, create a deep copy. Return the root of the new tree.

//time taken:20 min 
//Time complexity:O(N)  as each node is traversed once
//Space complexity:O(n) as output ans has newly formed n nodes

#include<iostream>

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
Node* deepcopy(Node* root) {
    if (root == NULL) return NULL;
    
    Node* newnode = new Node(root->val);
    newnode->left = deepcopy(root->left);
    newnode->right = deepcopy(root->right);
    
    return newnode;
}

Node* createTree() {
     Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(3);
    root->left->right = new Node(7);

    root->right->left = new Node(15);
    root->right->right = new Node(25);

    root->left->left->left = new Node(1);
    root->left->left->right = new Node(4);

    root->right->left->right = new Node(17);

    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = createTree();
    
    std::cout << "Original Tree (Preorder): ";
    preorder(root);
    std::cout << std::endl;

    Node* copyRoot = deepcopy(root);

    std::cout << "Copied Tree (Preorder): ";
    preorder(copyRoot);
    std::cout << std::endl;

    return 0;
}