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

int floorINBST(Node* root, int target) {
    int floorValue = -1; 
    Node* currentNode = root;

    while (currentNode != nullptr) {
        if (currentNode->data == target) {
            return currentNode->data;
        } 
        else if (currentNode->data < target) {
            floorValue = currentNode->data; 
            currentNode = currentNode->right; 
        } 
        else {
            currentNode = currentNode->left; 
        }
    }

    return floorValue; 
}
// TC: O(h), SC: O(1) 
int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(16);

    
    root->left->right = new Node(9);

    root->right->left = new Node(13);
    root->right->right = new Node(17);

    root->right->right->right = new Node(20);
    int target = 15;
    int floorValue = floorINBST(root, target);
    cout << "Floor value of " << target << " in the BST is: " << floorValue << endl;
}