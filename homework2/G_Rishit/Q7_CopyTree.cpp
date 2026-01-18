// Copy a binary tree (deep copy) and print the copied tree's inorder traversal.
// Method: build tree from level-order tokens ("N" = null), clone recursively, then inorder-traverse.
// Time: O(n), Space: O(h) fot recursion stack.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long v) : val(v), left(nullptr), right(nullptr) {}
};

// build tree from level-order tokens where "N" means null
Node* buildTree(const string &line) {
    stringstream ss(line);
    vector<string> tokens;
    string tok;
    while (ss >> tok) tokens.push_back(tok);
    if (tokens.empty() || tokens[0] == "N") return nullptr;
    Node* root = new Node(stoll(tokens[0]));
    queue<Node*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        Node* cur = q.front(); q.pop();
        if (i < tokens.size()) {
            if (tokens[i] != "N") {
                cur->left = new Node(stoll(tokens[i]));
                q.push(cur->left);
            }
            i++;
        }
        if (i < tokens.size()) {
            if (tokens[i] != "N") {
                cur->right = new Node(stoll(tokens[i]));
                q.push(cur->right);
            }
            i++;
        }
    }
    return root;
}

// deep copy (recursive)
Node* clone(Node* root) {
    if (!root) return nullptr;
    Node* n = new Node(root->val);
    n->left = clone(root->left);
    n->right = clone(root->right);
    return n;
}

// collect inorder traversal
void inorderCollect(Node* root, vector<long long> &out) {
    if (!root) return;
    inorderCollect(root->left, out);
    out.push_back(root->val);
    inorderCollect(root->right, out);
}

int main() {
    ifstream file("input7.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    int T;
    if (!(file >> T)) {
        cout << "Invalid input: first token should be the number of test cases.\n";
        return 1;
    }
    string line;
    getline(file, line); // consume remaining newline after T

    for (int tc = 1; tc <= T; ++tc) {
        // read next non-empty line
        string treeLine;
        while (getline(file, treeLine)) {
            bool allSpace = true;
            for (char c : treeLine) if (!isspace((unsigned char)c)) { allSpace = false; break; }
            if (!allSpace) break;
        }
        if (treeLine.size() == 0) treeLine = "N"; // treat missing as empty tree

        Node* orig = buildTree(treeLine);
        Node* cp = clone(orig);

        vector<long long> vals;
        inorderCollect(cp, vals);
        cout << "Test Case " << tc << ": ";
        if (vals.empty()) cout << "N";
        else {
            for (size_t i = 0; i < vals.size(); ++i) {
                if (i) cout << ' ';
                cout << vals[i];
            }
        }
        cout << "\n";

        
    }

    return 0;
}