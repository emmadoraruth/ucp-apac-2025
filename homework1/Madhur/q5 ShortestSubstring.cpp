/*
Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int shortestSubstring(string s, string required) {
    unordered_map<char, int> need, window;
    for (char c : required) need[c]++;

    int haveCount = 0, needCount = need.size();
    int left = 0, minLen = 1000000; // Large number

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c]) haveCount++;

        while (haveCount == needCount) {
            if (right - left + 1 < minLen) minLen = right - left + 1;
            char leftChar = s[left];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar]) haveCount--;
            left++;
        }
    }

    return (minLen == 1000000) ? 0 : minLen;
}

// Test cases are shown below
int main() {
    cout << shortestSubstring("abracadabra", "abc") << endl; // Output: 4
    cout << shortestSubstring("zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx") << endl; // Output: 10
    cout << shortestSubstring("dog", "god") << endl; // Output: 3
    return 0;
}
