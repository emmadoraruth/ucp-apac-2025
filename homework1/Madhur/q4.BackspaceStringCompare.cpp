/*
Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

// Helper function to process backspaces and return final index
int getNextValidIndex(const string &s, int index) {
    int backspace = 0;
    while (index >= 0) {
        if (s[index] == '#') {
            backspace++;
            index--;
        } else if (backspace > 0) {
            backspace--;
            index--;
        } else {
            break;
        }
    }
    return index;
}

// Function to compare two strings with backspaces
bool backspaceCompare(string s, string t) {
    int i = s.size() - 1, j = t.size() - 1;

    while (i >= 0 || j >= 0) {
        i = getNextValidIndex(s, i);
        j = getNextValidIndex(t, j);

        if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
        if ((i >= 0) != (j >= 0)) return false;

        i--;
        j--;
    }
    return true;
}

// Test cases
int main() {
    cout << (backspaceCompare("abcde", "abcde") ? "True" : "False") << endl;            // Expected: True
    cout << (backspaceCompare("Uber Career Prep", "u#Uber Careee#r Prep") ? "True" : "False") << endl; // Expected: True
    cout << (backspaceCompare("abcdef###xyz", "abcw#xyz") ? "True" : "False") << endl;  // Expected: True
    cout << (backspaceCompare("abcdef###xyz", "abcdefxyz###") ? "True" : "False") << endl; // Expected: False
    return 0;
}
