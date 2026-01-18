// Technique: Level Order Traversal (BFS) - Left View
// Time Complexity: O(n) 
// Space Complexity: O(n) 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<int> findLeftView(TreeNode* root) {
    vector<int> leftViewNodes;
    if (root == nullptr) return leftViewNodes;
    
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    while (!nodeQueue.empty()) {
        int currentLevelSize = nodeQueue.size();
        leftViewNodes.push_back(nodeQueue.front()->val);
        
        for (int i = 0; i < currentLevelSize; i++) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
            
            if (currentNode->left != nullptr) {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                nodeQueue.push(currentNode->right);
            }
        }
    }
    
    return leftViewNodes;
}

TreeNode* buildTree(vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    int index = 1;
    while (index < values.size()) {
        TreeNode* currentNode = nodeQueue.front();
        nodeQueue.pop();
        
        if (index < values.size() && values[index] != -1) {
            currentNode->left = new TreeNode(values[index]);
            nodeQueue.push(currentNode->left);
        }
        index++;
        
        if (index < values.size() && values[index] != -1) {
            currentNode->right = new TreeNode(values[index]);
            nodeQueue.push(currentNode->right);
        }
        index++;
    }
    
    return root;
}

void printVector(vector<int> vec) {
    
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    
    }
    
}

int main() {
    
   
    vector<int> tree1Values = {7, 8, 20, 3, 9, 13, 14, -1, -1, -1, -1, -1, -1, 15};
    TreeNode* tree1 = buildTree(tree1Values);
    vector<int> result1 = findLeftView(tree1);
    
    
    printVector(result1);
    cout << endl;
    
    
    
    vector<int> tree2Values = {7, 20, 4, 15, 6, 8, 11};
    TreeNode* tree2 = buildTree(tree2Values);
    vector<int> result2 = findLeftView(tree2);
    
    
    printVector(result2);

    return 0;
}