// Given a binary tree, determine if it is a binary search tree.


//time taken : 30 min(majorly on creating the tree)

//Time complexity: best case O(1) [if by first node is not satisfying the bst condition 
//                 average case O(n)
//Space complexity:O(1)   [no extra space is used ]

#include <bits/stdc++.h>


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
Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Build a BST using insert operations
Node* createBST() {
    Node* root = NULL;

    int arr[] = {10, 5, 20, 3, 7, 15, 25, 1, 4, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    return root;
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}
bool isbst(Node* root,int l,int r){
    if(root==NULL){
        return true;
    }
    int val=root->val;
    if(val<=l || val>=r || l>r) return false;
    if(isbst(root->left,l,val) && isbst(root->right,val,r)) return true;
    return false;    
}

int main(){
    Node* root=createBST();
    bool Isbst=isbst(root,INT_MIN,INT_MAX);
    std::cout<<"The Given Tree Preorder is : "<<std::endl;
    inorder(root);
    std::cout<<((Isbst)?"The Given Tree is  a BST . ":"The Given Tree is Not a BST . ");
    std::cout<<std::endl;
}