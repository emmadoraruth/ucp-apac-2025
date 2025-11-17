#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//tc=O(n)
//sc=O(1)   
// Approach: Count character frequencies and track mismatches to determine if two strings can be made anagrams with k changes.
// TIMETAKEN:30MINS

bool KAnagrams(string s, string t, int k)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> mp;

    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {

        if (mp.find(t[i]) == mp.end())
        {
            k--;
            if (k == -1)
                return false;
        }

        else if (mp.find(t[i]) != mp.end())
        {
            mp[t[i]]--;
        }
    }
    return true;
}