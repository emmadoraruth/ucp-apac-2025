#include <iostream>
#include <string>
using namespace std;

// Process backspaces in a string (# means backspace)
string processBackspaces(string str) {
    string result;
    
    // Build result string while handling backspaces
    for(char ch : str) {
        if(ch != '#') {
            result.push_back(ch);
        } else if(!result.empty()) {
            result.pop_back();  // Remove last character for backspace
        }
    }
    
    return result;
}

// Compare two strings after processing backspaces
bool BackspaceStringCompare(string s1, string s2) {
    // Process both strings to handle backspaces
    string processed1 = processBackspaces(s1);
    string processed2 = processBackspaces(s2);
    
    // Quick length check for efficiency
    if(processed1.length() != processed2.length()) {
        return false;
    }
    
    // Compare characters one by one
    for(int i = 0; i < processed1.length(); i++) {
        if(processed1[i] != processed2[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    // Test cases with expected results
    cout << BackspaceStringCompare("abcdef###xyz", "abcw#xyz") << endl;           // Expected: 1 (true)
    cout << BackspaceStringCompare("Uber Career Prep", "u#Uber Careee#r Prep") << endl; // Expected: 1 (true)
    cout << BackspaceStringCompare("abcdef###xyz", "abcdefxyz###") << endl;       // Expected: 0 (false)
    cout << BackspaceStringCompare("a##c", "#a#c") << endl;                       // Expected: 1 (true)
    cout << BackspaceStringCompare("ab#c", "ad#c") << endl;                       // Expected: 1 (true)
    
    return 0;
}

// T.C = O(n + m) where n and m are lengths of input strings
// S.C = O(n + m) for processed strings
// Approach: Stack simulation using strings