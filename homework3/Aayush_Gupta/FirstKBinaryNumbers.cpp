#include<bits/stdc++.h>
using namespace std;

vector<string> firstKBinaryNumbers(int k){
    vector<string> result;
    queue<string> q;
    q.push("0");
    q.push("1");

    while(result.size()<k){
        string curr=q.front();
        q.pop();
        result.push_back(curr);
        q.push(curr+"0");
        q.push(curr+"1");
    }
    return result;
}

int main(){
    int k;
    cin>>k;

    vector<string> ans=firstKBinaryNumbers(k);
    for(string s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}
