// Given two strings representing series of keystrokes, determine whether the resulting text is the same. Backspaces are represented by the '#' character so "x#" results in the empty string ("").

// Examples:
// eInput Strings: "abcde", "abcde"
// Output: True

// Input Strings: "Uber Career Prep", "u#Uber Careee#r Prep"
// Output: True

// Input Strings: "abcdef###xyz", "abcw#xyz"
// Output: True

// Input Strings: "abcdef###xyz", "abcdefxyz###"
// Output: False

//2:15-

//timetaken:10min
//Time complexity:O(n)
//Space Complexity:O(n)
#include<bits/stdc++.h>
using namespace std;
bool backspacecompare(string& s1,string& s2){
    stack<char> s;
    
    //for s1
    for(auto& i:s1){
        if(i=='#' && !s.empty()){
            s.pop();
        }
        else if(i!='#'){
            s.push(i);
        }
    }
    s1="";
    while(!s.empty()){
        s1.push_back(s.top());
        s.pop();
    }
    reverse(s1.begin(),s1.end());
    while(!s.empty()){
        s.pop();
    }
    //for s2
    for(auto& i:s2){
        if(i=='#' && !s.empty()){
            s.pop();
        }
        else if(i!='#'){
            s.push(i);
        }
    }
    s2="";
    while(!s.empty()){
        s2.push_back(s.top());
        s.pop();
    }
        reverse(s2.begin(),s2.end());
    //compare
    if(s1==s2)
       return true;
    return false;
}
int main(){
    
    string s1_1="abcde";
    string s1_2="abcde";
    bool issame1=backspacecompare(s1_1,s1_2);

    string s2_1="Uber Career Prep";
    string s2_2="u#Uber Careee#r Prep";
    bool issame2=backspacecompare(s2_1,s2_2);

    string s3_1="abcdef###xyz";
    string s3_2="abcw#xyz";
    bool issame3=backspacecompare(s3_1,s3_2);

    string s4_1="abcdef###xyz";
    string s4_2="abcdefxyz###";
    bool issame4=backspacecompare(s4_1,s4_2);
    
    cout<<"Result will be in the Format"<<endl;
    cout<<"1-->for same strings"<<endl<<"0-->for different strings"<<endl;
    cout<<"1 :- "<<issame1<<endl;
    cout<<"2 :- "<<issame2<<endl;
    cout<<"3 :- "<<issame3<<endl;
    cout<<"4:- "<<issame4<<endl;
}