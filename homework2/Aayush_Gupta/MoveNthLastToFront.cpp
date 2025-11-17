// Technique Used: Linked list fixed-distance two-pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
//// Time Spent: 14 minutes
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* makeList(vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int v : values) {
        Node* newNode = new Node(v);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

Node* moveNthLastToFront(Node* head, int k) {
    if (!head || k <= 0) return head;

    Node* lead = head;
    Node* follow = head;

    for (int i = 0; i < k; i++) {
        if (!lead) return head;
        lead = lead->next;
    }

    if (!lead) return head;

    while (lead->next) {
        lead = lead->next;
        follow = follow->next;
    }

    Node* target = follow->next;
    follow->next = follow->next->next;
    target->next = head;
    head = target;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {15, 2, 8, 7, 20, 9, 11, 6, 19};

    Node* list1 = makeList(values);
    Node* list2 = makeList(values);

    list1 = moveNthLastToFront(list1, 2);
    list2 = moveNthLastToFront(list2, 7);

    printList(list1);
    printList(list2);

    return 0;
}


