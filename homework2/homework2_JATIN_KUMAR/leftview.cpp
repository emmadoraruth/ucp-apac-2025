


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};  

vector<int>leftview(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();

            if (i == 0) {
                result.push_back(currentNode->data);
            }

            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
    }

    return result;
}
// TC: O(n), SC: O(n) where n is the number of nodes in the tree


void print( vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    Node* root = new Node(7);
    root->left = new Node(8);
    root->right = new Node(3);

    
    root->right->left = new Node(9);
    root->right->left->left = new Node(20);
    root->right->right = new Node(13);
    root->right->right->left = new Node(14);

    root->right->right->left->right = new Node(15);
    vector<int> leftViewResult = leftview(root);
    cout << "Left View of the Binary Tree: ";
    print(leftViewResult);

}

