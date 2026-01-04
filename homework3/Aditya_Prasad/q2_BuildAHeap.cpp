// DS/Algo used - Heap

// Time Complexities -
// top() - O(1)
// insert() - O(logn)
// remove() - O(logn)

// Memory Complexity O(n)

// where n is the number of elements in the array

#include <bits/stdc++.h>
using namespace std;

class Heap {
    private:
      vector<int> arr; // the underlying array

    public:
      Heap(){
        arr.push_back(-1); // dummy element at index 0;
      }

      int top(){// returns the min (top) element in the heap
        int heapSize = arr.size() - 1;

        if (heapSize == 0){
            cout << "heap is empty" << endl;
            return -1;
        }

        cout << arr[1] << endl;
        return arr[1];
      }

      void insert(int x){// adds int x to the heap in the appropriate position
        arr.push_back(x);

        int arraySize = arr.size();
        int i = arraySize - 1;

        while(i > 1){
            int parent = i/2;

            if(arr[parent] > arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }else{
                return;
            }
        }
        
      }
      void remove(){ // removes the min (top) element in the heap
        int heapSize = arr.size() - 1;

        if (heapSize == 0){
            cout << "heap is empty" << endl;
            return;
        }
        
        arr[1] = arr.back();
        arr.pop_back();
        heapSize--;

        int i = 1;

        while(2*i <= heapSize){
            int leftChild = i*2;
            int rightChild = i*2 + 1;
            int smallest = i;

            if (leftChild <= heapSize && arr[leftChild] < arr[smallest])
            smallest = leftChild;

            if (rightChild <= heapSize && arr[rightChild] < arr[smallest])
                smallest = rightChild;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            }else{
                return;
            }
        }
    }
};

// Time Taken - 30 mins