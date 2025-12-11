// Given a binary tree, create a deep copy. Return the root of the new tree.

// Using Pre-order traversal
Node* copyTree(Node* root) {
    if(root == NULL){
        return NULL;
    }

    // create new node
    Node* newNode = new Node();
    newNode->data = root->data;

    // recursively copy left and right subtrees
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Using Post-order traversal
Node* copyTree(Node* root) {
    if(root == NULL){
        return NULL;
    }

    // process left subtree first
    Node* leftCopy = copyTree(root->left);
    
    // process right subtree second
    Node* rightCopy = copyTree(root->right);
    
    // process current node last
    Node* newNode = new Node();
    newNode->data = root->data;
    newNode->left = leftCopy;
    newNode->right = rightCopy;

    return newNode;
}