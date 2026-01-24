//Question 2: Build a Heap (40 min max)
//Write a min heap class according to the following API using an array as the underlying data structure. 
//(A max heap has the same implementation; you simply need to flip the direction of the comparators.) 
//For simplicity, you can assume that the heap holds integers rather than generic comparables.


//-------------------------------------------------------------------------------------------------------
//Example:
// class Heap { 
//     private: 
//       array<int> arr; // the underlying array 
 
//     public: 
//       int top(); // returns the min (top) element in the heap 
//       void insert(int x); // adds int x to the heap in the appropriate position 
//       void remove(); // removes the min (top) element in the heap 
// }


#include <bits/stdc++.h>
class MinHeap {
private:
    std::vector<int> arr;

    // Heapify up (used after insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] > arr[index]) {
                std::swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down (used after removal)
    void heapifyDown(int index) {
        int size = arr.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != index) {
                std::swap(arr[index], arr[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Returns the minimum element
    int top() {
        if (arr.empty()){
            std::cout<<"Heap is empty";
            return -1;
            std::cout<<std::endl;
        }
        return arr[0];
    }

    // Insert a new element
    void insert(int x) {
        arr.push_back(x);
        heapifyUp(arr.size() - 1);
    }

    // Remove the minimum element
    void remove() {
        if (arr.empty()){
            std::cout<<"Heap is empty";
            return;
        }
        arr[0] = arr.back();
        arr.pop_back();

        if (!arr.empty())
            heapifyDown(0);
    }

    // Optional: for debugging
    void printHeap() {
        for (int x : arr)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main() {
    MinHeap h;

    // Insert elements
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(1);
    h.insert(20);

    std::cout << "Heap elements: ";
    h.printHeap();

    // Get minimum element
    std::cout << "Top (min element): " << h.top() << std::endl;

    // Remove minimum element
    h.remove();
    std::cout << "After removing top: ";
    h.printHeap();

    // Remove again
    h.remove();
    std::cout << "After removing again: ";
    h.printHeap();

    // Insert more elements
    h.insert(2);
    h.insert(8);
    std::cout << "After inserting 2 and 8: ";
    h.printHeap();

    std::cout << "Top (min element): " << h.top() << std::endl;
    return 0;
}
