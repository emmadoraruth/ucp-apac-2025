// Compute the left view of a binary tree.
// Method: BFS (level-order), take the first node at each level.
// Time: O(n). Space: O(n).

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

vector<long long> leftView(Node* root) {
    vector<long long> out;
    if (!root) return out;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = (int)q.size();
        for (int i = 0; i < sz; ++i) {
            Node* cur = q.front(); q.pop();
            if (i == 0) out.push_back(cur->val); // first node of this level
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return out;
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ifstream file("input13.txt");
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
        // read next non-empty line
        string treeLine;
        while (getline(file, treeLine)) {
            bool allSpace = true;
            for (char c : treeLine) if (!isspace((unsigned char)c)) { allSpace = false; break; }
            if (!allSpace) break;
        }
        if (treeLine.size() == 0) treeLine = "N";

        Node* root = buildTree(treeLine);
        vector<long long> lv = leftView(root);

        cout << "Test Case " << tc << ": ";
        if (lv.empty()) {
            cout << "N";
        } else {
            for (size_t i = 0; i < lv.size(); ++i) {
                if (i) cout << ' ';
                cout << lv[i];
            }
        }
        cout << "\n";

        freeTree(root);
    }

    return 0;
}
