#include <bits/stdc++.h>
using namespace std;

// completed in around 20 min

int main()
{
    int m;
    cin >> m;
    vector <int> arr(m);

    for(int i = 0; i<m ; i++)
    {
        cin>> arr[i];
    }

    unordered_map <int,int> frequency;

    for(int i =0; i<m ; i++)
    {
        frequency[arr[i]]++;
    }

    int temp = 0;
    int temp2 = 0;

    for(int i = 0; i<m; i++)
    {
        if(frequency[arr[i]] == 1)
        {
            temp = temp + arr[i];

           
        }
        if(frequency[arr[i]]>1)
        {
            temp2 = temp2 + arr[i];
            frequency[arr[i]] = 0;
        }

        
    }

    cout << temp+temp2 << endl;
    return 0;
}