#include<bits/stdc++.h>
using namespace std;

string toBinary(int n){
    if(n==0) return "0";
    string bin="";
    while(n>0){
        bin=(char)('0'+(n%2))+bin;
        n/=2;
    }
    return bin;
}

int main(){
    ifstream in("Q5_input.txt");
    ofstream out("Q5_output.txt");
    
    int k;
    in>>k;
    
    out<<"[";
    for(int i=0;i<k;i++){
        out<<"\""<<toBinary(i)<<"\"";
        if(i<k-1) out<<", ";
    }
    out<<"]"<<endl;
    
    in.close();
    out.close();
    return 0;
}
