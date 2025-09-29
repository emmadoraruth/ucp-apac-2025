#include <bits/stdc++.h>
using namespace std;

//it took me around 25-30 min to complete
// i used one direcional running computation with hashmap to keep freq count of Zerosums
//time -> O(n) , space -> O(n) (for freq map)

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i<n; i++)
    {
        cin >>arr[i];
    }

    unordered_map<int,int> freq;
    int sum = 0;
    int count = 0;
    
    for(int i =0; i<n; i++)
    {
        sum = sum + arr[i];
    if(sum == 0)
    {
        count++;
    }
    if(freq.find(sum)  != freq.end())
    {
        count = count + freq[sum];
    }

    freq[sum]++;
    }

    cout << count;
    return 0;
}
