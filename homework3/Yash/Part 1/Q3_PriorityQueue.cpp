// Question 3 : Priority Queue
// Time Taken : 20 minutes

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<pair<string, int>> arr;

    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;

            
            if(arr[parent].second >= arr[index].second){
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
            int largest = index;

            if(left < n && arr[left].second > arr[largest].second){
                largest = left;
            }

            if(right < n && arr[right].second > arr[largest].second){
                largest = right;
            }

            if(largest == index){
                break;
            }

            swap(arr[index], arr[largest]);
            index = largest;
        }
    }

public:
    string top(){
        if(arr.empty()){
            return ""; 
        }
        return arr[0].first;
    }

    void insert(string x, int weight){
        arr.push_back({x, weight});
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
    PriorityQueue pq;

    pq.insert("A", 2);
    pq.insert("B", 5);
    pq.insert("C", 1);
    pq.insert("D", 4);

    cout << pq.top() << endl; 

    pq.remove();
    cout << pq.top() << endl; 

    pq.remove();
    cout << pq.top() << endl; 

    return 0;
}
