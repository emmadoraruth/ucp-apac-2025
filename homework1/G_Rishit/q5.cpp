#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

int shortestSubstring(string s, string required) {
    unordered_map<char, int> reqCount;
    
    // Count frequency of each required character
    for(char c : required) {
        reqCount[c]++;
    }
    
    int left = 0, right = 0;
    int minLength = INT_MAX;
    int requiredChars = reqCount.size();
    int formed = 0;
    unordered_map<char, int> windowCount;
    
    while(right < s.length()) {
        char currentChar = s[right];
        windowCount[currentChar]++;
        
        // Check if current character completes a requirement
        if(reqCount.find(currentChar) != reqCount.end() && 
           windowCount[currentChar] == reqCount[currentChar]) {
            formed++;
        }
        
        // Try to minimize window when all requirements are met
        while(formed == requiredChars && left <= right) {
            minLength = min(minLength, right - left + 1);
            
            // Remove left character from window
            char leftChar = s[left];
            windowCount[leftChar]--;
            
            // Check if removing broke any requirement
            if(reqCount.find(leftChar) != reqCount.end() && 
               windowCount[leftChar] < reqCount[leftChar]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    cout << shortestSubstring("abracadabra", "abc") << endl;  // Expected: 4 ("brac")
    cout << shortestSubstring("zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx") << endl;  // Expected: 10
    cout << shortestSubstring("dog", "god") << endl;          // Expected: 3 ("dog")
    cout << shortestSubstring("a", "a") << endl;              // Expected: 1
    cout << shortestSubstring("abc", "d") << endl;            // Expected: 0 (no substring)
    
    return 0;
}

// T.C = O(n)
// S.C = O(k) where k is number of unique characters in required string
// Approach: Sliding window with character frequency tracking