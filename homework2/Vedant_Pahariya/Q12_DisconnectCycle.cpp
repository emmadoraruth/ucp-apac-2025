// Given a singly linked list, disconnect the cycle, if one exists.

// Technique used: Linked list Fast-slow two pointer approach 
// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(1) as we are using only constant extra space

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* disconnect(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle using Floyd’s Cycle-Finding Algorithm
    bool hasCycle = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            hasCycle = true;
            break;
        }
    }

    // If no cycle, return the original list
    if(!hasCycle){
        return head;
    }

    // Step 2: Find the start of the cycle
    slow = head;
    Node* prev = NULL; // To keep track of the node before the meeting point
    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Disconnect the cycle
    if(prev != NULL){
        prev->next = NULL;
    }

    return head;
}

// First approach came into my mind was using a hash set to store all visited nodes and if we encounter a node that is already in the set, we can disconnect the cycle by setting the next pointer of the previous node to NULL. However, this approach uses O(n) extra space.

// Then, I knew that I can detect the cycle using the fast and slow pointer technique in O(n) time and O(1) space. But the challenge was to find the starting point of the cycle and disconnect it which I wasn't sure of how to do without using extra space. By searching this and taking help from google, I came to know to do this by resetting one pointer to the head and moving both pointers one step at a time until they meet again. The previous pointer keeps track of the node before the meeting point, allowing us to disconnect the cycle efficiently.
