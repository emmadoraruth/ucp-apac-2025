#include <bits/stdc++.h>
using namespace std;

// it took around  20 min to complete
//I used One-directional running computation/total 
// I went throgh the string in one go keeping an index
// Time -> O(S1+s2) (lemgths of s1 and s2), space -> O(S1+S2) ->two new strings are created after removing #

string remove(string s)
{
    string final(s.size(), ' ');
    int j = 0;
    for(int i =0; i<s.size(); i++)
    {
        if(s[i] == '#')
        {
            if(j>0)
            {
                j--;
            }
        }else{
            final[j++] = s[i];
        }
    }

    return final.substr(0, j);
}

int main()
{
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);

    string s_change1 = remove(s1);
    string s_change2 = remove(s2);

    if(s_change1 == s_change2)
    {
        cout << "True";
    }else{
        cout << "False";
    }

    return 0;

    
}