//Question 5: FirstKBinaryNumbers
//Given a number, k, return an array of the first k binary numbers, represented as strings.

//-------------------------------------------------------------------------------------------------------
//I used the Binary Tree to implement this questions as in binary number 
//each we insert 0 and 1 to get next two numbers
//-------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//using binary tree

//time complexity  :O(n)
//space complexity :O(n)  in storing the binary numbers
vector<string> firstKBinaryNumbers(int k) {
    vector<string> result;
    if (k <= 0) return result;

    queue<string> q;
    q.push("1");

    for (int i = 0; i < k; i++) {
        string curr = q.front();
        q.pop();

        result.push_back(curr);

        q.push(curr + "0");
        q.push(curr + "1");
    }

    return result;
}
int main(){
    int k1=4;
    int k2=7;
    vector<string> binnos1=firstKBinaryNumbers(k1);
    vector<string> binnos2=firstKBinaryNumbers(k2);
    for(auto& i:binnos1){
        cout<<i<<" , ";
    }
    cout<<endl;
    for(auto& i:binnos2){
        cout<<i<<" , ";
    }
    cout<<endl;
}
