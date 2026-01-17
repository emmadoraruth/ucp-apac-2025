#include <iostream>
using namespace std;

//it took around 30 min to complete
// Technique: Linked list fast-slow two-pointer combined with reset/catch-up two-pointer
// Time complexity: O(n), where n is the number of nodes
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

void disconnectcycle(Node* head) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;
    bool cycleExists = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycleExists = true;
            break;
        }
    }

    if (!cycleExists) {
        cout << "No cycle detected.\n";
        return;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* cycleStart = slow;
    cout << "Cycle detected at node with value: " << cycleStart->data << "\n";
    Node* ptr = cycleStart;
    while (ptr->next != cycleStart) {
        ptr = ptr->next;
    }
    ptr->next = nullptr;
    cout << "Cycle disconnected.\n";
}

void printList(Node* head) {
    Node* temp = head;
    int limit = 20; 
    while (temp && limit--) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << (temp ? "..." : "NULL") << "\n";
}

int main() {
    Node* head1 = nullptr;
    head1 = insertAtBack(head1, 1);
    head1 = insertAtBack(head1, 2);
    head1 = insertAtBack(head1, 3);
    head1 = insertAtBack(head1, 4);
    head1 = insertAtBack(head1, 5);

    Node* temp = head1;
    Node* cycleStart = nullptr;
    int count = 0;
    while (temp->next) {
        if (count == 2) {
            cycleStart = temp; 
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycleStart; 
    printList(head1);
    disconnectcycle(head1);
    printList(head1);
    cout << endl;

    Node* head2 = nullptr;
    head2 = insertAtBack(head2, 10);
    head2 = insertAtBack(head2, 20);
    head2 = insertAtBack(head2, 30);
    printList(head2);
    disconnectcycle(head2);
    printList(head2);

    return 0;
}
