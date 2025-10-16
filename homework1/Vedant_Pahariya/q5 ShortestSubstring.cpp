// ***** Good Question *****

// Problem Statement
/* Given a string and a second string representing required characters, return the length of the shortest substring containing all the required characters.
*/
// Technique: Sliding Window
// Time Complexity: O(n + m), n and m are the lengths of the two strings
// Space Complexity: O(m), m is the length of the second string

// Input Strings: "abracadabra", "abc"
// Output: 4
// (Shortest Substring: "brac")

#include <bits/stdc++.h>
using namespace std;

int shortest(string str1, string str2){
    unordered_map<char, int> char_count;
    for(char c : str2){
        char_count[c]++;
    }

    int required = char_count.size();
    int formed = 0;
    unordered_map<char, int> window_counts;

    int l = 0, r = 0;
    int min_len = INT_MAX;
    int min_left = 0;

    while(r < str1.size()){
        char c = str1[r];
        window_counts[c]++;

        if(char_count.find(c) != char_count.end() && window_counts[c] == char_count[c]){
            formed++;
        }

        while(l <= r && formed == required){
            c = str1[l];

            if(r - l + 1 < min_len){
                min_len = r - l + 1;
                min_left = l;
            }

            window_counts[c]--;
            if(char_count.find(c) != char_count.end() && window_counts[c] < char_count[c]){
                formed--;
            }
            l++;
        }
        r++;
    }

    return min_len == INT_MAX ? 0 : min_len;
}

int main(){
    string str1 = "abracadabra";
    string str2 = "abc";
    cout << shortest(str1, str2) << "\n";

    str1 = "zxycbaabcdwxyzzxwdcbxyzabccbazyx";
    str2 = "zzyzx";
    cout << shortest(str1, str2) << "\n";

    str1 = "dog";
    str2 = "god";
    cout << shortest(str1, str2) << "\n";
}