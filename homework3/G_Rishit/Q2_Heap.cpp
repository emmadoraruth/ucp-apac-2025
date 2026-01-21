#include<bits/stdc++.h>
using namespace std;

class Heap{
private:
    vector<int>arr;
    void heapifyUp(int idx){
        while(idx>0){
            int par=(idx-1)/2;
            if(arr[par]>arr[idx]){
                swap(arr[par],arr[idx]);
                idx=par;
            }else{
                break;
            }
        }
    }
    void heapifyDown(int idx){
        int n=arr.size();
        while(true){
            int left=2*idx+1;
            int right=2*idx+2;
            int smallest=idx;
            if(left<n&&arr[left]<arr[smallest])
                smallest=left;
            if(right<n&&arr[right]<arr[smallest])
                smallest=right;
            if(smallest!=idx){
                swap(arr[idx],arr[smallest]);
                idx=smallest;
            }else{
                break;
            }
        }
    }
public:
    int top(){
        if(arr.empty())
            throw runtime_error("Heap empty");
        return arr[0];
    }
    void insert(int x){
        arr.push_back(x);
        heapifyUp(arr.size()-1);
    }
    void remove(){
        if(arr.empty())
            throw runtime_error("Heap empty");
        arr[0]=arr.back();
        arr.pop_back();
        if(!arr.empty())
            heapifyDown(0);
    }
};

int main(){
    ifstream in("Q2_input.txt");
    ofstream out("Q2_output.txt");
    
    Heap h;
    int n;
    in>>n;
    
    for(int i=0;i<n;i++){
        string op;
        in>>op;
        
        if(op=="INSERT"){
            int x;
            in>>x;
            h.insert(x);
            out<<"Inserted "<<x<<endl;
        }
        else if(op=="REMOVE"){
            try{
                h.remove();
                out<<"Removed top element"<<endl;
            }catch(exception& e){
                out<<"Error: "<<e.what()<<endl;
            }
        }
        else if(op=="TOP"){
            try{
                int top=h.top();
                out<<"Top element: "<<top<<endl;
            }catch(exception& e){
                out<<"Error: "<<e.what()<<endl;
            }
        }
    }
    
    in.close();
    out.close();
    return 0;
}
