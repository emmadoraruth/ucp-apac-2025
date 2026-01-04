// DS/Algo used - Stack

// Time Complexity O(n)

// Memory Complexity O(n)

// where n is the size of given string 

#include <bits/stdc++.h>
using namespace std;

string ReverseWords(string words){
    stack<string> st;
    string word;

    for (char c : words){
        if (c == ' '){
            st.push(word);
            word = "";
        }else{
            word += c;
        }
    }

    st.push(word);

    string ReversedString;

    while (!st.empty()){
        ReversedString += st.top();
        st.pop();
        if(!st.empty()) ReversedString += " ";
    }

    return ReversedString;
}

int main(){
    cout << ReverseWords("Uber Career Prep") << endl;
    cout << ReverseWords("Emma lives in Brooklyn, New York.");
}

// Time Taken - 9 min