#include <iostream>
using namespace std;

//it took around 20 min to complete
// Technique: Doubly linked list forward-backward two-pointer
// Time complexity: O(n), where n is the number of nodes in the list
// Space complexity: O(1) extra space

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

Node* insertAtBack(Node* head, int val) {
    Node* newNode = createNode(val);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

bool ispalindrome(Node* head) {
    if (!head || !head->next) {
        return true;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

void printForward(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head1 = nullptr;
    head1 = insertAtBack(head1, 1);
    head1 = insertAtBack(head1, 2);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 2);
    head1 = insertAtBack(head1, 1);

    printForward(head1);
    cout << "Is palindrome? " << (ispalindrome(head1) ? "Yes" : "No") << "\n\n";

    Node* head2 = nullptr;
    head2 = insertAtBack(head2, 4);
    head2 = insertAtBack(head2, 5);
    head2 = insertAtBack(head2, 5);
    head2 = insertAtBack(head2, 4);

    printForward(head2);
    cout << "Is palindrome? " << (ispalindrome(head2) ? "Yes" : "No") << "\n\n";

    return 0;
}
