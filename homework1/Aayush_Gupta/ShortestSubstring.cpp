#include<bits/stdc++.h>
using namespace std;
//TC:O(n)
//SC:O(k) where k is unique characters in required 

int shortestSubstring(string s, string required) {
    if (s.empty() || required.empty()) {
        return 0;
    }
    

    unordered_map<char, int> requiredCount;
    for (char c : required) {
        requiredCount[c]++;
    }
    
   
    int requiredChars = requiredCount.size();
    int matchedChars = 0;
    

    int left = 0;
    int minLength = INT_MAX;
    unordered_map<char, int> windowCount;
    
    for (int right = 0; right < s.length(); right++) {

        char currentChar = s[right];
        windowCount[currentChar]++;
        

        if (requiredCount.find(currentChar) != requiredCount.end() && 
            windowCount[currentChar] == requiredCount[currentChar]) {
            matchedChars++;
        }
        

        while (matchedChars == requiredChars && left <= right) {
            
            int currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
            }
            
           
            char leftChar = s[left];
            windowCount[leftChar]--;
            
           
            if (requiredCount.find(leftChar) != requiredCount.end() && 
                windowCount[leftChar] < requiredCount[leftChar]) {
                matchedChars--;
            }
            
            left++;
        }
    }
    
    return minLength != INT_MAX ? minLength : 0;
}





int main(){
    string s, required;
    cin >> s >> required;
    
    int result = shortestSubstring(s, required);
    if (result == 0)
        cout << "No substring contains all required characters";
    else
        cout << result;
    
    return 0;


    

}