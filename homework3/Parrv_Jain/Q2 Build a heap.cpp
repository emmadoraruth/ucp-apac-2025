#include <bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> arr;   

    // Heapify up (for insert)
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

    // Heapify down (for remove)
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
    // Returns the min (top) element
    int top() {
        if (arr.empty())
            throw runtime_error("Heap is empty");
        return arr[0];
    }

    // Insert element into heap
    void insert(int x) {
        arr.push_back(x);
        heapifyUp(arr.size() - 1);
    }

    // Remove the min (top) element
    void remove() {
        if (arr.empty())
            return;

        arr[0] = arr.back();
        arr.pop_back();
        heapifyDown(0);
    }
};

int main() {
    Heap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(1);

    cout << "Min element: " << h.top() << endl; // 1
    h.remove();
    cout << "Min after remove: " << h.top() << endl; // 4

    return 0;
}
