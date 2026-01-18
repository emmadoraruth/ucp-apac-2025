#include <bits/stdc++.h>
using namespace std;

//It took me around 30-35 min to complete 
//I used two pointer, window (variable sliding) along with hashmaps for freq
//Time -> O(n+m) (lengths of s1 and s2) and space -> worst case -> O(26+26) ->for freq maps for s1 and s2

int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline (cin,s2);

    int n = s1.size();
    int m = s2.size();

    unordered_map <char,int> map1; 
    unordered_map <char,int> map2;

    for(int i = 0; i<m; i++)
    {
        map1[s2[i]]++;
    }

    int f = map1.size();

    int count = 0;
    int start = -1;
    int len = n+1;
    int y = 0;

    for(int i = 0; i<n; i++)
    {
        char x = s1[i];
        map2[x]++;
        if(map2[x] <= map1[x])
        {
            if(map1.find(x) != map1.end())
            {
                count++;
            }
        }

        while(count == m)
        {
            if(i-y+1<len)
            {
                len = i-y+1;
                start = y;
            }

            char z = s1[y];
            map2[z]--;
            if(map2[z] < map1[z])
            {
                if(map1.find(z) != map1.end())
                {
                    count--;
                }
            }
            y++;
        }
    }
     if(start == -1)
        {
            cout << 0;
        }else{
            cout << len ;
    }

    return 0;

}
