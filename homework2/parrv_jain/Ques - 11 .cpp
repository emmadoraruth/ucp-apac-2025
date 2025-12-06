// Check if a doubly linked list is a palindrome.
// Method: two-pointer compare from head and tail.
// Time: O(n). Space: O(1).

#include <bits/stdc++.h>
using namespace std;

struct DNode {
    long long val;
    DNode* prev;
    DNode* next;
    DNode(long long v) : val(v), prev(nullptr), next(nullptr) {}
};

DNode* buildDList(const vector<long long>& vals) {
    if (vals.empty()) return nullptr;
    DNode* head = new DNode(vals[0]);
    DNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        DNode* node = new DNode(vals[i]);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    return head;
}

bool isPalindrome(DNode* head) {
    if (!head) return true;
    // find tail
    DNode* tail = head;
    while (tail->next) tail = tail->next;
    // compare
    while (head != tail && head->prev != tail) {
        if (head->val != tail->val) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void freeDList(DNode* head) {
    while (head) {
        DNode* nx = head->next;
        delete head;
        head = nx;
    }
}

int main() {
    ifstream file("input11.txt");
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
        int n;
        file >> n;
        vector<long long> vals;
        for (int i = 0; i < n; ++i) {
            long long x; file >> x;
            vals.push_back(x);
        }

        DNode* head = buildDList(vals);
        bool ans = isPalindrome(head);

        cout << "Test Case " << tc << ": " << (ans ? "YES" : "NO") << "\n";

        freeDList(head);
    }
    return 0;
}