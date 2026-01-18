// Technique Used: Doubly linked list forward-backward two-pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
// Time Spent: 13 minutes
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
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
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;

    while (right->next) right = right->next;

    while (left != right && left->prev != right) {
        if (left->value != right->value) return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    vector<int> v1 = {9, 2, 4, 2, 9};
    vector<int> v2 = {9, 12, 4, 2, 9};

    Node* list1 = makeList(v1);
    Node* list2 = makeList(v2);

    cout << (isPalindrome(list1) ? "True" : "False") << endl;
    cout << (isPalindrome(list2) ? "True" : "False") << endl;

    return 0;
}


