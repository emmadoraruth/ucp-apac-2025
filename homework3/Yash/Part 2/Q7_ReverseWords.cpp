// Question 7 : Reverse Words in a String
// Time Taken : 15 minutes

#include <iostream>
#include <vector>
using namespace std;

string ReverseWords(string s){
    vector<string> words;
    string curr = "";

    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            words.push_back(curr);
            curr = "";
        } else {
            curr += s[i];
        }
    }

    
    words.push_back(curr);

    
    string result = "";
    for(int i = words.size() - 1; i >= 0; i--){
        result += words[i];
        if(i != 0){
            result += " ";
        }
    }

    return result;
}

int main(){

    string testcase1 = "Uber Career Prep";
    string testcase2 = "Emma lives in Brooklyn, New York.";
    string testcase3 = "Hello";
    string testcase4 = "";

    cout << ReverseWords(testcase1) << endl;
    cout << ReverseWords(testcase2) << endl;
    cout << ReverseWords(testcase3) << endl;
    cout << ReverseWords(testcase4) << endl;

    return 0;
}
