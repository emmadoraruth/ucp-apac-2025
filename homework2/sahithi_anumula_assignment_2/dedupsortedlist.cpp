#include <iostream>
using namespace std;

//It took around 25 min to complete
// Technique: Linked list fast-slow two-pointer
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

Node* dedupsortedlist(Node* head) {
    if (!head) return head;

    Node* slow = head;       
    Node* fast = head->next; 

    while (fast) {
        if (fast->data == slow->data) {
            Node* dup = fast;
            fast = fast->next;
            slow->next = fast;
            delete dup;
        } else {
            slow = fast;
            fast = fast->next;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head1 = nullptr;
    head1 = insertAtBack(head1, 1);
    head1 = insertAtBack(head1, 1);
    head1 = insertAtBack(head1, 2);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 4);
    head1 = insertAtBack(head1, 4);

    printList(head1);
    head1 = dedupsortedlist(head1);
    printList(head1);
    cout << endl;

    Node* head2 = nullptr;
    head2 = insertAtBack(head2, 5);
    head2 = insertAtBack(head2, 5);
    head2 = insertAtBack(head2, 5);
    head2 = insertAtBack(head2, 5);

    printList(head2);
    head2 = dedupsortedlist(head2);
    printList(head2);
    cout << endl;

    Node* head3 = nullptr;
    head3 = insertAtBack(head3, 1);
    head3 = insertAtBack(head3, 2);
    head3 = insertAtBack(head3, 3);
    head3 = insertAtBack(head3, 4);

    printList(head3);
    head3 = dedupsortedlist(head3);
    printList(head3);
    cout << endl;

    return 0;
}
