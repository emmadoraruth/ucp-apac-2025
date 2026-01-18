// Binary Search Tree — average-case complexities O(log n), worst-case O(n) for unbalanced trees
// Time Complexity (typical / average):
//   min: O(log n)   max: O(log n)   contains: O(log n)
//   insert: O(log n) delete: O(log n)
// Space Complexity: O(1) auxiliary (ignoring recursion stack)

#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // O(h) where h is the tree height (average O(log n))
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->val) node->left = insertNode(node->left, value);
        else if (value > node->val) node->right = insertNode(node->right, value);
        return node;
    }

    // O(h)
    bool containsNode(Node* node, int value) {
        if (node == nullptr) return false;
        if (value < node->val) return containsNode(node->left, value);
        if (value > node->val) return containsNode(node->right, value);
        return true;
    }

    // O(h)
    Node* findMinNode(Node* node) {
        Node* cur = node;
        while (cur && cur->left) cur = cur->left;
        return cur;
    }

    // O(h)
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return nullptr;
        if (value < node->val) node->left = deleteNode(node->left, value);
        else if (value > node->val) node->right = deleteNode(node->right, value);
        else {
            // node to delete found
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {
                Node* nxt = node->right;
                delete node;
                return nxt;
            }
            if (node->right == nullptr) {
                Node* nxt = node->left;
                delete node;
                return nxt;
            }
            // two children: replace with inorder successor
            Node* succ = findMinNode(node->right);
            node->val = succ->val;
            node->right = deleteNode(node->right, succ->val);
        }
        return node;
    }

    // O(n) to print the whole tree
    void printInorder(Node* node) {
        if (node == nullptr) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // O(h)
    int min() {
        Node* cur = root;
        while (cur && cur->left) cur = cur->left;
        return cur ? cur->val : -1;
    }

    // O(h)
    int max() {
        Node* cur = root;
        while (cur && cur->right) cur = cur->right;
        return cur ? cur->val : -1;
    }

    // O(h)
    bool contains(int value) {
        return containsNode(root, value);
    }

    // O(h)
    void insert(int value) {
        root = insertNode(root, value);
    }

    // O(h)
    void remove(int value) {
        root = deleteNode(root, value);
    }

    // Expose inorder printing
    void printInorder() {
        printInorder(root);
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinarySearchTree bst;


    cout << "Inserting values into BST..." << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);


    cout << "BST inorder: ";
    bst.printInorder();
    cout << endl;
    // Expected: 20 30 40 50 60 70 80


    cout << "Contains 40? " << bst.contains(40) << endl;
    // Expected: 1


    cout << "Contains 25? " << bst.contains(25) << endl;
    // Expected: 0


    cout << "Min: " << bst.min() << endl;
    // Expected: 20


    cout << "Max: " << bst.max() << endl;
    // Expected: 80


    cout << "Removing root (50)..." << endl;
    bst.remove(50);


    cout << "BST inorder after removing 50: ";
    bst.printInorder();
    cout << endl;
    // Expected: 20 30 40 60 70 80


    return 0;
}