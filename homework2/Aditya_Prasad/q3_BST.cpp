// Time taken : 39 mins

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
  private:
    Node* root;

  public:
    BinarySearchTree(){
    	root = nullptr;
    }

    int min(){
    	if(root == nullptr) return -1;
    	Node* curr = root;
    	while(curr->left != nullptr){
    		curr = curr->left;
    	}
    	return curr->data;
    }

    int max(){
    	if(root == nullptr) return -1;
    	Node* curr = root;
    	while(curr->right != nullptr){
    		curr = curr->right;
    	}
    	return curr->data;
    }

    bool contains(int val){
    	Node* curr = root;
    	while(curr != nullptr){
    		if(val < curr->data){
    			curr = curr->left;
    		}else if(val > curr->data){
    			curr = curr->right;
    		}else{
    			return true;
    		}
    	}
    	return false;
    }
    
    void insert(int val){
    	Node* newNode = new Node(val);
    	if(root == nullptr){
    		root = newNode;
    		return;
    	}
    	Node* curr = root;
    	Node* parent = nullptr;
    	while(curr != nullptr){
    		parent = curr;
    		if(val < curr->data) curr = curr->left;
    		else if(val > curr->data) curr = curr->right;
    		else return;
    	}
    	if(val < parent->data) parent->left = newNode;
    	else parent->right = newNode;
    }
                            
    void remove(int val){
        Node* curr = root;
        Node* parent = nullptr;
        while(curr != nullptr && curr->data != val){
            parent = curr;
            if(val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        if(curr == nullptr) return;

        if(curr->left == nullptr && curr->right == nullptr){
            if(curr == root){
                delete root;
                root = nullptr;
                return;
            }
            if(parent->left == curr) parent->left = nullptr;
            else parent->right = nullptr;
            delete curr;
            return;
        }

        if(curr->left == nullptr || curr->right == nullptr){
            Node* child = (curr->left != nullptr) ? curr->left : curr->right;
            if(curr == root){
                delete root;
                root = child;
                return;
            }
            if(parent->left == curr) parent->left = child;
            else parent->right = child;
            delete curr;
            return;
        }

        Node* succParent = curr;
        Node* succ = curr->right;
        while(succ->left != nullptr){
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;
        if(succParent->left == succ) succParent->left = succ->right;
        else succParent->right = succ->right;
        delete succ;
    }
};

int main(){
	return 0;
}
