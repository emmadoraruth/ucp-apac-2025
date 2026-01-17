#include <bits/stdc++.h>
using namespace std;
// Completed in  around 20 minutes 
//I used hashing - one directional, for freq count and to calculate needed changes
//Time complexity -> O(n), space -> freq map used, worst case O(26+26)

int main()
{
    string s1;
    string s2;
    int k;

    getline (cin,s1);
    getline (cin,s2);
    cin >> k;

    unordered_map<char,int> freq;

    int n = s1.size();
    int m = s2.size();

    for (int i =0; i<n; i++)
    {
        freq[s1[i]]++;
    }

    int change = 0;

    for (int i =0; i<m; i++)
    {
        if(freq[s2[i]]>0)
        {
            freq[s2[i]]--;
        }else{
            change++;
        }
    }

    if(change <= k && m == n)
    {
        cout << "True";
    }else
    {
        cout << "False";
    }

    return 0;
}