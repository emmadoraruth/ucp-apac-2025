// Remove duplicates from a sorted singly linked list.
// Method: iterate once, unlink duplicate nodes as encountered.
// Time: O(n). Space: O(1).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    long long val;
    ListNode* next;
    ListNode(long long v) : val(v), next(nullptr) {}
};

// build list from vector of values
ListNode* buildList(const vector<long long>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// remove duplicates from sorted list (in-place)
ListNode* removeDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp; // free duplicate node
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// print list to stdout
void printList(ListNode* head) {
    if (!head) {
        cout << "EMPTY";
        return;
    }
    bool first = true;
    for (ListNode* p = head; p; p = p->next) {
        if (!first) cout << ' ';
        cout << p->val;
        first = false;
    }
}

int main() {
    ifstream file("input9.txt");
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

        ListNode* head = buildList(vals);
        head = removeDuplicates(head);

        cout << "Test Case " << tc << ": ";
        printList(head);
        cout << "\n";

        // free remaining nodes
        ListNode* cur = head;
        while (cur) {
            ListNode* nx = cur->next;
            delete cur;
            cur = nx;
        }
    }

    return 0;
}