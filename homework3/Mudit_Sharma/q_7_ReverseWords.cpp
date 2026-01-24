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

//time complexity  :O(n) 
//space complexity :O(n) by using a stack and answer string 

#include<bits/stdc++.h>
std::string reverseWords(std::string str){
    std::string word="";
    std::stack<std::string> st;
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
    std::string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    std::string s1="Uber Career Prep";
    std::string reversewords1=reverseWords(s1);
    std::cout<<"After Reversing the words string becomes : "<<reversewords1<<std::endl;
    std::string s2="Emma lives in Brooklyn, New York.";
    std::string reversewords2=reverseWords(s2);
    std::cout<<"After Reversing the words string becomes : "<<reversewords2<<std::endl;
}