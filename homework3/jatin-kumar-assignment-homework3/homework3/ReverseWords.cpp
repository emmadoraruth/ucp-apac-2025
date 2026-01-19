

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// Approach:reverse the words in the string using a stack
// tc: O(n)
// sc: O(n)
// time taken: 20 min



string ReverseWords(string s){
    stack<string> words;
    string curr="";

    for(int i=0; i<s.length();i++ ) {
        if(s[i]==' '){
            words.push(curr);
            curr="";
        }
        else{
            curr+=s[i];
        }
    }
    // push the last word
    words.push(curr);
   
    string result="";
    while(!words.empty()){
        result+=words.top();
        words.pop();
        if(!words.empty()){
            result+=" ";
        }
    }
    return result;

}
int main(){
    // Test Case 1
    // Input: "Uber Career Prep"
    // Expected Output: "Prep Career Uber"
    string s1 = "Uber Career Prep";
    cout << "Test Case 1: " << ReverseWords(s1) << endl;
    
    // Test Case 2
    // Input: "Emma lives in Brooklyn, New York."
    // Expected Output: "York. New Brooklyn, in lives Emma"
    string s2 = "Emma lives in Brooklyn, New York.";
    cout << "Test Case 2: " << ReverseWords(s2) << endl;
    
    return 0;
}