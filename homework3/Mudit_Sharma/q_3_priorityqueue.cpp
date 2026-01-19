#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<pair<string,int>> arr;

    // Heapify up (after insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            // MAX heap: compare priorities
            if (arr[parent].second < arr[index].second) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down (after removal)
    void heapifyDown(int index) {
        int size = arr.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && arr[left].second > arr[largest].second)
                largest = left;

            if (right < size && arr[right].second > arr[largest].second)
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
    // Returns highest priority element
    string top() {
        if (arr.empty()) {
            cout << "Priority Queue is empty\n";
            return "";
        }
        return arr[0].first;
    }

    // Insert element with priority
    void insert(string x, int weight) {
        arr.push_back({x, weight});
        heapifyUp(arr.size() - 1);
    }

    // Remove highest priority element
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

    // Debug helper
    void printPQ() {
        for (auto &p : arr)
            cout << "(" << p.first << ", " << p.second << ") ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert("task1", 3);
    pq.insert("task2", 5);
    pq.insert("task3", 1);
    pq.insert("task4", 10);

    pq.printPQ();

    cout << "Top: " << pq.top() << endl;

    pq.remove();
    cout << "After remove:\n";
    pq.printPQ();

    cout << "Top: " << pq.top() << endl;
}
