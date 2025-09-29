// Given a sorted array of non-negative integers, modify the array by removing duplicates
// so each element only appears once. If arrays are static (aka, not dynamic/resizable) in your
// language of choice, the remaining elements should appear in the left-hand side of the array
// and the extra space in the right-hand side should be padded with -1s.

// Examples:
// Input Array: [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
// Modified Array: [1, 2, 3, 4]
// or [1, 2, 3, 4, -1, -1, -1, -1, -1, -1] (depending on language)

// Input Array: [0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15]
// Modified Array: [0, 1, 4, 5, 8, 9, 10, 11, 15]
// or [0, 1, 4, 5, 8, 9, 10, 11, 15, -1, -1, -1, -1, -1] (depending on language)

// Input Array: [1, 3, 4, 8, 10, 12]
// Modified Array: [1, 3, 4, 8, 10, 12]

//***************************************************** */
// time taken : 10min
// Time Complexity:O(N)
// Space Complexity:O(N)

#include <bits/stdc++.h>
using namespace std;
void deduce(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    int ind = 0;
    unordered_map<int, bool> vis;
    for (auto &i : arr)
    {
        if (vis.find(i) == vis.end())
        {
            vis[i] = true;
            ans[ind] = i;
            ind++;
        }
    }
    arr = ans;
}
int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<int> arr2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
    vector<int> arr3 = {1, 3, 4, 8, 10, 12};
    deduce(arr1);
    deduce(arr2);
    deduce(arr3);
    for (auto &i : arr1)
        cout << i << " , ";
    cout<<endl;
    for (auto &i : arr2)
        cout << i << " , ";
    cout<<endl;
    for (auto &i : arr3)
        cout << i << " , ";
    cout<<endl;
    }