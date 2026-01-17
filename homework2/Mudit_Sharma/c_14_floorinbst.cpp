// Given a target numeric value and a binary search tree, return the floor (greatest element less than or equal to the target) in the BST.


//Time Spent:24 min


//Time complexity:  O(logn )  [as we used a binary search in a BST]
//Space complexity: O(1)   [we used only a variable to store ans which takes constant space]

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

// Insert in BST
Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Build BST
Node* createBST() {
    Node* root = NULL;

    int arr[] = {10, 5, 20, 3, 7, 15, 25, 1, 4, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    return root;
}

// Proper inorder
void inorder(Node* root, std::vector<int>& ans) {
    if (root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

std::vector<int> makeinorder(Node* root){
    std::vector<int> ans;
    inorder(root, ans);
    return ans;
}

// Floor in BST using binary search in inorder array
int floorinbst(int target, Node* root) {
    std::vector<int> inorderset = makeinorder(root);
    int s = 0, e = inorderset.size() - 1;
    int ans = INT_MIN;

    while (s <= e) {
        int m = s + (e - s) / 2;
        int val = inorderset[m];

        if (val == target) return val;

        if (val < target) {
            ans = val;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return ans;
}

int main() {
    Node* root = createBST();

    std::vector<int> inorderset = makeinorder(root);
    for (auto &i : inorderset)
        std::cout << i << " ";

    std::cout << std::endl;

    int target = 1;
    std::cout << "Floor of " << 1<< " is " << floorinbst(1, root)<<std::endl;
    std::cout << "Floor of " << 6<< " is " << floorinbst(6, root)<<std::endl;
}
