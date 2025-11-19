#include <iostream>
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

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }


Node* insertHelper(Node* curr, int key) {
        
        if (curr == nullptr) {
            return new Node(key);
        }
        if (key < curr->data) {
         curr->left = insertHelper(curr->left, key);
        } 
        else if (key > curr->data) {
            curr->right = insertHelper(curr->right, key);
        }
       
        return curr;
    }   // TC: O(h)


        bool contains(Node* curr, int key) {
            if (curr == nullptr) {
                return false;
            }
            if (key == curr->data) {
                return true;
            }
            else if (key < curr->data) {
                return contains(curr->left, key);
            }
            else {
                return contains(curr->right, key);
            }
    }  // TC: O(h)

    Node* deleteNode(Node* curr, int key) {
        if (curr == nullptr) {
            return curr;
        }
        if (key < curr->data) {
            curr->left = deleteNode(curr->left, key);
        }
        else if (key > curr->data) {
            curr->right = deleteNode(curr->right, key);
        }
        else {
            if (curr->left == nullptr) {
                Node* temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr) {
                Node* temp = curr->left;
                delete curr;
                return temp;
            }
            Node* temp = findMin(curr->right);
            curr->data = temp->data;
            curr->right = deleteNode(curr->right, temp->data);
        }
        return curr;
    } // TC: O(h)

    Node* findMin(Node* curr) {
        while (curr && curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    } // TC: O(h)

    int max(Node* curr) {
        if(curr == nullptr) return -1;
        
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        return curr->data;
    } // TC: O(h)
    int min(Node* curr) {
        if(curr == nullptr) return -1;
        
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr->data;
    }   // TC: O(h)
};