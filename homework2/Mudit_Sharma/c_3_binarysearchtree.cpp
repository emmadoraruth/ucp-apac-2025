// In each of the methods, use pointers in languages that support pointers (e.g., Node * in C++) or  references in languages that support references (e.g., Python). Your Node struct will be the same as for your doubly linked list except the two pointers/references should be left and right rather than next and prev. Note that the delete method is more difficult than the insert method; you won’t need it for the rest of the assignment so either stop or get help from your mentor if you are stuck after 40 minutes.

// struct Node {
//   int data
//   Node left
//   Node right
// }

// class BinarySearchTree {
//   private:
//     Node this->root

//   public:
//     int min() // returns the minimum value in the BST.  O(logn) time.
//     int max() // returns the maximum value in the BST.  O(logn) time.
//     bool contains(int val) // returns a boolean indicating whether val is present in the
//                               BST.  O(logn) time.
//     void insert(int val) // creates a new Node with data val in the appropriate location.
//                             For simplicity, do not allow duplicates. If val is already
//                             present, insert is a no-op. O(logn) time.
//     void delete(int val) // deletes the Node with data val, if it exists. O(logn) time.
// }

//Time spent:42 min

#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    // Return minimum value (left-most node)
    int min()
    {
        if (root == NULL)
            return -1;

        Node *temp = root;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }

    // Return maximum value (right-most node)
    int max()
    {
        if (root == NULL)
            return -1;

        Node *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }

    // Search a value in the BST
    bool contains(int val)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == val)
                return true;
            else if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    // Insert value — NO duplicates allowed
    void insert(int val)
    {
        Node *newNode = new Node(val);

        // Case 1: Empty tree
        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Node *temp = root;
        Node *parent = NULL;

        while (temp != NULL)
        {
            parent = temp;

            // No duplicates allowed
            if (val == temp->data)
            {
                delete newNode;
                return;
            }

            if (val < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        // Insert as child of parent
        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    void deleteNodeHelper(Node *&root, int value)
    {
        if (root == NULL)
            return;

        if (value < root->data)
        {
            deleteNodeHelper(root->left, value);
        }
        else if (value > root->data)
        {
            deleteNodeHelper(root->right, value);
        }
        else
        {
            // CASE 1: No children (leaf)
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
                return;
            }

            // CASE 2: One child (right)
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                root = temp;
                return;
            }

            // CASE 2: One child (left)
            if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                root = temp;
                return;
            }

            // CASE 3: Two children
            Node *successor = root->right;
            while (successor->left != NULL)
            {
                successor = successor->left;
            }

            root->data = successor->data;                   // Copy successor value
            deleteNodeHelper(root->right, successor->data); // Delete successor
        }
    }

    void deletenode(int value)
    {  //did by changing the data of the root to delete
        deleteNodeHelper(root, value);
    }
    void inorderhelper(Node* curr){
        if(curr==NULL) return;
        inorderhelper(curr->left);
        std::cout<<" "<<curr->data<<" , ";
        inorderhelper(curr->right);
    }
    void inorder(){
        Node* temp=root;
        inorderhelper(temp);
    }
};

int main() {
    BinarySearchTree bst;

    // Insert values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal after inserts: ";
    bst.inorder();  
    std::cout << "\n";

    std::cout << "Minimum value: " << bst.min() << "\n";
    std::cout << "Maximum value: " << bst.max() << "\n";

    // Search
    std::cout << "Contains 40  ? " << (bst.contains(40) ? "YES" : "NO") << "\n";
    std::cout << "Contains 100 ? " << (bst.contains(100) ? "YES" : "NO") << "\n";

    // Delete nodes
    std::cout<<std::endl<< "Deleting 20...";
    bst.deletenode(20);

    std::cout<<std::endl<< "Deleting 30...\n";
    bst.deletenode(30);

    std::cout<<std::endl<< "Deleting 50...\n"; 
    bst.deletenode(50);

    std::cout<<std::endl<< "Inorder after deletions: ";
    bst.inorder();
    std::cout<<std::endl;

    return 0;
}