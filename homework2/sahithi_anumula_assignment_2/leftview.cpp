#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//It took around 25 min to complete
// Technique: Level-order (breadth-first) traversal
// Time complexity: O(n), where n is the number of nodes in the tree
// Space complexity: O(n) for the queue + output array (in worst case, a full level)

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

vector<int> leftview(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            if (i == 0) {
                result.push_back(curr->data);
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }

    return result;
}

void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]";
}

int main() {
    Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
    root1->right->right = createNode(6);
    root1->left->left->left = createNode(7);

    inorderPrint(root1);
    vector<int> lv1 = leftview(root1);
    printVector(lv1);
    cout << "\n\n";

    Node* root2 = createNode(10);
    inorderPrint(root2);
    vector<int> lv2 = leftview(root2);
    printVector(lv2);
    cout << "\n\n";

    return 0;
}
