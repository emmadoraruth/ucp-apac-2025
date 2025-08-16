// Problem Statement
/* Given a string, return a string that contains only the first occurrence of each character in the string */

// Time Complexity: O(n), n is the length of the string
// Space Complexity: O(n) for the set and result string

#include <bits/stdc++.h>
using namespace std;

string firstOccur(string s){

    unordered_set<char> out;
    string result = "";

    for(int i = 0; i < s.size(); i++){
        if(out.find(s[i]) == out.end()){
            // find function is O(1) average time, returns end() iterator when element not there.
            out.insert(s[i]);
            result += s[i];
        }
    }
   
    return result;
}

int main(){
    string result;
    vector <string> input;
    input =  {"abracadabra", "Uber Career Prep", "zzyzx"};  

    for(auto str : input){
        result = firstOccur(str);
        cout << result << endl;
    }
}

// Started the assignment with this question, have the intial intuition from the problem statement that I need to use a set because no repetition that also not ordered because of O(1) average time complexity.

// Took 25-30 mins (most of the time spent to figure out and searching the syntax, logic was straightforward)