// Q3: Implementing Binary Search Tree
// Time Taken: 37 minutes

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }

        // O(log n)
        int min() {
            if (root == nullptr) {
                return -1; 
            }
            Node* cur = root;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            return cur->data;
        }

        // O(log n)
        int max() {
            if (root == nullptr) {
                return -1;
            }
            Node* cur = root;
            while (cur->right != nullptr) {
                cur = cur->right;
            }
            return cur->data;
        }

        // O(log n)
        bool contains(int val) {
            Node* cur = root;
            while (cur != nullptr) {
                if (val == cur->data) {
                    return true;
                }
                else if (val < cur->data) {
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
            }
            return false;
        }

        // O(log n)
        void insert(int val) {
            if (root == nullptr) {
                root = new Node(val);
                return;
            }

            Node* cur = root;
            Node* parent = nullptr;

            while (cur != nullptr) {
                parent = cur;
                if (val == cur->data) {
                    return;  // no duplicates
                }
                else if (val < cur->data) {
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
            }

            Node* n = new Node(val);

            if (val < parent->data) {
                parent->left = n;
            }
            else {
                parent->right = n;
            }
        }
};


int main() {
    BinarySearchTree bst;

    cout << "Inserting values" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Min and Max" << endl;
    cout << "Minimum value: " << bst.min() << endl;
    cout << "Maximum value: " << bst.max() << endl;

    cout << "Contains function" << endl;
    int searchVals[] = {40, 25, 80, 90};
    for (int v : searchVals) {
        cout << "Contains " << v << "? "
             << (bst.contains(v) ? "Yes" : "No") << endl;
    }

    cout << "Test inserting duplicate (should not change anything)" << endl;
    bst.insert(30);
    cout << "Contains 30? " << (bst.contains(30) ? "Yes" : "No") << endl;

    return 0;
}
