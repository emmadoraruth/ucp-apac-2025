#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    private:
        vector<pair<string,int>> arr;

    public:
        int top(){
            if(arr.size()==0) return -1;
            return arr[0].second;
        }

        void insert(string x,int weight){
            arr.push_back({x,weight});
            int i=arr.size()-1;
            while(i>0){
                int parent=(i-1)/2;
                if(arr[parent].second < arr[i].second){
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
                int largest=i;

                if(left<n && arr[left].second > arr[largest].second)
                    largest=left;
                if(right<n && arr[right].second > arr[largest].second)
                    largest=right;

                if(largest!=i){
                    swap(arr[i],arr[largest]);
                    i=largest;
                }
                else break;
            }
        }
};

int main(){
    PriorityQueue pq;
    pq.insert("a",10);
    pq.insert("b",30);
    pq.insert("c",20);

    cout<<pq.top()<<endl;
    pq.remove();
    cout<<pq.top()<<endl;

    return 0;
}
