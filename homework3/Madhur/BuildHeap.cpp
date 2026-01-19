/*
Approach:
Use an array-based Min Heap and maintain heap order using heapify-up on insertion
and heapify-down on deletion.

Time Complexity:
- Insert: O(log n)
- Remove: O(log n)
- Top: O(1)
- Space: O(n)

Practical Time Taken:
27 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> arr;   // underlying array

    // Restores heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Restores heap property after removal
    void heapifyDown(int index) {
        int n = arr.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < n && arr[left] < arr[smallest])
                smallest = left;

            if (right < n && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != index) {
                swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Returns the minimum element
    int top() {
        if (arr.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Inserts an element into the heap
    void insert(int x) {
        arr.push_back(x);
        heapifyUp(arr.size() - 1);
    }

    // Removes the minimum element
    void remove() {
        if (arr.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty())
            heapifyDown(0);
    }

    // Utility function to print heap (for testing)
    void printHeap() {
        for (int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    Heap h;

    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(0);

    cout << "Heap elements: ";
    h.printHeap();

    cout << "Top element: " << h.top() << endl;

    h.remove();
    cout << "Heap after removing top: ";
    h.printHeap();

    return 0;
}
