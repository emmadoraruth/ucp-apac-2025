#include <iostream>
#include <string>
using namespace std;

// Check if character is a vowel (case insensitive)
bool checkVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// Function to reverse the vowels in the string
string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    
    while (left < right) {
        if (!checkVowel(s[left])) {
            left++;
        } else if (!checkVowel(s[right])) {
            right--;
        } else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

// Test cases to check the function
int main() {
    cout << reverseVowels("Uber Career Prep") << endl;    // Expected: "eber Ceraer PrUp"
    cout << reverseVowels("xyz") << endl;                 // Expected: "xyz"
    cout << reverseVowels("flamingo") << endl;            // Expected: "flominga"
    cout << reverseVowels("AEIOU") << endl;               // Expected: "UOIEA"
    cout << reverseVowels("") << endl;                    // Expected: "" 
    cout << reverseVowels("a") << endl;                   // Expected: "a" 
    cout << reverseVowels("b") << endl;                   // Expected: "b" 
    cout << reverseVowels("Hello World") << endl;         // Expected: "Hollo Werld"
    
    return 0;
}

// T.C = O(n)
// S.C = O(1)
// Approach: Two-pointer technique