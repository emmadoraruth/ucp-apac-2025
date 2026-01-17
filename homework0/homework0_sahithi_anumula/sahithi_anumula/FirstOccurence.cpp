#include <bits/stdc++.h>
using namespace std;

// completed in around 25 min

int main()
{
    string string;
    getline( cin , string);

    map <char,int> frequency;
    int m = string.length();
    for (int i = 0; i<m ; i++)
    {
        frequency[string[i]]++;
    }

   
    int j = 0;

    for ( int i = 0; i<m; i++)
    {
        if(frequency[string[i]] != 0)
        {
           cout << string[i] ;
            frequency[string[i]] = 0;
            j++;
        }
    }

    cout <<  endl;
    return 0;

}