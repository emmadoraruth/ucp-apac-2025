#include <bits/stdc++.h>
using namespace std;

//it took me 15 min
// I applied a forward pointer, which moves forward until given condition was broken
//Time - O(n), space -> O(n) (for array)
int main()
{
    int n;
    cin >> n;
    vector <int> arr(n-1);
    for (int i = 0; i<n-1; i++)
    {
        cin >>arr[i];
    }

    int i = 0;
    int j;

    while (i<n-1)
    {
        if(arr[i] == i+1)
        {
            i++;
        }else 
        {
            break;
        }
    }

    j = i+1;
    cout << j;

    

}