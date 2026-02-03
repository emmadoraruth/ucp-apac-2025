// Given a string, return the string with the order of the space-separated words reversed.

// Time Complexity: O(N), where N is the length of the input string
// Space Complexity; O(N), for the stack

#include <bits/stdc++.h>
using namespace std;

string revers(string sent){
    string out;
    stack<string> temp;
    string word;
    for(auto character : sent){
        if(character == ' '){
            if(word != ""){
                temp.push(word);
            }
            word = "";
        }
        else{
            word = word + character;
        }
    }
    out = word + " ";

    while(!temp.empty()){
        out = out + temp.top() + " ";
        temp.pop();
    }
    return out;
}

int main(){
    string test1 = "Uber     Career Prep";
    cout << revers(test1) << "\n";

    string test2 = "Emma lives in Brooklyn, New York.";
    cout << revers(test2) << "\n";
}