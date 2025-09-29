#include <bits/stdc++.h>
using namespace std;

// It took around 25 minutes
//I used sliding window, fixed one
// time c-> O(n), space is constant O(n) for creation of array

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int window = 0;
    for(int i = 0; i<k; i++)
    {
        window = arr[i] + window;
    }

    int sum = window;

    for(int i = k; i<n; i++ )
    {
        window = arr[i] + window - arr[i-k];
        sum = max(sum,window);
    }

    double p = (double)sum/k;
    cout << p;

    

    return 0;

    
}