// Check if a binary tree is a BST.
// Method: build tree from level-order tokens ("N" = null), then perform inorder traversal ensuring node values are strictly increasing.
// Time: O(n). Space: O(h) recursion stack (h = tree height).

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

// inorder check: values must be strictly increasing
bool inorderCheck(Node* root, long long &prev, bool &hasPrev) {
    if (!root) return true;
    if (!inorderCheck(root->left, prev, hasPrev)) return false;
    if (hasPrev && !(prev < root->val)) return false; // strictly increasing
    prev = root->val;
    hasPrev = true;
    return inorderCheck(root->right, prev, hasPrev);
}

bool isBST(Node* root) {
    long long prev = 0;
    bool hasPrev = false;
    return inorderCheck(root, prev, hasPrev);
}

int main() {
    ifstream file("input8.txt");
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
    getline(file, line); // consume newline after T

    for (int tc = 1; tc <= T; ++tc) {
        // read next non-empty line
        string treeLine;
        while (getline(file, treeLine)) {
            bool allSpace = true;
            for (char c : treeLine) if (!isspace((unsigned char)c)) { allSpace = false; break; }
            if (!allSpace) break;
        }
        if (treeLine.size() == 0) treeLine = "N";

        Node* root = buildTree(treeLine);
        bool ans = isBST(root);
        cout << "Test Case " << tc << ": " << (ans ? "YES" : "NO") << "\n";

    }

    return 0;
}