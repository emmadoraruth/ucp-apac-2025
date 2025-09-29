/*
Technique: Forward/backward two-pointer
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

// Helper function is used to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to reverse the vowels in the string
string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (!isVowel(s[left])) left++;
        else if (!isVowel(s[right])) right--;
        else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
}

// Test cases to check the function
int main() {
    cout << reverseVowels("Uber Career Prep") << endl; // Expected: eber Ceraer PrUp
    cout << reverseVowels("xyz") << endl;              // Expected: xyz
    cout << reverseVowels("flamingo") << endl;         // Expected: flominga
    cout << reverseVowels("AEIOU") << endl;            // Expected: UOIEA
    cout << reverseVowels("") << endl;                 // Expected: (empty string)
    return 0;
}
