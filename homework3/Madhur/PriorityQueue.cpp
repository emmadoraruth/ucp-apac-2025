/*
Approach:
Implement a Priority Queue using a Max Heap where elements are stored as
(string, priority) pairs and ordering is maintained based on priority.

Time Complexity:
- Insert: O(log n)
- Remove: O(log n)
- Top: O(1)
- Space: O(n)

Practical Time Taken:
16 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<pair<string, int>> arr;   // (element, priority)

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent].second < arr[index].second) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = arr.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && arr[left].second > arr[largest].second)
                largest = left;

            if (right < n && arr[right].second > arr[largest].second)
                largest = right;

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    string top() {
        if (arr.empty()) {
            cout << "Priority Queue is empty\n";
            return "";
        }
        return arr[0].first;
    }

    void insert(string x, int weight) {
        arr.push_back({x, weight});
        heapifyUp(arr.size() - 1);
    }

    void remove() {
        if (arr.empty()) {
            cout << "Priority Queue is empty\n";
            return;
        }

        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty())
            heapifyDown(0);
    }

    void printPQ() {
        for (auto &p : arr)
            cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert("jobA", 2);
    pq.insert("jobB", 8);
    pq.insert("jobC", 5);
    pq.insert("jobD", 1);

    cout << "Priority Queue: ";
    pq.printPQ();

    cout << "Top element: " << pq.top() << endl;

    pq.remove();
    cout << "After removing top: ";
    pq.printPQ();

    return 0;
}
