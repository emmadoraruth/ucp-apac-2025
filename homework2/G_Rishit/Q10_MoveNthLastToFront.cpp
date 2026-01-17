// Move the nth-from-last node to the front of a singly linked list.
// Method: two-pointer (advance fast by n, then move fast+slow together to find predecessor of target), relink.
// Time: O(n). Space: O(1).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    long long val;
    ListNode* next;
    ListNode(long long v) : val(v), next(nullptr) {}
};

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

ListNode* moveNthLastToFront(ListNode* head, int n) {
    if (!head || n <= 0) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = head;
    // advance fast n steps
    for (int i = 0; i < n; ++i) {
        if (!fast) {
            // n > length -> do nothing
            return head;
        }
        fast = fast->next;
    }
    ListNode* slow = &dummy;
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    // slow->next is the target node (nth from last)
    ListNode* target = slow->next;
    if (!target) return head;       // shouldn't happen
    if (target == head) return head; // already front

    // remove target
    slow->next = target->next;
    // move to front
    target->next = head;
    head = target;
    return head;
}

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

void freeList(ListNode* head) {
    while (head) {
        ListNode* nx = head->next;
        delete head;
        head = nx;
    }
}

int main() {
    ifstream file("input10.txt");
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    int T;
    if (!(file >> T)) {
        cout << "Invalid input: first token should be number of test cases.\n";
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
        int n;
        file >> n;

        ListNode* head = buildList(vals);
        head = moveNthLastToFront(head, n);

        cout << "Test Case " << tc << ": ";
        printList(head);
        cout << "\n";

        freeList(head);
    }
    return 0;
}
