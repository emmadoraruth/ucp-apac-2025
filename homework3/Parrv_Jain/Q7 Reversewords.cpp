#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty())
            words.push_back(word);

        reverse(words.begin(), words.end());

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
