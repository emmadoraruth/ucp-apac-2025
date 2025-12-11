struct Node {
  int data;
  Node* left;
  Node* right;
};

class BinarySearchTree {
  private:
    Node* root;

  public:
  // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // returns the minimum value in the BST.  O(logn) time.
    int min(){
        if(root == NULL){
            return 0;
        }

         Node* current = root;
        while(current->left != NULL) {
            current = current->left;
        }
        return current->data;
    }

    // returns the maximum value in the BST.  O(logn) time.
    int max(){
        if(root == NULL){
            return 0;
        }

        Node* current = root;
        while(current->right != NULL) {
            current = current->right;
        }
        return current->data;
    }

    // returns a boolean indicating whether val is present in the BST.  O(logn) time. 
    bool contains(int val){
        Node* current = root;
        while(current != NULL) {
            if(current->data == val) {
                return true;
            } else if(current->data > val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    
    // creates a new Node with data val in the appropriate location. For simplicity, do not allow duplicates. If val is already present, insert is a no-op. O(logn) time.
    void insert(int val){
        // create new node
        Node* newNode = new Node();
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;

        //find the point where to insert
        Node* current = root;

        while(current != NULL){
            if(current->data == val){
                return; // no-op for duplicate
            } else if (current->data > val){
                if(current->left == NULL){
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } 
            else {
                if(current->right == NULL){
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
        }
        root = newNode; 
    }   
    
    // deletes the Node with data val, if it exists. O(logn) time.
    // we can't use delete keyword because it is a reserved keyword in C++
    // deletes the Node with data val, if it exists. O(logn) time. took help of SUing tnr fxn
void deleteNode(int val) {
    if(root == NULL) {
        return;
    }
    
    Node* current = root;
    Node* parent = NULL;
    
    // Find the node to delete and its parent
    while(current != NULL && current->data != val) {
        parent = current;
        if(val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // Node not found
    if(current == NULL) {
        return;
    }
    
    // Case 1: Node has no children (leaf node)
    if(current->left == NULL && current->right == NULL) {
        if(parent == NULL) {
            // Deleting root
            root = NULL;
        } else if(parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete current;
    }
    // Case 2: Node has only right child
    else if(current->left == NULL) {
        if(parent == NULL) {
            // Deleting root
            root = current->right;
        } else if(parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        delete current;
    }
    // Case 3: Node has only left child
    else if(current->right == NULL) {
        if(parent == NULL) {
            // Deleting root
            root = current->left;
        } else if(parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        delete current;
    }
    // Case 4: Node has two children
    else {
        // Find inorder successor (smallest node in right subtree)
        Node* successorParent = current;
        Node* successor = current->right;
        
        while(successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        
        // Copy successor's data to current node
        current->data = successor->data;
        
        // Delete successor (it has at most one right child)
        if(successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }
        delete successor;
    }
}
}

