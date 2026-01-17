#include <iostream>
using namespace std;

//it took around 20 min
// Technique: Linked list fixed-distance two-pointer
// Time complexity: O(n), where n is the number of nodes in the list
// Space complexity: O(1) extra space

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

Node* insertAtBack(Node* head, int val) {
    Node* newNode = createNode(val);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* moventhlasttofront(Node* head, int n) {
    if (!head || n <= 0) return head;

    Node* fast = head;
    for (int i = 0; i < n; ++i) {
        if (!fast) {
            return head;
        }
        fast = fast->next;
    }

    Node* slow = head;
    Node* prev = nullptr;

    while (fast) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev == nullptr) {
        return head;
    }

    prev->next = slow->next;
    slow->next = head;
    head = slow;
    return head;
}

int main() {
    Node* head1 = nullptr;
    head1 = insertAtBack(head1, 1);
    head1 = insertAtBack(head1, 2);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 4);
    head1 = insertAtBack(head1, 5);

    int k = 2;
    int l = 1;

    printList(head1);
    head1 = moventhlasttofront(head1, k);
    printList(head1);
    cout << endl;

    Node* head2 = nullptr;
    head2 = insertAtBack(head2, 10);
    head2 = insertAtBack(head2, 20);
    head2 = insertAtBack(head2, 30);

    printList(head2);
    head2 = moventhlasttofront(head2, l);
    printList(head2);
    cout << endl;

    return 0;

}
