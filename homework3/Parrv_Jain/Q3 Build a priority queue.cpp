#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<pair<string, int>> arr;   // (element, priority)

    // Heapify up (for insert)
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

    // Heapify down (for remove)
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
    // Returns the highest priority element
    string top() {
        if (arr.empty())
            throw runtime_error("Priority Queue is empty");
        return arr[0].first;
    }

    // Insert element with priority
    void insert(string x, int weight) {
        arr.push_back({x, weight});
        heapifyUp(arr.size() - 1);
    }

    // Remove highest priority element
    void remove() {
        if (arr.empty())
            return;

        arr[0] = arr.back();
        arr.pop_back();
        heapifyDown(0);
    }
};

int main() {
    PriorityQueue pq;

    pq.insert("task1", 3);
    pq.insert("task2", 10);
    pq.insert("task3", 5);

    cout << pq.top() << endl;  
    pq.remove();
    cout << pq.top() << endl;  

    return 0;
}
