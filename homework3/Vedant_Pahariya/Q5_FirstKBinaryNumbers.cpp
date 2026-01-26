// Given a number, k, return an array of the first k binary numbers, represented as strings.

#include <bits/stdc++.h>
using namespace std;

string binary(int i){

    if(i==0){
        return "0";
    }
    string s;
    while(i>0){
        s.push_back('0' + i%2);
        i/=2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<string> bin(int k){
    vector<string> result;

    for(int i=0; i<k; i++){
        result.push_back(binary(i));
    }

    return result;
}

// the first approach came to my mind is to have a loop from 0 to k-1, convert every number to binary and append it to the result, I couldn't think of its approch using the graph and after looking into it got the following approach

vector<string> bin2(int k) {
    vector<string> result;
    queue<string> q;

    q.push("1");

    for (int i = 0; i < k; ++i) {
        string curr = q.front();
            q.pop();
        result.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }
    
    return result;
}

int main(){
    int test = 10;
    vector<string> res = bin(test);

    for(auto it : res){
        cout << it << "\n";
    }
}