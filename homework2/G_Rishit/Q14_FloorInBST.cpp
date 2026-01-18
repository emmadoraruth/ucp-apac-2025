// Return floor (greatest value <= target) in a BST.
// Method: iterative BST traversal — go left when node > target, record node and go right when node < target.
// Time: O(h) where h = tree height. Space: O(1).

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

bool findFloor(Node* root, long long target, long long &out) {
    bool found = false;
    long long best = LLONG_MIN;
    Node* cur = root;
    while (cur) {
        if (cur->val == target) {
            out = cur->val;
            return true;
        }
        if (cur->val < target) {
            if (!found || cur->val > best) {
                best = cur->val;
                found = true;
            }
            cur = cur->right;
        } else { // cur->val > target
            cur = cur->left;
        }
    }
    if (found) out = best;
    return found;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ifstream file("input14.txt");
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
    getline(file, line); // consume remainder of line after T

    for (int tc = 1; tc <= T; ++tc) {
        long long target;
        if (!(file >> target)) {
            cout << "Invalid input: expected target value for test case " << tc << ".\n";
            return 1;
        }
        getline(file, line); // consume remainder of line after target

        // read next non-empty line as tree level-order
        string treeLine;
        while (getline(file, treeLine)) {
            bool allSpace = true;
            for (char c : treeLine) if (!isspace((unsigned char)c)) { allSpace = false; break; }
            if (!allSpace) break;
        }
        if (treeLine.size() == 0) treeLine = "N";

        Node* root = buildTree(treeLine);
        long long ans = 0;
        bool ok = findFloor(root, target, ans);

        cout << "Test Case " << tc << ": ";
        if (ok) cout << ans;
        else cout << "NONE";
        cout << "\n";

        freeTree(root);
    }

    return 0;
}
