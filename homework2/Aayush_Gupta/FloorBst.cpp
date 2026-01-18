/*
Technique: Iterative Binary Search on BST

Time Complexity: O(H)

Space Complexity: O(1)
*/

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findFloorInBST(TreeNode* root, int target) {
    int floor = -1; 

    while (root != nullptr) {
        if (root->val == target) {
            return root->val;
        }

        if (root->val > target) {
            root = root->left;
        } else {
            floor = root->val; 
            root = root->right;
        }
    }
    
    return floor;
}
int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(16);
    root->left->right = new TreeNode(9); 
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    root->right->right->right = new TreeNode(20);

   
    int target1 = 13;
    int result1 = findFloorInBST(root, target1);
    cout << "Test Case 1 (target=13): " << result1 <<endl; // Output: 13
    int target2 = 15;
    int result2 = findFloorInBST(root, target2);
    cout << "Test Case 2 (target=15): " << result2 << endl; // Output: 13


    return 0;
}