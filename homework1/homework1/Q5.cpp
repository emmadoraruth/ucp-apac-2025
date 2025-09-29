// Question 5 : Shortest Sub String
// Time Complexity : O(n)  Space Complexity : O(n+m)  Time taken: 42 minutes 


#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

int ShortestSubstring(string s1, string s2){
    unordered_map<char, int> need;
    unordered_map<char, int> have_count;

    for(char c : s2) {
        need[c]++;
    }    

    int have = 0;
    int required_count = need.size();
    int left = 0;
    int min_length = INT_MAX;

    for(int right = 0; right < s1.size(); right++){
        char c = s1[right];
        have_count[c]++;

        if(need.count(c) && have_count[c] == need[c]){
            have++;
        }

        while(have == required_count){
            if(right - left + 1 < min_length){
                min_length = right - left + 1;
            }

            char left_char = s1[left];
            have_count[left_char]--;
            if(need.count(left_char) && have_count[left_char] < need[left_char]){
                have--;
            }
            left++;
        }
    }

    return (min_length == INT_MAX) ? -1 : min_length;
}

int main(){
    string str1 = "abracadabra";
    string req1 = "abc";
    cout << ShortestSubstring(str1, req1) << endl; 

    string str2 = "zxycbaabcdwxyzzxwdcbxyzabccbazyx";
    string req2 = "zzyzx";
    cout << ShortestSubstring(str2, req2) << endl; 

    string str3 = "dog";
    string req3 = "god";
    cout << ShortestSubstring(str3, req3) << endl; 

    return 0;
}
