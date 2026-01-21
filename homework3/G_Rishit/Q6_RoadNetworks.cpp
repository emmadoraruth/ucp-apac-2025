#include<bits/stdc++.h>
using namespace std;

class DSU{
private:
    map<string,string>parent;
    map<string,int>rank;
public:
    void make(string x){
        if(!parent.count(x)){
            parent[x]=x;
            rank[x]=0;
        }
    }
    string find(string x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(string x,string y){
        string px=find(x);
        string py=find(y);
        if(px==py) return;
        if(rank[px]<rank[py]) swap(px,py);
        parent[py]=px;
        if(rank[px]==rank[py]) rank[px]++;
    }
    int countComponents(){
        set<string>roots;
        for(auto p:parent){
            roots.insert(find(p.first));
        }
        return roots.size();
    }
};

int main(){
    ifstream in("Q6_input.txt");
    ofstream out("Q6_output.txt");
    
    int n;
    in>>n;
    
    DSU dsu;
    for(int i=0;i<n;i++){
        string town;
        in>>town;
        dsu.make(town);
    }
    
    int m;
    in>>m;
    
    for(int i=0;i<m;i++){
        string t1,t2;
        in>>t1>>t2;
        dsu.unite(t1,t2);
    }
    
    int networks=dsu.countComponents();
    out<<"Number of road networks: "<<networks<<endl;
    
    in.close();
    out.close();
    return 0;
}
