#include <bits/stdc++.h>
using namespace std;

//it took around 20 min to complete
//I used hashing, one directional, to keep count of frequency using unordered map
//time -> O(n), space -> O(n) -> for map storage

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int,int> freq;
    for (int i =0; i<n; i++)
    {
        freq[arr[i]]++;
    }

    int j = 0;

    for(int i =0; i<n; i++)
    {
        if(freq[arr[i]] == 1)
        {
            arr[j] = arr[i];
            j++;
        }else{
            if(freq[arr[i]] != 0)
            {
                arr[j] = arr[i];
                j++;
                freq[arr[i]] = 0;
            }
        }
    }

    for(int p = j; p<n; p++)
    {
        arr[p] = -1;
    }

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}