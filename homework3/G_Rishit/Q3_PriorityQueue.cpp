#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
private:
    vector<pair<string,int>>arr;
    void heapifyUp(int idx){
        while(idx>0){
            int par=(idx-1)/2;
            if(arr[par].second<arr[idx].second){
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
            int largest=idx;
            if(left<n&&arr[left].second>arr[largest].second)
                largest=left;
            if(right<n&&arr[right].second>arr[largest].second)
                largest=right;
            if(largest!=idx){
                swap(arr[idx],arr[largest]);
                idx=largest;
            }else{
                break;
            }
        }
    }
public:
    string top(){
        if(arr.empty())
            throw runtime_error("PQ empty");
        return arr[0].first;
    }
    void insert(string x,int w){
        arr.push_back({x,w});
        heapifyUp(arr.size()-1);
    }
    void remove(){
        if(arr.empty())
            throw runtime_error("PQ empty");
        arr[0]=arr.back();
        arr.pop_back();
        if(!arr.empty())
            heapifyDown(0);
    }
};

int main(){
    ifstream in("Q3_input.txt");
    ofstream out("Q3_output.txt");
    
    PriorityQueue pq;
    int n;
    in>>n;
    
    for(int i=0;i<n;i++){
        string op;
        in>>op;
        
        if(op=="INSERT"){
            string x;
            int w;
            in>>x>>w;
            pq.insert(x,w);
            out<<"Inserted "<<x<<" with priority "<<w<<endl;
        }
        else if(op=="REMOVE"){
            try{
                pq.remove();
                out<<"Removed top element"<<endl;
            }catch(exception& e){
                out<<"Error: "<<e.what()<<endl;
            }
        }
        else if(op=="TOP"){
            try{
                string top=pq.top();
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
