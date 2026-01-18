/*
technique  used: 
- Linked list fast–slow two-pointer
- Linked list reset/catch-up two-pointer

time complexity: O(n)
space complexity: O(1)
*/
// time spent: 18 minutes 

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int x) : value(x), next(NULL) {}
};

void disconnectCycle(Node* head) {
    if (!head || !head->next) return;

    Node* slowPtr = head;
    Node* fastPtr = head;

    while (fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) break;
    }

    if (!fastPtr || !fastPtr->next) return;

    slowPtr = head;
    while (slowPtr != fastPtr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    Node* cycleStart = slowPtr;
    Node* loopPtr = cycleStart;

    while (loopPtr->next != cycleStart) {
        loopPtr = loopPtr->next;
    }

    loopPtr->next = NULL;
}

Node* buildList(const vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void createCycle(Node* head, int fromValue, int toValue) {
    Node* fromNode = NULL;
    Node* toNode = NULL;
    Node* current = head;

    while (current) {
        if (current->value == fromValue) fromNode = current;
        if (current->value == toValue)   toNode = current;
        current = current->next;
    }
    if (fromNode && toNode) fromNode->next = toNode;
}

bool hasCycle(Node* head) {
    Node* slowPtr = head;
    Node* fastPtr = head;
    while (fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) return true;
    }
    return false;
}

int main() {

    vector<int> arr1 = {10,18,12,9,11,4};
    Node* head1 = buildList(arr1);
    createCycle(head1, 4, 12);

    cout << "Before: " << (hasCycle(head1) ? "Cycle" : "No cycle") << "\n";
    disconnectCycle(head1);
    cout << "After : " << (hasCycle(head1) ? "Cycle" : "No cycle") << "\n";
    cout << "Test 1: " << (!hasCycle(head1) ? "PASS" : "FAIL") << "\n\n";

    vector<int> arr2 = {10,18,12,9,11,4};
    Node* head2 = buildList(arr2);
    createCycle(head2, 4, 4);

    cout << "Before: " << (hasCycle(head2) ? "Cycle" : "No cycle") << "\n";
    disconnectCycle(head2);
    cout << "After : " << (hasCycle(head2) ? "Cycle" : "No cycle") << "\n";
    cout << "Test 2: " << (!hasCycle(head2) ? "PASS" : "FAIL") << "\n";

    return 0;
}



