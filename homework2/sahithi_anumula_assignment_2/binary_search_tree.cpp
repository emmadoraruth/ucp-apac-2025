#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

class BinarySearchTree {
  private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return createNode(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    bool contains(Node* node, int val) const {
        if (node == nullptr) return false;
        if (val == node->data) return true;
        if (val < node->data) return contains(node->left, val);
        return contains(node->right, val);
    }

    Node* findMinNode(Node* node) const {
        if (!node) return nullptr;
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    Node* findMaxNode(Node* node) const {
        if (!node) return nullptr;
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) return nullptr;

        if (val < node->data) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->data) {
            node->right = deleteNode(node->right, val);
        } else {
            // found the node to delete
            if (node->left == nullptr && node->right == nullptr) {
                // no children
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                // only right child
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                // only left child
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                // two children: use inorder successor (min in right subtree)
                Node* succ = findMinNode(node->right);
                node->data = succ->data;
                node->right = deleteNode(node->right, succ->data);
            }
        }
        return node;
    }

    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

  public:
    BinarySearchTree() : root(nullptr) {}

    int min() {
        Node* mn = findMinNode(root);
        if (!mn) {
            cerr << "Tree is empty" << endl;
            return -1; 
        }
        return mn->data;
    }

    int max() {
        Node* mx = findMaxNode(root);
        if (!mx) {
            cerr << "Tree is empty" << endl;
            return -1; 
        }
        return mx->data;
    }

    bool contains(int val) {
        return contains(root, val);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteValue(int val) {
        root = deleteNode(root, val);
    }

    void printInOrder() const {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    bst.printInOrder();

    cout << bst.min() << endl;
    cout << bst.max() << endl;

    cout << "6? " << (bst.contains(6) ? "yes" : "no") << endl;
    cout << "2? " << (bst.contains(2) ? "yes" : "no") << endl;

    bst.deleteValue(3);
    bst.printInOrder();

    bst.deleteValue(8);
    bst.printInOrder();

    return 0;
}
