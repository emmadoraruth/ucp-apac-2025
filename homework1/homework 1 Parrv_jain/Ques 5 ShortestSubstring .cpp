#include <iostream>
#include <string>
#include <map>
#include <climits>
using namespace std;


int ShortestSubstring(string s, string sub) {
    map<int, int> mp;
    for (int i = 0; i < sub.length(); i++) {
        mp[sub[i]]++;
    }
    int right = 0, left = 0, flag = 0, min_len = INT_MAX;
    while (right < s.length()) {
        if (mp.find(s[right]) != mp.end()) {
            mp[s[right]]--;
            if (mp[s[right]] == 0) flag++;
        }
        if (flag == mp.size()) {
            min_len = min(min_len, right - left + 1);
            while (left < right) {
                if (mp.find(s[left]) != mp.end()) {
                    mp[s[left]]++;
                    if (mp[s[left]] > 0) {
                        flag--;
                        break;
                    }
                }
                left++;
            }
        }
        right++;
    }
    return min_len == INT_MAX ? 0 : min_len;
}