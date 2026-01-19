#include <iostream>
using namespace std;
#include <vector>

class Heap {
    public:
    int arr[100];
    int size;
    Heap (){
    arr[0]=-1;
    size=0;
}
int top(){
    if(size==0){
        cout<<"Heap is empty"<<endl;
        return -1;
    }
    return arr[1];
}
void insert(int val){
    size=size+1;
    int index=size;
    arr[index]=val;

    while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else{
            return;
        }
    }
}

void remove(){
    if(size==0){
        cout<<"Heap is empty"<<endl;
        return;
    }
    arr[1]=arr[size];
    size--;

    int index=1;
    while(index<size){
        int left=2*index;
        int right=2*index+1;

        if(left<size && arr[index]<arr[left]){
            swap(arr[index],arr[left]);
            index=left;
        }
        else if(right<size && arr[index]<arr[right]){
            swap(arr[index],arr[right]);
            index=right;
        }
        else{
            return;
        }
    }
}
};

int main() {
    Heap h;
    h.size=0;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.remove();

    for(int i=1;i<=h.size;i++){
        cout<<h.arr[i]<<" ";
    }
    return 0;
}