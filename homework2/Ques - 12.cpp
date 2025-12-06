// Detect and disconnect a cycle in a singly linked list.
// Method: Floyd's cycle detection to find meeting point, locate cycle start, then sever the link.
// Time: O(n). Space: O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

Node* buildListWithCycle(const vector<long long>& vals, int pos) {
    // pos: 0-based index where tail will connect; -1 => no cycle
    if (vals.empty()) return nullptr;
    vector<Node*> nodes;
    nodes.reserve(vals.size());
    for (long long v : vals) nodes.push_back(new Node(v));
    for (size_t i = 0; i + 1 < nodes.size(); ++i) nodes[i]->next = nodes[i+1];
    if (pos >= 0 && pos < (int)nodes.size()) nodes.back()->next = nodes[pos];
    return nodes[0];
}

// returns true if a cycle was detected and removed
bool detectAndRemoveCycle(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head;
    bool found = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { found = true; break; }
    }
    if (!found) return false;

    // find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* start = slow;
    // find the node just before start in the cycle
    Node* ptr = start;
    while (ptr->next != start) ptr = ptr->next;
    // break the cycle
    ptr->next = nullptr;
    return true;
}

void printList(Node* head) {
    if (!head) { cout << "EMPTY"; return; }
    bool first = true;
    for (Node* p = head; p; p = p->next) {
        if (!first) cout << ' ';
        cout << p->val;
        first = false;
    }
}

void freeList(Node* head) {
    while (head) {
        Node* nx = head->next;
        delete head;
        head = nx;
    }
}

int main() {
    ifstream file("input12.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    int T;
    if (!(file >> T)) {
        cout << "Invalid input: first token should be the number of test cases.\n";
        return 1;
    }

    for (int tc = 1; tc <= T; ++tc) {
        int m;
        file >> m;
        vector<long long> vals;
        for (int i = 0; i < m; ++i) {
            long long x; file >> x;
            vals.push_back(x);
        }
        int pos;
        file >> pos; // 0-based index for cycle start, -1 = no cycle

        Node* head = buildListWithCycle(vals, pos);
        bool removed = detectAndRemoveCycle(head);

        cout << "Test Case " << tc << ": ";
        printList(head);
        cout << " | " << (removed ? "CYCLE_REMOVED" : "NO_CYCLE") << "\n";

        freeList(head);
    }
    return 0;
}