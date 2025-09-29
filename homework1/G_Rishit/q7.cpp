#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkKAnagram(string str1, string str2, int k) {
    if (str1.length() != str2.length()) return false;

    vector<int> charFreq(26, 0);

    // Count character frequency in first string
    for (char ch : str1) {
        if (isalpha(ch)) charFreq[ch - 'a']++;
    }

    // Subtract character frequency using second string
    for (char ch : str2) {
        if (isalpha(ch)) charFreq[ch - 'a']--;
    }

    // Calculate total positive differences
    int totalDiff = 0;
    for (int freq : charFreq) {
        if (freq > 0) totalDiff += freq;
    }

    return totalDiff <= k;
}

int main() {
    cout << (checkKAnagram("apple", "peach", 1) ? "True" : "False") << endl;    // Expected: False
    cout << (checkKAnagram("apple", "peach", 2) ? "True" : "False") << endl;    // Expected: True
    cout << (checkKAnagram("cat", "dog", 3) ? "True" : "False") << endl;        // Expected: True
    cout << (checkKAnagram("debit curd", "bad credit", 1) ? "True" : "False") << endl; // Expected: True
    cout << (checkKAnagram("baseball", "basketball", 2) ? "True" : "False") << endl;  // Expected: False
    
    return 0;
}

// T.C = O(n)
// S.C = O(1)
// Approach: Character frequency counting with fixed-size array