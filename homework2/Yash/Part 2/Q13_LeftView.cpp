// Q13: Left View, Technique Used: Level-order (breadth-first) traversal
// Time Complexity: O(n), Space Complexity: O(n), Time Taken: 38 minutes

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Binary Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};


vector<int> leftView(Node* root) {
    vector<int> result;

    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            // The first element at this level is the left view element
            if (i == 0) {
                result.push_back(cur->val);
            }

            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }

    return result;
}

// Print vector
void printVec(vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}



int main() {
    cout << "Testing LeftView\n";

    // Example 1 Tree:
   

    Node* root1 = new Node(7);
    root1->left = new Node(8);
    root1->right = new Node(3);

    
    root1->right->left = new Node(9);
    root1->right->left->left = new Node(20);
    root1->right->right = new Node(13);
    root1->right->right->left = new Node(14);

    root1->right->right->left->right = new Node(15);

    vector<int> res1 = leftView(root1);
    cout << "Left View Example 1: ";
    printVec(res1);  // expected [7, 8, 9, 20, 15]


    // Example 2 Tree:
  
    Node* root2 = new Node(7);
    root2->left = new Node(20);
    root2->right = new Node(4);

    root2->left->left = new Node(15);
    root2->left->right = new Node(6);
    root2->right->left = new Node(8);
    root2->right->right = new Node(11);

    vector<int> res2 = leftView(root2);
    cout << "Left View Example 2: ";
    printVec(res2);  // expected [7, 20, 15]

    return 0;
}
