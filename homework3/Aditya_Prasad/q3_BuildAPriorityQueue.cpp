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
      vector<pair<string,int>> arr; 

    public:
      Heap(){
        arr.push_back({"",-1}); // dummy element at index 0;
      }

      string top(){ 
        int heapSize = arr.size() - 1;

        if (heapSize == 0){
            cout << "heap is empty" << endl;
            return "";
        }

        return arr[1].first;
      }

      void insert(string x, int weight){ 
        arr.push_back({x, weight});

        int arraySize = arr.size();
        int i = arraySize - 1;

        while(i > 1){
            int parent = i/2;

            if(arr[parent].second < arr[i].second){
                swap(arr[parent], arr[i]);
                i = parent;
            }else{
                return;
            }
        }
        
      }
      void remove(){ 
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

            if (leftChild <= heapSize && arr[leftChild].second > arr[smallest].second)
            smallest = leftChild;

            if (rightChild <= heapSize && arr[rightChild].second > arr[smallest].second)
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

// Time Taken - 7 min