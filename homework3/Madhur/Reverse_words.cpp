/*
Data Structure Used:
Array (vector), String

Approach:
Split the string into space-separated words, reverse the order of words,
and join them back using spaces.

Time Complexity:
- O(n), where n is the length of the string

Space Complexity:
- O(n)

Time Taken:
9 minutes
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        // Split string by spaces
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Join words back into a string
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};

int main() {
    Solution s;

    cout << s.reverseWords("Uber Career Prep") << endl;
    cout << s.reverseWords("Emma lives in Brooklyn, New York.") << endl;

    return 0;
}
