// Technique Used: Linked list fixed-distance two-pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
// Time Spent : 16 minutes 22 seconds 
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

Node* removeDuplicates(Node* head) {
    if (!head) return head;

    Node* curr = head;

    while (curr && curr->next) {
        if (curr->value == curr->next->value) {
            Node* duplicate = curr->next;
            curr->next = curr->next->next;
            delete duplicate;
        } else {
            curr = curr->next;
        }
    }

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
    vector<int> v1 = {1, 2, 2, 4, 5, 5, 5, 10, 10};
    vector<int> v2 = {8, 8, 8, 8};

    Node* list1 = makeList(v1);
    Node* list2 = makeList(v2);

    list1 = removeDuplicates(list1);
    list2 = removeDuplicates(list2);

    printList(list1);
    printList(list2);

    return 0;
}


