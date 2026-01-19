//Question 7: ReverseWords
//Given a string, return the string with the order of the space-separated words reversed.

//Examples: 
// Input: "Uber Career Prep" 
// Output: "Prep Career Uber" 
// Input: "Emma lives in Brooklyn, New York." 
// Output: "York. New Brooklyn, in lives Emma" 

//-------------------------------------------------------------------------------------------------------

//one approach:could be that i make a new string and store in it using some pointer manupalation which
//start from end

//another approach:start from 0th index and start making the string word and pushing into the stack and 
//when iteration ends i can insert into a new string by popping word from the stack


#include<bits/stdc++.h>
using namespace std;
string reverseWords(string str){
    string word="";
    stack<string> st;
    for(auto& ch:str){
        if(ch==' '){                // some word end then we also need to push a space and after
                                    //last word is pushed no need of space.
            st.push(word);
            st.push(" ");
            word="";
        }
        else{
            word.push_back(ch);
        }
    }
    st.push(word);
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s1="Uber Career Prep";
    string reversewords1=reverseWords(s1);
    cout<<"After Reversing the words string becomes : "<<reversewords1<<endl;
    string s2="Emma lives in Brooklyn, New York.";
    string reversewords2=reverseWords(s2);
    cout<<"After Reversing the words string becomes : "<<reversewords2<<endl;
}