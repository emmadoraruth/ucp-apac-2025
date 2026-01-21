#include <iostream>
#include <string>
using namespace std;

// Priority Queue implementation using Max Heap

// Time Complexity: 
//insert O(log n)
// remove O(log n)
// top O(1)

// Space Complexity: O(n)


class PriorityQueue {
public:
    pair<string, int> arr[100];  // Array to store (element, priority) pairs
    int size;                     // Current number of elements

    // Constructor 
    PriorityQueue() {
        arr[0] = {"", -1};  
        size = 0;
    }

    // Returns the highest priority (first) element in the PQ
    // Time Complexity: O(1)
    string top() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return "";
        }
        return arr[1].first;  
    }

    
    // Time Complexity: O(log n) - heapify up
    void insert(string x, int weight) {
        size = size + 1;
        int index = size;
        arr[index] = {x, weight};

        
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent].second < arr[index].second) {  
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    // Removes the highest priority (first) element in the PQ
    // Time Complexity: O(log n) - heapify down
    void remove() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Heapify down
        int index = 1;
        while (index < size) {
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left < size && arr[index].second < arr[left].second) {
                swap(arr[index], arr[left]);
                index = left;
            }
            else if (right < size && arr[index].second < arr[right].second) {
                swap(arr[index], arr[right]);
                index = right;
            }
            else {
                return;
            }
        }
    }

    // Helper function to display the priority queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 1; i <= size; i++) {
            cout << "(" << arr[i].first << ", " << arr[i].second << ") ";
        }
        cout << endl;
    }

    // Helper function to get current size
    int getSize() {
        return size;
    }
};

int main() {
    PriorityQueue pq;

    // Test Case 1: Basic insertions
    // Insert elements with different priorities
    cout << "Test Case 1: Basic Operations" << endl;
    pq.insert("task1", 3);
    pq.insert("task2", 1);
    pq.insert("task3", 5);
    pq.insert("task4", 2);
    pq.insert("task5", 4);
    
    pq.display();
    cout << "Top element: " << pq.top() << endl;  // Expected: task3 (priority 5)
    
    // Test Case 2: Remove operations
    cout << "Test Case 2: Remove highest priority elements" << endl;
    pq.remove();
    cout << "After removing top: ";
    pq.display();
    cout << "New top element: " << pq.top() << endl;  // Expected: task5 (priority 4)
    
    pq.remove();
    cout << "After removing top again: ";
    pq.display();
    cout << "New top element: " << pq.top() << endl;  // Expected: task1 (priority 3)
    
    // Test Case 3: Insert after removals
    cout << "Test Case 3: Insert after removals" << endl;
    pq.insert("urgent", 10);
    pq.display();
    cout << "Top element: " << pq.top() << endl;  // Expected: urgent (priority 10)
    
    // Test Case 4: Remove all elements
    cout << "Test Case 4: Remove all elements" << endl;
    while (pq.getSize() > 0) {
        cout << "Removing: " << pq.top() << endl;
        pq.remove();
    }
    
    // Test Case 5: Operations on empty queue
    cout << "Test Case 5: Operations on empty queue" << endl;
    pq.top();     // Expected: "Priority Queue is empty"
    pq.remove();  // Expected: "Priority Queue is empty"

    return 0;
}
