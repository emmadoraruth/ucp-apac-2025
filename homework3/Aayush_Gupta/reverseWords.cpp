#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    string currentWord="";
    stack<string> wordStack;

    for(char ch:s){
        if(ch!=' '){
            currentWord.push_back(ch);
        }
        else{
            if(currentWord.length()!=0){
                wordStack.push(currentWord);
                currentWord="";
            }
        }
    }

    if(currentWord.length()!=0){
        wordStack.push(currentWord);
    }

    string result="";
    while(!wordStack.empty()){
        result+=wordStack.top();
        wordStack.pop();
        if(!wordStack.empty()){
            result.push_back(' ');
        }
    }
    return result;
}

int main(){
    string s;
    getline(cin,s);
    cout<<reverseWords(s)<<endl;
    return 0;
}
