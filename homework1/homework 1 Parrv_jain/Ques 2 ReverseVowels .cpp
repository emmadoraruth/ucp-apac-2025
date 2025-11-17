#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// TC = O(n)
// SC = O(1)
// Approach: Use two pointers to find vowels from both ends and swap them until they meet in the middle.
// TIMETAKEN:20MINS

bool isVowel(char ch) {
    string vowels = "aeiou";
    return vowels.find(tolower(ch)) != string::npos;
}

string ReverseVowels(string &s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (isVowel(s[left]) && !isVowel(s[right])) {
            right--;
        }
        else if (!isVowel(s[left]) && isVowel(s[right])) {
            left++;
        }
        else if (!isVowel(s[left]) && !isVowel(s[right])) {
            left++;
            right--;
        }
        else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

int main() {
    string s1 = "Uber Career Prep";
    string s2 = "xyz";
    string s3 = "flamingo";

    cout << ReverseVowels(s1) << endl;    // Expected: "eber Ceraer PrUp"
    cout << ReverseVowels(s2) << endl;    // Expected: "xyz"
    cout << ReverseVowels(s3) << endl;    // Expected: "flominga"
}

