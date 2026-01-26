// Write a min heap class according to the following API using an array as the underlying data structure. (A max heap has the same implementation; you simply need to flip the direction of the comparators.) For simplicity, you can assume that the heap holds integers rather than generic comparables.

class Heap {
    private:
      vector<int> arr; // the underlying array

    public:
        // returns the min (top) element in the heap
      int top(){
            if(arr.size() == 0){
                cout << "Heap is empty\n";
            }
            return arr[0];
      } 

      // adds int x to the heap in the appropriate position
      void insert(int x){
            arr.push_back(x);
            int index = arr.size() - 1;
            while(index > 0){
                int parent = (index - 1) / 2;
                if(arr[parent] > arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    break;
                }
            }
      }

      // removes the min (top) element in the heap
      void remove(){
            if(arr.size() == 0){
                cout << "Heap is empty\n";
                return;
            }
            arr[0] = arr[arr.size() - 1];
            arr.pop_back();
            int index = 0;
            int size = arr.size();
            while(index < size){
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int smallest = index;

                if(left < size && arr[left] < arr[smallest]){
                    smallest = left;
                }
                if(right < size && arr[right] < arr[smallest]){
                    smallest = right;
                }
                if(smallest != index){
                    swap(arr[smallest], arr[index]);
                    index = smallest;
                } else {
                    break;
                }
            }
      }
}