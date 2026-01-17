#include <iostream>
#include <string>
using namespace std;

// T.C = O(n)
// S.C = O(1)
// Approach: Process each string to simulate backspaces and then compare the results.
// TIMETAKEN:30MINS

bool BackspaceStringCompare(string s, string t)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 && s[i] == '#')
        {
            s.erase(i, 1);
            i = i - 2;
        }
        if (i>0 && s[i] == '#')
        {
            s.erase(i - 1, 2);
            i = i - 2;
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (i == 0 && t[i] == '#')
        {
            t.erase(i, 1);
            i = i - 2;
        }
        if (i > 0 && t[i] == '#')
        {
            t.erase(i - 1, 2);
            i = i - 2;
        }
    }
    return s == t;
}
int main(){

    cout << (BackspaceStringCompare("abcde", "abcde") ? "True" : "False") << endl; // Expected: True
    cout << (BackspaceStringCompare("Uber Career Prep", "u#Uber Careee#r Prep") ? "True" : "False") << endl; // Expected: True
    cout << (BackspaceStringCompare("abcdef###xyz", "abcw#xyz") ? "True" : "False") << endl; // Expected: True
    cout << (BackspaceStringCompare("abcdef###xyz", "abcdefxyz###") ? "True" : "False") << endl; // Expected: False

}