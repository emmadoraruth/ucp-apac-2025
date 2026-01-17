#include<bits/stdc++.h>
using namespace std;

class Heap{
    private:
        vector<int> arr;

    public:
        int top(){
            if(arr.size()==0) return -1;
            return arr[0];
        }

        void insert(int x){
            arr.push_back(x);
            int i=arr.size()-1;
            while(i>0){
                int parent=(i-1)/2;
                if(arr[parent]>arr[i]){
                    swap(arr[parent],arr[i]);
                    i=parent;
                }
                else break;
            }
        }

        void remove(){
            if(arr.size()==0) return;
            arr[0]=arr.back();
            arr.pop_back();
            int i=0;
            int n=arr.size();
            while(true){
                int left=2*i+1;
                int right=2*i+2;
                int smallest=i;

                if(left<n && arr[left]<arr[smallest])
                    smallest=left;
                if(right<n && arr[right]<arr[smallest])
                    smallest=right;

                if(smallest!=i){
                    swap(arr[i],arr[smallest]);
                    i=smallest;
                }
                else break;
            }
        }
};

int main(){
    Heap h;
    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(2);

    cout<<h.top()<<endl;
    h.remove();
    cout<<h.top()<<endl;

    return 0;
}
