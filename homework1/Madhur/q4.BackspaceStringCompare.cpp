/*
Time Complexity: O(n + m)
Space Complexity: O(n+m)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> chs;
    stack<char> cht;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '#')
            chs.push(s[i]);
        else if(!chs.empty())
            chs.pop();
    }

    for(int i = 0; i < t.size(); i++) {
        if(t[i] != '#')
            cht.push(t[i]);
        else if(!cht.empty())
            cht.pop();
    }

    return chs == cht;
}

int main() {
    cout << boolalpha;

    cout << backspaceCompare("abcde", "abcde") << endl;                 // true
    cout << backspaceCompare("Uber Career Prep", "u#Uber Careee#r Prep") << endl; // true
    cout << backspaceCompare("abcdef###xyz", "abcw#xyz") << endl;       // true
    cout << backspaceCompare("abcdef###xyz", "abcdefxyz###") << endl;   // false

    return 0;
}
