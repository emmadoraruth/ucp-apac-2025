// Question 2 : Build a Min Heap
// Time Taken : 35 minutes

#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> arr;

    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;

            if(arr[parent] <= arr[index]){
                break;
            }

            swap(arr[parent], arr[index]);
            index = parent;
        }
    }

    void heapifyDown(int index){
        int n = arr.size();

        while(true){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if(left < n && arr[left] < arr[smallest]){
                smallest = left;
            }

            if(right < n && arr[right] < arr[smallest]){
                smallest = right;
            }

            if(smallest == index){
                break;
            }

            swap(arr[index], arr[smallest]);
            index = smallest;
        }
    }

public:
    int top(){
        if(arr.empty()){
            return -1; 
        }
        return arr[0];
    }

    void insert(int x){
        arr.push_back(x);
        heapifyUp(arr.size() - 1);
    }

    void remove(){
        if(arr.empty()){
            return;
        }

        arr[0] = arr.back();
        arr.pop_back();

        if(!arr.empty()){
            heapifyDown(0);
        }
    }
};

int main(){
    
    // Testing Heap Class
    
    Heap h;

    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(1);

    cout << h.top() << endl; 

    h.remove();
    cout << h.top() << endl; 

    h.remove();
    cout << h.top() << endl; 

    return 0;
}
