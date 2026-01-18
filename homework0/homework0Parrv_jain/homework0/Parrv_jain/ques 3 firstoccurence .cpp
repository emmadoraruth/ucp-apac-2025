//Time complexity - O(n)
//Space complexity - O(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeduplicates(string s){
    
    unordered_set<char> element; 
    string result;

    for(char c : s){
        if (element.find(c) == element.end()){
            element.insert(c);
            result = result + c; 
        }
    }
    return result;
}

int main() {
    string s = "zzyzx";
    cout << removeduplicates(s);
}

//Time taken - 20 min