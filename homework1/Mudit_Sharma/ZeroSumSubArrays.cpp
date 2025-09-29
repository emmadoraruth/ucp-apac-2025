// Given an array of integers, count the number of subarrays that sum to zero.

// Examples:
// Input Array: [4, 5, 2, -1, -3, -3, 4, 6, -7]
// Output: 2
// (Subarrays: [5, 2, -1, -3, -3], [-3, 4, 6, -7])

// Input Array: [1, 8, 7, 3, 11, 9]
// Output: 0

// Input Array: [8, -5, 0, -2, 3, -4]
// Output: 2
// (Subarrays: [0], [8, -5, 0, -2, 3, -4])

//************************************************** */


// Time taken to solve the Problem:25 minutes
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int zerosumsubarrays(vector<int> &arr)
{
    int n = arr.size();
    vector<int> psum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        psum[i] = arr[i - 1] + psum[i - 1];
    }
    int zcount = 0;
    for (int i = 0; i < n; i++)
    {
        int presum = psum[i];
        for (int j = i + 1; j <= n; j++)
        {
            if (psum[j] - presum == 0)
            {
                zcount++;
            }
        }
    }
    return zcount;
}

//********************************* */

// time taken:20mins
// Time Complexity: O(n)
// Space Complexity: O(N)
int zsumbyhashmap(vector<int> &arr)
{
    unordered_map<int, int> psumcnt;
    psumcnt[0] = 1;
    int sum = 0, zsum = 0;

    for (int x : arr)
    {
        sum += x;
        if (psumcnt.find(sum) != psumcnt.end())
        {
            zsum += psumcnt[sum];
        }
        psumcnt[sum]++;
    }
    return zsum;
}

int main()
{
    vector<int> arr1 = {4, 5, 2, -1, -3, -3, 4, 6, -7};
    vector<int> arr2 = {1, 8, 7, 3, 11, 9};
    vector<int> arr3 = {8, -5, 0, -2, 3, -4};
    cout << "Answer By Brute Force Approach" << endl;
    int ans1 = zerosumsubarrays(arr1);
    int ans2 = zerosumsubarrays(arr2);
    int ans3 = zerosumsubarrays(arr3);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    cout << "Answer by Efficent Approach" << endl;
    int a1 = zsumbyhashmap(arr1);
    int a2 = zsumbyhashmap(arr2);
    int a3 = zsumbyhashmap(arr3);
    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
}