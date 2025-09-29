/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to check if two strings are k-anagrams
bool kAnagrams(string s1, string s2, int k) {
    if (s1.size() != s2.size()) return false;

    vector<int> count(26, 0);

    // Count characters in s1
    for (char c : s1) if (isalpha(c)) count[c - 'a']++;

    // Decrement counts using s2
    for (char c : s2) if (isalpha(c)) count[c - 'a']--;

    // Count total positive differences
    int diff = 0;
    for (int c : count) if (c > 0) diff += c;

    return diff <= k;
}

// Test cases
int main() {
    cout << (kAnagrams("apple", "peach", 1) ? "True" : "False") << endl;    // Expected: False
    cout << (kAnagrams("apple", "peach", 2) ? "True" : "False") << endl;    // Expected: True
    cout << (kAnagrams("cat", "dog", 3) ? "True" : "False") << endl;        // Expected: True
    cout << (kAnagrams("debit curd", "bad credit", 1) ? "True" : "False") << endl; // Expected: True
    cout << (kAnagrams("baseball", "basketball", 2) ? "True" : "False") << endl;  // Expected: False
    return 0;
}
