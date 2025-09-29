// Problem Statement
/* Given a string, reverse the order of the vowels in the string. */

// Technique: Two-pointer approach
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) - as we are using a fixed set of vowels

#include <bits/stdc++.h>
using namespace std;

string reverse(string s){
    int left = 0;
    int right = s.size() - 1;

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    // unordered_set is implemented using hash table in C++ and here we don't care about the order of vowels, just need O(1) average time complexity for lookups.

    auto vowelEnd = vowels.end();
    // defining it here to avoid calling end() function again and again in the loop which will increase the number of instructions at assembly level.

    while(left < right){
        auto leftIt = vowels.find(s[left]);
        auto rightIt = vowels.find(s[right]);

        if(leftIt != vowelEnd && rightIt != vowelEnd){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        else if(leftIt == vowelEnd){
            left++;
        }
        else{
            right--;
        }
    }

    return s;
}

int main(){
    string s;

    s = "Uber Career Prep";
    cout << reverse(s) << "\n"; 

    s = "xyz";
    cout << reverse(s) << "\n";

    s = "flamingo";
    cout << reverse(s) << "\n";
}
