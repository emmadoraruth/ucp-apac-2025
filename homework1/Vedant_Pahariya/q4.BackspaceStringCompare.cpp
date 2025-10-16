// Problem Statement
/* Given two strings representing series of keystrokes, determine whether the resulting text is the same. Backspaces are represented by the '#' character so "x#" results in the empty string (""). */

// Technique: Two Pointers
// Time Complexity: O(n + m), n and m are the lengths of the two strings
// Space Complexity: O(1), just used few variables like pointers and counters

#include <bits/stdc++.h>
using namespace std;

bool Backspace(string str1, string str2){
    int i = str1.size() -1;
    int j = str2.size() -1;
    int back =0;

    while(i >= 0 || j >= 0){
        back =0;
        //  cout<< i<<j<<"\n";
        while(i>=0 && str1[i] == '#'){
            i--;
            back++;
        }
        i = i - back;

        back = 0;
        while(j>=0 && str2[j] == '#'){
            j--;
            back++;
        }
        j = j - back;

        if(str1[i] == str2[j]){
            i--;
            j--;
            continue;
        }
        if(i<0 && j<0) break;
        return false;
    }
    return true;
}

int main(){
    string str1 = "abcde";
    string str2 = "abcde";
    cout << boolalpha << Backspace(str1, str2) << "\n";
    
    str1 = "Uber Career Prep";
    str2 = "u#Uber Careee#r Prep";
    cout << Backspace(str1, str2) << "\n";

    str1 = "abcdef###xyz";
    str2 = "abcw#xyz";
    cout << Backspace(str1, str2) << "\n";

    str1 = "abcdef###xyz";
    str2 = "abcdefxyz###";
    cout << Backspace(str1, str2) << "\n";
}

// Thinking Process
/*
1. Used two pointers, one for each string, starting from the end of the strings.
2. Also use two counters to keep track of the number of backspaces encountered in each string.
3. Iterate through both strings until both pointers are less than 0.
4. For each string, move the pointer backwards while counting the number of backspaces encountered.
5. After processing the backspaces, compare the characters at the current pointers of both strings.
6. If the characters are the same, move both pointers backwards and continue the process.
7. If the characters are different, return false.
8. If both pointers are less than 0, return true.
*/
